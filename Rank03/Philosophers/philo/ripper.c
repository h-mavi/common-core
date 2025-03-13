/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ripper.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfanelli <mfanelli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/06 10:37:22 by mfanelli          #+#    #+#             */
/*   Updated: 2025/03/13 09:40:58 by mfanelli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

//routine del thread che controlla la morte, in un ciclo while controlla se
//qualcuno e' morto
void	*check_death(void   *args)
{
	t_philo	**head;
	long long diff;
	int			i;
	int			flag;

	flag = 0;
	head = (t_philo **)args;
	while (1)
	{
		i = -1;
		while (++i < (*head)[0].gen->num_philos)
		{
			pthread_mutex_lock(&(*head)[i].timing);
			if ((*head)[i].start == 0)
			{
				pthread_mutex_unlock(&(*head)[i].timing);
				continue ;
			}
			diff = (get_curr_time()) - (((*head)[i].last_eat.tv_sec * 1000) + \
			((*head)[i].last_eat.tv_usec / 1000));
			if ((diff >= (*head)[i].gen->time_to_die && (*head)[i].dinners < (*head)[i].gen->max_dinners) || \
			(diff >= (*head)[i].gen->time_to_die && (*head)[i].gen->max_dinners == 0))
			{
				pthread_mutex_unlock(&(*head)[i].timing);
				ft_scriba("%lld %d died\n", &(*head)[i]);
				pthread_mutex_lock(&((*head)[i].gen->murtem));
				(*head)[i].dead = 1;
				pthread_mutex_unlock(&(*head)[i].gen->murtem);
				break ;
			}
			if ((*head)[i].dinners == (*head)[i].gen->max_dinners && (*head)[i].gen->max_dinners != 0)
				flag++;
			pthread_mutex_unlock(&(*head)[i].timing);
		}
		if (i != (*head)[0].gen->num_philos || ((flag >= (*head)[0].gen->num_philos) && (*head)[0].gen->max_dinners != 0))
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
