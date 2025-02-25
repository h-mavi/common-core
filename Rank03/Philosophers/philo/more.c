/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   more.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfanelli <mfanelli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/25 11:28:43 by mfanelli          #+#    #+#             */
/*   Updated: 2025/02/25 14:45:45 by mfanelli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

long long	get_curr_time(void)
{
	long long		tmp;
	struct timeval	tv;

	tmp = 0;
	gettimeofday(&tv, NULL);
	tmp = ((tv.tv_sec * 1000) + (tv.tv_usec / 1000));
	return (tmp);
}

void	locks(data_t *th)
{
	if ((*th).whoami == 1)
	{
		pthread_mutex_lock(&(*th).my_fork);
		pthread_mutex_lock(&((*th).left_philo->my_fork));
	}
	else
	{
		pthread_mutex_lock(&((*th).left_philo->my_fork));
		pthread_mutex_lock(&(*th).my_fork);
	}
}

void	unlocks(data_t *th)
{
	if ((*th).whoami == 1)
	{
		pthread_mutex_unlock(&(*th).my_fork);
		pthread_mutex_unlock(&((*th).left_philo->my_fork));
	}
	else
	{
		pthread_mutex_unlock(&((*th).left_philo->my_fork));
		pthread_mutex_unlock(&(*th).my_fork);
	}
}

void	gnam(data_t *th)
{
	locks(th);
	(*th).my_f = 1;
	(*th).left_philo->my_f = 1;
	ft_scriba("%lld %d has taken a fork\n", th);
	ft_scriba("%lld %d has taken a fork\n", th);
	gettimeofday(&(*th).last_eat, NULL);
	ft_scriba("%lld %d is eating\n", th);
	usleep((*th).time_to_eat * 1000);
	// ft_scriba("%lld %d has finished eating\n", th);
	++(*th).dinners;
	(*th).my_f = 0;
	(*th).left_philo->my_f = 0;
	unlocks(th);
}
