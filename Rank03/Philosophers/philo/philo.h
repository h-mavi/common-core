/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfanelli <mfanelli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/20 08:54:00 by mfanelli          #+#    #+#             */
/*   Updated: 2025/02/25 14:39:37 by mfanelli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H
# include <stdlib.h>
# include <stdio.h>
# include <unistd.h>
# include <pthread.h>
# include <sys/time.h>

typedef struct data_s
{
	pthread_t		philo;
	pthread_mutex_t my_fork;
	pthread_mutex_t printing;
	int             num_philos;
	int             whoami;
	long long       time_to_die;
	long long       time_to_eat;
	long long       time_to_sleep;
	int				max_dinners;
	int             dinners;
	int             my_f;
	int             dead;
	struct timeval	start;
	struct timeval	last_eat;
	struct data_s	*left_philo;
	struct data_s 	*head_th;
}		data_t;


//in utils.c
int		ft_isdigit(int a);
int		ft_iswhitespace(char c);
int		ft_atoi(const char *str);
int		im_writing(data_t *th);
void	i_finished(data_t *th);
// void	printing(data_t *th);

//in main.c
void	ft_scriba(char	*str, data_t *th);
int		check_error(int argc, char *argv[]);
void	set_data(data_t *th, char *argv[], int argc);
void	free_all(data_t *th);

//tasks.c
int		check_if_dead(data_t *th);
int		is_someone_dead(data_t *th);
int		go_thinking(data_t *th);
void	go_sleeping(data_t *th);
void	*go_eat(void *th);

//in more.c
long long	get_curr_time(void);
void		locks(data_t *th);
void		unlocks(data_t *th);
void		gnam(data_t *th);

#endif