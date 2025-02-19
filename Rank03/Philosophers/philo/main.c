/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfanelli <mfanelli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/18 13:59:38 by mfanelli          #+#    #+#             */
/*   Updated: 2025/02/19 12:08:58 by mfanelli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	set_values(char *argv[], data_t	*th)
{
	int	i;

	i = -1;
	while (++i < ft_atoi(argv[1]))
	{
		th[i].num_philo = ft_atoi(argv[1]);
		th[i].whoiam = i;
		th[i].myf_occ = 0;
		th[i].yourf_occ = 0;
		th[i].is_spleeping = 0;
		th[i].is_dead = 0;
		th[i].time_to_die = ft_atoi(argv[2]);
		th[i].time_to_eat = ft_atoi(argv[3]);
		th[i].time_to_sleep = ft_atoi(argv[4]);
		pthread_mutex_init(&th[i].mutex_myf, NULL);
		if (i != 0)
			th[i].mutex_yourf = th[i - 1].mutex_myf;
		th[i].head_th = th;
	}
	th[0].mutex_yourf = th[i].mutex_myf;
}

int	check_eating(data_t th)
{
	if (th.myf_occ == 1 || th.yourf_occ == 1)
			return (0);
	return (1);
}

void	go_sleeping(data_t th)
{
	th.is_spleeping = 1;
	printf("Philo number %d goes to mimir\n", th.whoiam);
	usleep(th.time_to_sleep);
	th.is_spleeping = 1;
	printf("Philo number %d wakes up!\n", th.whoiam);
}

void go_thinking(data_t th)
{
	struct timeval	*time;
	struct timeval	*start;
	int				thinking;

	gettimeofday(start, NULL);
	thinking = 0;
	while (thinking < th.time_to_die && check_eating(th) == 0)
	{
		usleep(1000000);
		printf("Philo number %d needs to think for a bit...\n", th.whoiam);
		gettimeofday(time, NULL);
		thinking = time - start;
		if (thinking == th.time_to_die)
		{
			th.is_dead = 1;
			exit (0);
		}
		if (check_eating(th) == 1)
			return ;
	}
	return ;
}

void	*fun_eat(void *th)
{
	data_t cp;

	cp = *(data_t *)th;
	if(check_eating(cp) != 0)
	{
		cp.myf_occ = 1;
		pthread_mutex_lock(&cp.mutex_myf);
		cp.yourf_occ = 1;
		pthread_mutex_lock(&cp.mutex_yourf);
		printf("Philo number %d is eating\n", cp.whoiam);
		usleep(cp.time_to_eat);
		cp.myf_occ = 0;
		pthread_mutex_unlock(&cp.mutex_myf);
		cp.yourf_occ = 0;
		pthread_mutex_unlock(&cp.mutex_yourf);
		printf("Philo number %d is full\n", cp.whoiam);
		go_sleeping(cp);
	}
	else
		go_thinking(cp);
	fun_eat(th);
	exit (0);
}

void	free_all(data_t *th)
{
	int	i;

	i = -1;
	while (++i < th[0].num_philo)
		pthread_mutex_destroy(&th[i].mutex_myf);
	free(th);
}


int	main(int argc, char *argv[])
{
	int		i;
	data_t	*th;
	
	if (argc != 5 && argc != 6)
		return (0);
	if (ft_atoi(argv[1]) == 1 || ft_atoi(argv[2]) < 1 || ft_atoi(argv[3]) < 1 || ft_atoi(argv[4]) < 1)
		return (0);
	th = (data_t *)malloc(ft_atoi(argv[1]) * sizeof(data_t));
	set_values(argv, th);
	i = -1;
	while (++i < ft_atoi(argv[1]))
		if (pthread_create(&th[i].philo, NULL, &fun_eat, &th[i]) != 0)
			return (0);
	i = 0;
	while (i < th[i].num_philo)
	{
		if (pthread_join(th[i].philo, NULL) == 0)
		{
			free_all(th);
			return (printf("LA SAI LA NOVITA'?? E' MORTO\n"));
		}
		i++;
		if (i == th[i].num_philo)
			i = 0;
	}
	return (0);
}
