/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfanelli <mfanelli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/20 08:53:42 by mfanelli          #+#    #+#             */
/*   Updated: 2025/02/21 14:26:18 by mfanelli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"


void	ft_scriba(char	*str, data_t *th)
{
	im_writing((*th).head_th);
	printf(str,(*th).whoami);
	i_finished((*th).head_th);
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

void	set_data(data_t *th, char *argv[], int argc)
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
		{
			th[i].left_philo = &th[i - 1];
			th[i].your_f = &th[i - 1].my_f;
		}
	}
	th[0].left_philo = &th[i - 1];
	th[0].your_f = &th[i - 1].my_f;
}

int	check_if_dead(data_t *th)
{
	struct timeval	temp;

	gettimeofday(&temp, NULL);
	if (((temp.tv_usec - (*th).slay.tv_usec) / 1000) >= (*th).time_to_die)
	{	
		(*th).dead = 1;
		ft_scriba("%d E' MORTO\n", th);
		return (0);
	}
	return (1);
}

int	go_thinking(data_t *th)
{
	ft_scriba("%d pensa...\n", th);
	while ((*th).my_f != 0 || *(*th).your_f != 0)
		if (check_if_dead(th) == 0)
			return (0);
	return (1);
}

void	go_sleeping(data_t *th)
{
	ft_scriba("%d va a dormire\n", th);
	usleep((*th).time_to_sleep * 1000);
	if (check_if_dead(th) == 0)
		return ;
	ft_scriba("%d finisce di dormire\n", th);
	return ;
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

void	*go_eat(void *th)
{
	data_t	*cp;

	cp = (data_t *)th;
	gettimeofday(&(*cp).slay, NULL);
	while (((*cp).max_dinners != 0 && (*cp).dinners < (*cp).max_dinners && \
	is_someone_dead((*cp).head_th) != 0) || ((*cp).max_dinners == 0 && is_someone_dead((*cp).head_th) != 0))
	{
		if ((*cp).my_f == 0 && *(*cp).your_f == 0)
		{
			(*cp).my_f = 1;
			*(*cp).your_f = 1;
			pthread_mutex_lock(&(*cp).my_fork);
			pthread_mutex_lock(&((*cp).left_philo->my_fork));
			ft_scriba("%d inizia a mangiare\n", cp);
			usleep((*cp).time_to_eat * 1000);
			ft_scriba("%d ha finito\n", cp);
			pthread_mutex_unlock(&(*cp).my_fork);
			pthread_mutex_unlock(&((*cp).left_philo->my_fork));
			(*cp).my_f = 0;
			*(*cp).your_f = 0;
			++(*cp).dinners;
			gettimeofday(&(*cp).slay, NULL);
			go_sleeping(cp);
		}
		if (is_someone_dead((*cp).head_th) != 0 && (*cp).dinners < (*cp).max_dinners)
			if (go_thinking(cp) == 0)
				return (0);
	}
	return (0);
}

void	free_all(data_t *th)
{
	int	i;
	int	max;

	max = th[0].num_philos;
	i = 0;
	while(i < max)
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
	data_t	*th;

	if (check_error(argc, argv) != 0)
		return (0);
	th = (data_t *)malloc(sizeof(data_t) * ft_atoi(argv[1]));
	set_data(th, argv, argc);
	i = -1;
	while (++i < th[0].num_philos)
		if (pthread_create(&th[i].philo, NULL, &go_eat, (void *)&th[i]) != 0)
			return (0);
	i = -1;
	while (++i < th[0].num_philos)
		if (pthread_join(th[i].philo, NULL) != 0) //pthread_detach!!!!!
			return (0);
	free_all(th);
	return (0);
}

//devo capire come fare a mandare singolarmente i messaggi senza che aspettino gli altri thread
//+ si sminchia se gli do quanti pasti fare e se do 3 philo dopop un po' uno scompare senza morire
//da fare TANTI, TANTI TEST... pero' non leakka