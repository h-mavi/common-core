/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfanelli <mfanelli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/18 13:59:46 by mfanelli          #+#    #+#             */
/*   Updated: 2025/02/19 12:07:35 by mfanelli         ###   ########.fr       */
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
	pthread_mutex_t	mutex_myf;
	pthread_mutex_t	mutex_yourf;
	int				whoiam;
	int				num_philo;
	int				myf_occ;
	int				yourf_occ;
	int				is_spleeping;
	int				is_dead;
	int				time_to_eat;
	int				time_to_sleep;
	int				time_to_die;
	struct data_s 	*head_th;
}		data_t;


///in main.c
void	set_values(char *argv[], data_t	*th);
int		check_eating(data_t th);
void	go_sleeping(data_t th);
void 	go_thinking(data_t th);
void	*fun_eat(void *th);

//in utils.c
int	ft_isdigit(int a);
int	ft_iswhitespace(char c);
int	ft_atoi(const char *str);


#endif