/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tasks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfanelli <mfanelli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/25 10:09:19 by mfanelli          #+#    #+#             */
/*   Updated: 2025/02/25 11:40:14 by mfanelli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	check_if_dead(data_t *th)
{
	long long       diff;

	diff = (get_curr_time()) - (((*th).last_eat.tv_sec * 1000) + ((*th).last_eat.tv_usec / 1000));
	if (diff >= (*th).time_to_die)
	{	
		ft_scriba("%lldms %d is dead\n", th);
		(*th).dead = 1;
		return (0);
	}
	return (1);
}

int	is_someone_dead(data_t *th)
{
	int	i;

	i = -1;
	while(++i < th[0].num_philos)
		if (th[i].dead == 1)
			return (0);
	return (1);
}

int	go_thinking(data_t *th)
{
	ft_scriba("%lldms %d is thinking\n", th);
	while ((*th).my_f != 0 || (*th).left_philo->my_f != 0)
		if (check_if_dead(th) == 0)
			return (0);
	return (1);
}

void	go_sleeping(data_t *th)
{
	ft_scriba("%lldms %d is sleeping\n", th);
	usleep((*th).time_to_sleep * 1000);
	if (check_if_dead(th) == 0)
		return ;
	ft_scriba("%lldms %d has finished sleeping\n", th);
	return ;
}

void	*go_eat(void *th)
{
	data_t	*cp;

	cp = (data_t *)th;
    gettimeofday(&(*cp).start, NULL);
	gettimeofday(&(*cp).last_eat, NULL);
	while (((*cp).max_dinners != 0 && (*cp).dinners < (*cp).max_dinners && \
	is_someone_dead((*cp).head_th) != 0) || ((*cp).max_dinners == 0 && is_someone_dead((*cp).head_th) != 0))
	{
		if ((*cp).my_f == 0 && (*cp).left_philo->my_f == 0)
		{
			pthread_mutex_lock(&((*cp).left_philo->my_fork));
			pthread_mutex_lock(&(*cp).my_fork);
			gettimeofday(&(*cp).last_eat, NULL);
			(*cp).my_f = 1;
			(*cp).left_philo->my_f = 1;
			ft_scriba("%lldms %d is eating\n", cp);
			usleep((*cp).time_to_eat * 1000);
			ft_scriba("%lldms %d has finished eating\n", cp);
			(*cp).my_f = 0;
			(*cp).left_philo->my_f = 0;
			++(*cp).dinners;
			pthread_mutex_unlock(&((*cp).left_philo->my_fork));
			pthread_mutex_unlock(&(*cp).my_fork);
			if (((*cp).max_dinners != 0 && (*cp).dinners < (*cp).max_dinners && is_someone_dead((*cp).head_th) != 0) || ((*cp).max_dinners == 0 && is_someone_dead((*cp).head_th) != 0))
				go_sleeping(cp);
		}
		if (((*cp).max_dinners != 0 && (*cp).dinners < (*cp).max_dinners && is_someone_dead((*cp).head_th) != 0) || (*cp).max_dinners == 0 && is_someone_dead((*cp).head_th) != 0)
			if (go_thinking(cp) == 0)
				return (0);
	}
	return (0);
}
