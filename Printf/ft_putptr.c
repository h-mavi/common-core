/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putptr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfanelli <mfanelli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/02 12:11:57 by mfanelli          #+#    #+#             */
/*   Updated: 2024/12/02 14:29:44 by mfanelli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putptr(unsigned long long ptr)
{
	int	len;

	if (!ptr)
	{
		write (1, "(nil)", 1);
		return (5);
	}
	len = 0;
	write(1, "0x", 2);
	len += 2;
	len += ft_putnbrhex_ptr((unsigned long)ptr);
	return (len);
}
