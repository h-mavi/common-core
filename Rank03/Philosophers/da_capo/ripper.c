/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ripper.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfanelli <mfanelli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/06 10:37:22 by mfanelli          #+#    #+#             */
/*   Updated: 2025/03/07 14:10:20 by mfanelli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

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
		usleep(500);
		while (++i < (*head)[0].num_philos)
		{
			diff = (get_curr_time()) - (((*head)[i].last_eat.tv_sec * 1000) + \
			((*head)[i].last_eat.tv_usec / 1000));
			if ((diff >= (*head)[i].time_to_die && (*head)[i].dinners < (*head)[i].max_dinners) || \
			(diff >= (*head)[i].time_to_die && (*head)[i].max_dinners == 0))
			{
				ft_scriba("%lld %d died\n", head[i]);
				pthread_mutex_lock(&(*head)[i].murtem);
				(*head)[i].dead = 1;
				pthread_mutex_unlock(&(*head)[i].murtem);
				break ;
			}
			if ((*head)[i].dinners == (*head)[i].max_dinners && (*head)[i].max_dinners != 0)
				flag++;
		}
		if (i != (*head)[0].num_philos || (flag == (*head)[0].num_philos && (*head)[0].max_dinners != 0))
			break ;
	}
	return (0);
}

int	is_someone_dead(t_philo *th)
{
	int	*i;

	i = (int *)malloc(sizeof(int));
	*i = -1;
	while (++*i < th[0].num_philos)
	{
		pthread_mutex_lock(&th[*i].murtem);
		if (th[*i].dead == 1)
		{
			pthread_mutex_unlock(&th[*i].murtem);
			free(i);
			return (0);
		}
		pthread_mutex_unlock(&th[*i].murtem);
	}
	free(i);
	return (1);
}
