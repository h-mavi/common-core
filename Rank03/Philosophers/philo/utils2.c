/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfanelli <mfanelli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/20 09:00:48 by mfanelli          #+#    #+#             */
/*   Updated: 2025/02/21 10:42:48 by mfanelli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo2.h"

int	ft_isdigit(int a)
{
	if (a >= '0' && a <= '9')
		return (1);
	return (0);
}

int	ft_iswhitespace(char c)
{
	if (c == ' ' || c == '\t' || c == '\n' || c == '\f' \
		|| c == '\v' || c == '\r')
		return (1);
	return (0);
}

int	ft_atoi(const char *str)
{
	int	i;
	int	num;
	int	sign;

	num = 0;
	i = 0;
	sign = 1;
	while (ft_iswhitespace(str[i]))
		i++;
	if (str[i] == '-')
		sign = -1;
	if (str[i] == '-' || str[i] == '+')
		i++;
	while (str[i] != '\0' && ft_isdigit(str[i]))
		num = (num * 10) + (str[i++] - '0');
	num = num * sign;
	return (num);
}

void	im_writing(data_t *th)
{
	int	*i;

	i = (int *)malloc(sizeof(int));
	*i = -1;
	while (++*i < th[0].num_philos)
		pthread_mutex_lock(&th[*i].printing);
	free(i);
}

void	i_finished(data_t *th)
{
	int	*i;

	i = (int *)malloc(sizeof(int));
	*i = -1;
	while (++*i < th[0].num_philos)
		pthread_mutex_unlock(&th[*i].printing);
	free(i);
}

void	printing(data_t *th)
{
	printf("\nSono il filosofo %d e so che:\ni filosofi in tutto son %d,\nil tempo per dormire, mangiare e morire e' %d, %d, %d,\nche la mia forchetta e' %p (%p) e quella del philo a sinistra e' %p (%p),\nho mangiato %d volte, la mia flag di morte e' %d,\nmentre quella per mangiare e' ...,\ne infine la nostra casa ha l'indirizzo %p.\n", \
			(*th).whoami, (*th).num_philos, (*th).time_to_sleep, (*th).time_to_eat, (*th).time_to_die, &((*th).my_fork), &((*th).my_f), &((*th).left_philo->my_fork), (*th).your_f, (*th).dinners, (*th).dead, (*th).head_th);
}
