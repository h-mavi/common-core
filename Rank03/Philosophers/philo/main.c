/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfanelli <mfanelli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/06 10:26:07 by mfanelli          #+#    #+#             */
/*   Updated: 2025/03/13 11:18:16 by mfanelli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

//parsing degli errori
int	check_error(int argc, char *argv[])
{
	pthread_t	phi;

	if (argc != 5 && argc != 6)
		return (printf("Too many or too few arguments\n"));
	if (is_str_digit(argv[1]) != 0 || is_str_digit(argv[2]) != 0 || \
	is_str_digit(argv[2]) != 0 || is_str_digit(argv[3]) != 0 || \
	is_str_digit(argv[4]) != 0 || (argv[5] != 0 && is_str_digit(argv[5]) != 0))
		return (printf("Not valid arguments\n"));
	if (ft_atoi(argv[2]) < 1 || ft_atoi(argv[3]) < 1 || ft_atoi(argv[4]) < 1)
		return (printf("Times too short\n"));
	if (argc == 6 && ft_atoi(argv[5]) < 1)
		return (printf("Philos cant't eat 0 times\n"));
	if (ft_atoi(argv[1]) < 2)
	{
		pthread_create(&phi, NULL, &lonely, (void *)argv);
		pthread_join(phi, NULL);
		return (1);
	}
	return (0);
}

//imposta le informazioni nella struttura di ogni filosofo
void	set_data(t_philo *th, char *argv[], int argc, t_gen *gen)
{
	int				i;
	struct timeval	tmp;

	i = -1;
	while (++i < ft_atoi(argv[1]))
	{
		pthread_mutex_init(&th[i].my_fork, NULL);
		pthread_mutex_init(&th[i].timing, NULL);
		th[i].whoami = i + 1;
		th[i].dinners = 0;
		th[i].dead = 0;
		th[i].head_th = th;
		th[i].gen = gen;
		gettimeofday(&tmp, NULL);
		th[i].start = (tmp.tv_sec * 1000) + (tmp.tv_usec / 1000);
		if (i != 0)
			th[i].left_fork = &th[i - 1].my_fork;
	}
	th[0].left_fork = &th[i - 1].my_fork;
}

//imposta le informazioni della struttura gen
void	set_gen(char *argv[], int argc, t_gen *gen)
{
	pthread_mutex_init(&(gen->printing), NULL);
	pthread_mutex_init(&(gen->murtem), NULL);
	(*gen).num_philos = ft_atoi(argv[1]);
	(*gen).time_to_die = ft_atoi(argv[2]);
	(*gen).time_to_eat = ft_atoi(argv[3]);
	(*gen).time_to_sleep = ft_atoi(argv[4]);
	if (argc == 6)
		(*gen).max_dinners = ft_atoi(argv[5]);
	else
		(*gen).max_dinners = 0;
}

//libera la memora allocata e i distrugge i mutex
void	free_all(t_philo *th)
{
	int	i;
	int	max;

	max = th[0].gen->num_philos;
	i = 0;
	pthread_mutex_destroy(&(th[0].gen->printing));
	pthread_mutex_destroy(&(th[0].gen->murtem));
	while (i < max)
	{
		pthread_mutex_destroy(&th[i].my_fork);
		pthread_mutex_destroy(&th[i].timing);
		i++;
	}
	free(th);
}

int	main(int argc, char *argv[])
{
	int			i;
	t_gen		gen;
	t_philo		*th;
	pthread_t	thanos;

	if (check_error(argc, argv) != 0)
		return (0);
	th = (t_philo *)ft_calloc(sizeof(t_philo), ft_atoi(argv[1]));
	set_gen(argv, argc, &gen);
	set_data(th, argv, argc, &gen);
	i = -1;
	while (++i < th[0].gen->num_philos)
	{
		if (th[i].whoami % 2 == 0)
			usleep(500);
		pthread_create(&th[i].filo, NULL, &routine, (void *)&th[i]);
	}
	pthread_create(&thanos, NULL, &check_death, (void *)&th);
	i = -1;
	while (++i < th[0].gen->num_philos)
		pthread_join(th[i].filo, NULL);
	pthread_join(thanos, NULL);
	free_all(th);
	return (0);
}
