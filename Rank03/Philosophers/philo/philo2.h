/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo2.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfanelli <mfanelli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/20 08:54:00 by mfanelli          #+#    #+#             */
/*   Updated: 2025/02/21 10:55:13 by mfanelli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO2_H
# define PHILO2_H
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
	int             time_to_die;
	int             time_to_eat;
	int             time_to_sleep;
	int				max_dinners;
	int             dinners;
	int             my_f;
	int             *your_f;
	struct timeval	slay;
	int             dead;
	struct data_s	*left_philo;
	struct data_s 	*head_th;
}		data_t;


//in utils2.c
int		ft_isdigit(int a);
int		ft_iswhitespace(char c);
int		ft_atoi(const char *str);
void	im_writing(data_t *th);
void	i_finished(data_t *th);
void	printing(data_t *th);



#endif