/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfanelli <mfanelli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/27 10:40:42 by mfanelli          #+#    #+#             */
/*   Updated: 2024/12/01 14:34:58 by mfanelli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putnbr(int n)
{
	int		i;
	char	num[10];

	i = 0;
	if (n == -2147483648)
	{
		write(1, "-2147483648", 11);
		return ;
	}
	if (n < 0)
	{
		n = -n;
		write(1, "-", 1);
	}
	while (n >= 10)
	{
		num[i++] = (n % 10) + '0';
		n = n / 10;
	}
	num[i] = (n % 10) + '0';
	while (i >= 0)
		write(1, &num[i--], 1);
}
/* int	main(void)
{
	ft_putnbr_fd(0, 1);
	printf("\n");
	ft_putnbr_fd(10000043, 1);
	printf("\n");
	ft_putnbr_fd(-10000043, 1);
	printf("\n");
	ft_putnbr_fd(-2147483648, 1);
	printf("\n");
	ft_putnbr_fd(2147483647, 1);
} */