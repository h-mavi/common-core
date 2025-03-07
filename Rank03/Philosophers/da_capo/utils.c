/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfanelli <mfanelli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/06 10:29:44 by mfanelli          #+#    #+#             */
/*   Updated: 2025/03/07 14:14:40 by mfanelli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

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

int	im_writing(t_philo *th)
{
	int	*i;

	i = (int *)malloc(sizeof(int));
	*i = -1;
	if (is_someone_dead((*th).head_th) != 0)
	{
		while (++*i < th[0].num_philos)
			pthread_mutex_lock(&th[*i].printing);
		free(i);
		return (1);
	}
	free(i);
	return (0);
}

void	i_finished(t_philo *th)
{
	int	*i;

	i = (int *)malloc(sizeof(int));
	*i = -1;
	while (++*i < th[0].num_philos)
		pthread_mutex_unlock(&th[*i].printing);
	free(i);
}
