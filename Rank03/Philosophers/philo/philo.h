/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfanelli <mfanelli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/20 08:54:00 by mfanelli          #+#    #+#             */
/*   Updated: 2025/02/25 16:44:43 by mfanelli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H
# include <stdlib.h>
# include <stdio.h>
# include <unistd.h>
# include <pthread.h>
# include <sys/time.h>

typedef struct s_data
{
	pthread_t		philo;
	pthread_mutex_t	my_fork;
	pthread_mutex_t	printing;
	int				num_philos;
	int				whoami;
	long long		time_to_die;
	long long		time_to_eat;
	long long		time_to_sleep;
	int				max_dinners;
	int				dinners;
	int				my_f;
	int				dead;
	struct timeval	start;
	struct timeval	last_eat;
	struct s_data	*left_philo;
	struct s_data	*head_th;
}		t_data;

//in utils.c
int			ft_isdigit(int a);
int			ft_iswhitespace(char c);
int			ft_atoi(const char *str);
int			im_writing(t_data *th);
void		i_finished(t_data *th);
// void	printing(t_data *th);

//in main.c
void		ft_scriba(char	*str, t_data *th);
int			check_error(int argc, char *argv[]);
void		set_data(t_data *th, char *argv[], int argc);
void		free_all(t_data *th);

//tasks.c
int			check_if_dead(t_data *th);
int			is_someone_dead(t_data *th);
void		go_thinking(t_data *th);
void		go_sleeping(t_data *th);
void		*go_eat(void *th);

//in more.c
long long	get_curr_time(void);
void		locks(t_data *th);
void		unlocks(t_data *th);
void		gnam(t_data *th);

#endif