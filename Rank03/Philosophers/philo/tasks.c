/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tasks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfanelli <mfanelli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/06 10:29:08 by mfanelli          #+#    #+#             */
/*   Updated: 2025/03/13 09:59:09 by mfanelli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

//funzione per gestire il caso di un filosofo
void	*lonely(void *args)
{
	char	**argv;

	argv = (char **)args;
	printf("%d %d has taken a fork\n", 0, 1);
	usleep(ft_atoi(argv[2]) * 1000);
	printf("%d %d is dead\n", ft_atoi(argv[2]), 1);
	return (NULL);
}

//funzione unicamente creata per contenere un if enorme
int	if_check(t_philo *th)
{
	if (((*th).gen->max_dinners != 0 && (*th).dinners < (*th).gen->max_dinners && \
	is_someone_dead((*th).head_th) != 0) || ((*th).gen->max_dinners == 0 && \
	is_someone_dead((*th).head_th) != 0))
		return (1);
	return (0);
}

//permette di dormire
void	go_sleeping(t_philo *th)
{
	ft_scriba("%lld %d is sleeping\n", th);
	manual_sleep(th, (*th).gen->time_to_sleep);
	return ;
}

//permette di mangiare
void	go_eat(t_philo *th)
{
	locks(th);
	ft_scriba("%lld %d is eating\n", th);
	pthread_mutex_lock(&(*th).timing);
	gettimeofday(&(*th).last_eat, NULL);
	++(*th).dinners;
	pthread_mutex_unlock(&(*th).timing);
	manual_sleep(th, (*th).gen->time_to_eat);
	unlocks(th);
}

//inizio della routine dove viene settato lo start e dove avviene il loop di mangiare-dormire-pensare
void	*routine(void *args)
{
	t_philo	*th;

	th = (t_philo *)args;
	pthread_mutex_lock(&(*th).timing);
	gettimeofday(&(*th).last_eat, NULL);
	pthread_mutex_unlock(&(*th).timing);
	while (if_check(th))
	{
		if (if_check(th))
		{
			go_eat(th);
			go_sleeping(th);
		}
		if (if_check(th))
		{
			ft_scriba("%lld %d is thinking\n", th);
			usleep(1000); //aggiunto un'attesa obbligatoria per mantenere la precedenza
		}
	}
	return (0);
}
