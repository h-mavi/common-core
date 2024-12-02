/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfanelli <mfanelli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/27 10:40:42 by mfanelli          #+#    #+#             */
/*   Updated: 2024/12/02 12:01:27 by mfanelli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_nbr_negative(void)
{
	write(1, "-", 1);
	return (1);
}

int	ft_putnbr(int n)
{
	int		i;
	int		temp;
	char	num[10];

	i = 0;
	if (n == -2147483648)
	{
		write(1, "-2147483648", 11);
		return (11);
	}
	if (n < 0)
	{
		n = -n;
		temp = ft_nbr_negative();
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
