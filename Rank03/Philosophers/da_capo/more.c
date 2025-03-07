/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   more.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfanelli <mfanelli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/06 10:48:54 by mfanelli          #+#    #+#             */
/*   Updated: 2025/03/07 14:12:17 by mfanelli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	locks(t_philo *th)
{
	if ((*th).whoami == 1)
	{
		pthread_mutex_lock(&(*th).my_fork);
		ft_scriba("%lld %d has taken a fork\n", th);
		pthread_mutex_lock(&((*th).left_philo->my_fork));
		ft_scriba("%lld %d has taken a fork\n", th);
	}
	else
	{
		pthread_mutex_lock(&((*th).left_philo->my_fork));
		ft_scriba("%lld %d has taken a fork\n", th);
		pthread_mutex_lock(&(*th).my_fork);
		ft_scriba("%lld %d has taken a fork\n", th);
	}
}

void	unlocks(t_philo *th)
{
		pthread_mutex_unlock(&(*th).my_fork);
		pthread_mutex_unlock(&((*th).left_philo->my_fork));
}

long long	get_curr_time(void)
{
	long long		tmp;
	struct timeval	tv;

	gettimeofday(&tv, NULL);
	tmp = ((tv.tv_sec * 1000) + (tv.tv_usec / 1000));
	return (tmp);
}

long long	get_start_time(t_philo *th)
{
	long long		tmp;

	tmp = (((*th).start.tv_sec * 1000) + ((*th).start.tv_usec / 1000));
	return (tmp);
}

void	ft_scriba(char	*str, t_philo *th)
{
	if (im_writing((*th).head_th) != 0)
	{
		printf(str, (get_curr_time() - get_start_time(th)), (*th).whoami);
		i_finished((*th).head_th);
	}
}

void	manual_sleep(t_philo *th, long long time)
{
	long long	i;

	i = get_curr_time();
	while (is_someone_dead((*th).head_th) != 0)
	{
		if ((get_curr_time() - i) >= time)
			break ;
		usleep(50);
	}
}
