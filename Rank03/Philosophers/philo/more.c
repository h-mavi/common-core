/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   more.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfanelli <mfanelli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/06 10:48:54 by mfanelli          #+#    #+#             */
/*   Updated: 2025/03/13 10:00:20 by mfanelli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

//blocca tutti i mutex nel loro ordine
void	locks(t_philo *th)
{
	if ((*th).whoami == 1)
	{
		pthread_mutex_lock(&(*th).my_fork);
		ft_scriba("%lld %d has taken a fork\n", th);
		pthread_mutex_lock(&(*(*th).left_fork));
		ft_scriba("%lld %d has taken a fork\n", th);
	}
	else
	{
		pthread_mutex_lock(&(*(*th).left_fork));
		ft_scriba("%lld %d has taken a fork\n", th);
		pthread_mutex_lock(&(*th).my_fork);
		ft_scriba("%lld %d has taken a fork\n", th);
	}
}

//sblocca tutti i mutex nel loro ordine
void	unlocks(t_philo *th)
{
	if ((*th).whoami == 1)
	{
		pthread_mutex_unlock(&(*(*th).left_fork));
		pthread_mutex_unlock(&(*th).my_fork);
	}
	else
	{
		pthread_mutex_unlock(&(*th).my_fork);
		pthread_mutex_unlock(&(*(*th).left_fork));
	}
}

//ritorna il tempo corrente
long long	get_curr_time(void)
{
	long long		tmp;
	struct timeval	tv;

	gettimeofday(&tv, NULL);
	tmp = ((tv.tv_sec * 1000) + (tv.tv_usec / 1000));
	return (tmp);
}

//scrive sul terminale bloccando il mutex della stampa
void	ft_scriba(char	*str, t_philo *th)
{
	pthread_mutex_lock(&(th->gen->printing));
	if (is_someone_dead((*th).head_th) != 0)
		printf(str, (get_curr_time() - (*th).start), (*th).whoami);
	pthread_mutex_unlock(&(th->gen->printing));
}

//sleep migliorato
void	manual_sleep(t_philo *th, long long time)
{
	long long	i;

	i = get_curr_time();
	while (1)
	{
		if ((get_curr_time() - i) >= time)
			break ;
		usleep(1);
	}
}
