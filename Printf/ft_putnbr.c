/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfanelli <mfanelli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/27 10:40:42 by mfanelli          #+#    #+#             */
/*   Updated: 2024/12/03 11:58:35 by mfanelli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	control(int n)
{
	if (n == -2147483648)
	{
		write(1, "-2147483648", 11);
		return (11);
	}
	if (n == 0)
	{
		write (1, "0", 1);
		return (1);
	}
	return (0);
}

int	ft_nbr_negative(int temp)
{
	write(1, "-", 1);
	temp = 1;
	return (temp);
}

int	limit(int n, int temp)
{
	if (n == -2147483648 || n == 0)
	{
		temp = control(n);
		return (temp);
	}
	return (temp);
}

int	ft_putnbr(int n)
{
	int		i;
	int		temp;
	char	num[11];

	i = 0;
	temp = 0;
	if (n == 0 || n <= INT_MIN)
		return (temp = limit(n, temp));
	if (n < 0)
	{
		n = -n;
		temp += ft_nbr_negative(temp);
	}
	while (n >= 10)
	{
		num[i++] = (n % 10) + '0';
		n = n / 10;
	}
	num[i] = (n % 10) + '0';
	temp += i + 1;
	while (i >= 0)
		write(1, &num[i--], 1);
	return (temp);
}
