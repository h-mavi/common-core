/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfanelli <mfanelli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/06 10:26:07 by mfanelli          #+#    #+#             */
/*   Updated: 2025/03/07 14:17:04 by mfanelli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	check_error(int argc, char *argv[])
{
	pthread_t	phi;

	if (argc != 5 && argc != 6)
		return (printf("Troppi o troppi pochi argomenti\n"));
	if (ft_atoi(argv[1]) < 2)
	{
		pthread_create(&phi, NULL, &lonely, (void *)argv);
		pthread_join(phi, NULL);
		return (1);
	}
	if (ft_atoi(argv[2]) < 1 || ft_atoi(argv[3]) < 1 || ft_atoi(argv[4]) < 1)
		return (printf("Tempistiche troppo basse\n"));
	if (argc == 6 && ft_atoi(argv[5]) < 1)
		return (printf("I philos non possono mangiare 0 volte\n"));
	return (0);
}

void	set_data(t_philo *th, char *argv[], int argc, int i)
{
	while (++i < ft_atoi(argv[1]))
	{
		pthread_mutex_init(&th[i].my_fork, NULL);
		pthread_mutex_init(&th[i].printing, NULL);
		pthread_mutex_init(&th[i].murtem, NULL);
		th[i].num_philos = ft_atoi(argv[1]);
		th[i].whoami = i + 1;
		th[i].time_to_die = ft_atoi(argv[2]);
		th[i].time_to_eat = ft_atoi(argv[3]);
		th[i].time_to_sleep = ft_atoi(argv[4]);
		th[i].dinners = 0;
		th[i].dead = 0;
		th[i].head_th = th;
		if (argc == 6)
			th[i].max_dinners = ft_atoi(argv[5]);
		else
			th[i].max_dinners = 0;
		if (i != 0)
			th[i].left_philo = &th[i - 1];
	}
	th[0].left_philo = &th[i - 1];
}

void	free_all(t_philo *th)
{
	int	i;
	int	max;

	max = th[0].num_philos;
	i = 0;
	while (i < max)
	{
		pthread_mutex_destroy(&th[i].my_fork);
		pthread_mutex_destroy(&th[i].printing);
		pthread_mutex_destroy(&th[i].murtem);
		i++;
	}
	free(th);
}

int	main(int argc, char *argv[])
{
	int			i;
	t_philo		*th;
	pthread_t	thanos;

	if (check_error(argc, argv) != 0)
		return (0);
	th = (t_philo *)malloc(sizeof(t_philo) * ft_atoi(argv[1]));
	set_data(th, argv, argc, -1);
	i = -1;
	while (++i < th[0].num_philos)
		if (pthread_create(&th[i].filo, NULL, &routine, (void *)&th[i]) != 0)
			return (0);
	if (pthread_create(&thanos, NULL, &check_death, (void *)&th) != 0)
		return (0);
	i = -1;
	if (pthread_join(thanos, NULL) != 0)
			return (0);
	while (++i < th[0].num_philos)
		if (pthread_join(th[i].filo, NULL) != 0)
			return (0);
	free_all(th);
	return (0);
}
