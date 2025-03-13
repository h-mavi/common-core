/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfanelli <mfanelli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/06 10:29:44 by mfanelli          #+#    #+#             */
/*   Updated: 2025/03/13 10:39:58 by mfanelli         ###   ########.fr       */
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

int	is_str_digit(char *str)
{
	int	i;

	i = -1;
	while (str[++i])
		if (str[i] < '0' || str[i] > '9')
			return (1);
	return (0);
}

void	*ft_bzero(void *buffer, size_t count)
{
	char	*str;
	size_t	i;

	if (buffer == NULL)
		return (NULL);
	str = (char *)buffer;
	i = 0;
	while (i < count)
		str[i++] = 0;
	return (buffer);
}
