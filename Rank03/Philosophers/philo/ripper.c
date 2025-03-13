/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ripper.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfanelli <mfanelli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/06 10:37:22 by mfanelli          #+#    #+#             */
/*   Updated: 2025/03/13 11:14:16 by mfanelli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	do_it(t_philo *th)
{
	ft_scriba("%lld %d died\n", &(*th));
	pthread_mutex_lock(&((*th).gen->murtem));
	(*th).dead = 1;
	pthread_mutex_unlock(&(*th).gen->murtem);
}

int	control(t_philo *th)
{
	int	diff;

	pthread_mutex_lock(&(*th).timing);
	diff = (get_curr_time()) - (((*th).last_eat.tv_sec * 1000) + \
	((*th).last_eat.tv_usec / 1000));
	if ((diff >= (*th).gen->time_to_die && \
	(*th).dinners < (*th).gen->max_dinners) || \
	(diff >= (*th).gen->time_to_die && (*th).gen->max_dinners == 0))
	{
		pthread_mutex_unlock(&(*th).timing);
		return (1);
	}
	pthread_mutex_unlock(&(*th).timing);
	return (0);
}

void	death_core(t_philo **th, int *flag, int *i)
{
	while (++*i < (*th)[0].gen->num_philos)
	{
		if ((*th)[*i].start == 0)
			continue ;
		if (control(&(*th)[*i]))
		{
			do_it(&(*th)[*i]);
			break ;
		}
		pthread_mutex_lock(&(*th)[*i].timing);
		if ((*th)[*i].dinners == (*th)[*i].gen->max_dinners && \
		(*th)[*i].gen->max_dinners != 0)
			*flag += 1;
		pthread_mutex_unlock(&(*th)[*i].timing);
	}
}

//routine del thread che controlla la morte, in un ciclo while controlla se
//qualcuno e' morto
void	*check_death(void *args)
{
	t_philo		**head;
	int			i;
	int			flag;

	flag = 0;
	head = (t_philo **)args;
	while (1)
	{
		i = -1;
		death_core(head, &flag, &i);
		if (i != (*head)[0].gen->num_philos || \
		((flag >= (*head)[0].gen->num_philos) && \
		(*head)[0].gen->max_dinners != 0))
			break ;
		usleep(5);
	}
	return (0);
}

//controllo se qualcuno e' morto
int	is_someone_dead(t_philo *th)
{
	int	*i;

	i = (int *)malloc(sizeof(int));
	*i = -1;
	while (++*i < th[0].gen->num_philos)
	{
		pthread_mutex_lock(&(*th).gen->murtem);
		if (th[*i].dead == 1)
		{
			pthread_mutex_unlock(&(*th).gen->murtem);
			free(i);
			return (0);
		}
		pthread_mutex_unlock(&(*th).gen->murtem);
	}
	free(i);
	return (1);
}
