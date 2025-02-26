/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   more.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfanelli <mfanelli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/25 11:28:43 by mfanelli          #+#    #+#             */
/*   Updated: 2025/02/26 14:47:46 by mfanelli         ###   ########.fr       */
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

void	locks(t_data *th)
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

void	unlocks(t_data *th)
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

void	gnam(t_data *th)
{
	locks(th);
	(*th).my_f = 1;
	(*th).left_philo->my_f = 1;
	unlocks(th);
	ft_scriba("%lld %d has taken a fork\n", th);
	ft_scriba("%lld %d has taken a fork\n", th);
	gettimeofday(&(*th).last_eat, NULL);
	ft_scriba("%lld %d is eating\n", th);
	usleep((*th).time_to_eat * 1000);
	++(*th).dinners;
	locks(th);
	(*th).my_f = 0;
	(*th).left_philo->my_f = 0;
	unlocks(th);
}

