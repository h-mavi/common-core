/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tasks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfanelli <mfanelli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/25 10:09:19 by mfanelli          #+#    #+#             */
/*   Updated: 2025/02/26 16:00:40 by mfanelli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	check_if_dead(t_data *th)
{
	long long	diff;

	diff = (get_curr_time()) - (((*th).last_eat.tv_sec * 1000) + \
	((*th).last_eat.tv_usec / 1000));
	if (diff >= (*th).time_to_die)
	{
		ft_scriba("%lld %d is dead\n", th);
		pthread_mutex_lock(&(*th).mortem);
		(*th).dead = 1;
		pthread_mutex_unlock(&(*th).mortem);
		return (0);
	}
	return (1);
}

int	is_someone_dead(t_data *th)
{
	int	*i;

	i = (int *)malloc(sizeof(int));
	*i = -1;
	while (++*i < th[0].num_philos)
	{
		pthread_mutex_lock(&th[*i].mortem);
		if (th[*i].dead == 1)
		{
			pthread_mutex_unlock(&th[*i].mortem);
			free(i);
			return (0);
		}
		pthread_mutex_unlock(&th[*i].mortem);
	}
	free(i);
	return (1);
}

void	go_thinking(t_data *th)
{
	ft_scriba("%lld %d is thinking\n", th);
	while (1)
	{
		if (check_if_dead(th) == 0)
			break ;
		locks(th);
		if ((*th).my_f == 0 && (*th).left_philo->my_f == 0)
		{
			unlocks(th);
			break ;
		}
		unlocks(th);
	}
	return ;
}

void	go_sleeping(t_data *th)
{
	ft_scriba("%lld %d is sleeping\n", th);
	manual_sleep(th, (*th).time_to_sleep);
	if (check_if_dead(th) == 0)
		return ;
	return ;
}

void	*go_eat(void *th)
{
	t_data	*cp;

	cp = (t_data *)th;
	gettimeofday(&(*cp).start, NULL);
	gettimeofday(&(*cp).last_eat, NULL);
	while (mother_fucking_daaamn(cp))
	{
		locks(cp);
		if ((*cp).my_f == 0 && (*cp).left_philo->my_f == 0)
		{
			unlocks(cp);
			gnam(cp);
			if (check_if_dead(cp) == 0)
				break ;
			if (mother_fucking_daaamn(cp))
				go_sleeping(cp);
		}
		else
			unlocks(cp);
		if (mother_fucking_daaamn(cp))
			go_thinking(cp);
	}
	return (0);
}

// ft_scriba("%lld %d has finished sleeping\n", th);