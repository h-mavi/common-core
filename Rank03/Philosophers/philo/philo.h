/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfanelli <mfanelli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/06 10:25:12 by mfanelli          #+#    #+#             */
/*   Updated: 2025/03/13 09:22:16 by mfanelli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H
# include <stdlib.h>
# include <stdio.h>
# include <unistd.h>
# include <pthread.h>
# include <sys/time.h>

typedef struct s_gen
{
	pthread_mutex_t	printing;
	pthread_mutex_t	murtem;
	int				num_philos;
	long long		time_to_die;
	long long		time_to_eat;
	long long		time_to_sleep;
	int				max_dinners;
}	t_gen;

typedef struct s_philo
{
	pthread_t		filo;
	pthread_mutex_t	my_fork;
	pthread_mutex_t	*left_fork; //unica cosa che ho fatto, indirizzo della fork e non del philo
	pthread_mutex_t	timing;
	int				whoami;
	int				dinners;
	int				dead;
	struct timeval	start;
	struct timeval	last_eat;
	struct s_philo	*head_th;
	t_gen			*gen;
}	t_philo;

//in main.c
void		set_data(t_philo *th, char *argv[], int argc, t_gen *gen);
int			check_error(int argc, char *argv[]);
void		set_gen(char *argv[], int argc, t_gen *gen);
void		free_all(t_philo *th);

//in more.c
void		locks(t_philo *th);
void		unlocks(t_philo *th);
long long	get_curr_time(void);
long long	get_start_time(t_philo *th);
void		ft_scriba(char	*str, t_philo *th);
void		manual_sleep(t_philo *th, long long time);

//in ripper.c
void		*check_death(void   *args);
int			is_someone_dead(t_philo *th);

//in tasks.c
void		*lonely(void *args);
int			if_check(t_philo *th);
void		go_sleeping(t_philo *th);
void		go_eat(t_philo *th);
void		*routine(void *args);

//in utils.c
int			ft_isdigit(int a);
int			ft_iswhitespace(char c);
int			ft_atoi(const char *str);
int			is_str_digit(char *str);
void		*ft_bzero(void *buffer, size_t count);
void		*ft_calloc(size_t nmemb, size_t size);

#endif