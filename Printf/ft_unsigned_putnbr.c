/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_unsigned_putnbr.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfanelli <mfanelli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/27 10:40:42 by mfanelli          #+#    #+#             */
/*   Updated: 2024/12/02 09:04:13 by mfanelli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_unsigned_putnbr(unsigned int n)
{
	int	i;
	char			num[11];

	i = 0;
	while (n >= 10)
	{
		num[i++] = (n % 10) + '0';
		n = n / 10;
	}
	num[i] = (n % 10) + '0';
	while (i >= 0)
		write(1, &num[i--], 1);
}
int	main(void)
{
	ft_unsigned_putnbr(4294967295);
	printf("\n");
	/* ft_putnbr_fd(10000043, 1);
	printf("\n");
	ft_putnbr_fd(-10000043, 1);
	printf("\n");
	ft_putnbr_fd(-2147483648, 1);
	printf("\n");
	ft_putnbr_fd(2147483647, 1); */
}