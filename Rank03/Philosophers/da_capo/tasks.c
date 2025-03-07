/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tasks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfanelli <mfanelli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/06 10:29:08 by mfanelli          #+#    #+#             */
/*   Updated: 2025/03/07 14:31:40 by mfanelli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	*lonely(void *args)
{
	char	**argv;

	argv = (char **)args;
	printf("%d %d has taken a fork\n", 0, 1);
	usleep(ft_atoi(argv[2]) * 1000);
	printf("%d %d is dead\n", ft_atoi(argv[2]), 1);
	return (NULL);
}

int	if_check(t_philo *th)
{
	if (((*th).max_dinners != 0 && (*th).dinners < (*th).max_dinners && \
	is_someone_dead((*th).head_th) != 0) || ((*th).max_dinners == 0 && \
	is_someone_dead((*th).head_th) != 0))
		return (1);
	return (0);
}

void	go_sleeping(t_philo *th)
{
	ft_scriba("%lld %d is sleeping\n", th);
	manual_sleep(th, (*th).time_to_sleep);
	return ;
}

void	go_eat(t_philo *th)
{
	locks(th);
	gettimeofday(&(*th).last_eat, NULL);
	ft_scriba("%lld %d is eating\n", th);
	++(*th).dinners;
	manual_sleep(th, (*th).time_to_eat);
	unlocks(th);
}

void	lag(t_philo *th)
{
	if ((*th).num_philos % 2 == 0)
	{
		if ((*th).whoami % 2 == 0)
			usleep(100);
	}
	else
		if ((*th).whoami % 2 == 0)
			usleep(100);
}

void	*routine(void *args)
{
	t_philo	*th;

	th = (t_philo *)args;
	gettimeofday(&(*th).start, NULL);
	lag(th);
	gettimeofday(&(*th).last_eat, NULL);
	while (if_check(th))
	{
		if (if_check(th))
		{
			go_eat(th);
			go_sleeping(th);
		}
		if (if_check(th))
			ft_scriba("%lld %d is thinking\n", th);
	}
	return (0);
}
