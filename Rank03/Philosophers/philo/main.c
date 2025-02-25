/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfanelli <mfanelli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/20 08:53:42 by mfanelli          #+#    #+#             */
/*   Updated: 2025/02/25 16:37:44 by mfanelli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	ft_scriba(char	*str, t_data *th)
{
	if (im_writing((*th).head_th) != 0)
	{
		printf(str, (get_curr_time() - (((*th).start.tv_sec * 1000) + \
		((*th).start.tv_usec / 1000))), (*th).whoami);
		i_finished((*th).head_th);
	}
}

int	check_error(int argc, char *argv[])
{
	if (argc != 5 && argc != 6)
		return (printf("Troppi o troppi pochi argomenti\n"));
	if (ft_atoi(argv[1]) < 2)
		return (printf("Troppi pochi philos\n"));
	if (ft_atoi(argv[2]) < 1 || ft_atoi(argv[3]) < 1 || ft_atoi(argv[4]) < 1)
		return (printf("Tempistiche troppo basse\n"));
	if (argc == 6 && ft_atoi(argv[5]) < 1)
		return (printf("I philos non possono mangiare 0 volte\n"));
	return (0);
}

void	set_data(t_data *th, char *argv[], int argc)
{
	int	i;

	i = -1;
	while (++i < ft_atoi(argv[1]))
	{
		pthread_mutex_init(&th[i].my_fork, NULL);
		pthread_mutex_init(&th[i].printing, NULL);
		th[i].num_philos = ft_atoi(argv[1]);
		th[i].whoami = i + 1;
		th[i].time_to_die = ft_atoi(argv[2]);
		th[i].time_to_eat = ft_atoi(argv[3]);
		th[i].time_to_sleep = ft_atoi(argv[4]);
		th[i].dinners = 0;
		th[i].my_f = 0;
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

void	free_all(t_data *th)
{
	int	i;
	int	max;

	max = th[0].num_philos;
	i = 0;
	while (i < max)
	{
		pthread_mutex_destroy(&th[i].my_fork);
		pthread_mutex_destroy(&th[i].printing);
		i++;
	}
	free(th);
}

int	main(int argc, char *argv[])
{
	int		i;
	t_data	*th;

	if (check_error(argc, argv) != 0)
		return (0);
	th = (t_data *)malloc(sizeof(t_data) * ft_atoi(argv[1]));
	set_data(th, argv, argc);
	i = -1;
	while (++i < th[0].num_philos)
		if (pthread_create(&th[i].philo, NULL, &go_eat, (void *)&th[i]) != 0)
			return (0);
	i = -1;
	while (++i < th[0].num_philos)
		if (pthread_join(th[i].philo, NULL) != 0)
			return (0);
	free_all(th);
	return (0);
}

//alcune cose non vengono scritte nell'ordine corretto, perche' virtualmente
//avvengono nello stesso momento ma a me seve che siano in un ordine specifico
//(o almeno credo) + helgrind mi rompe ancora il cazzo perche' in go_eat
//guardo gli indici delle forchette senza lockare e in check_if_dead modifico
// dead senza lockare