/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfanelli <mfanelli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/01 13:03:14 by mfanelli          #+#    #+#             */
/*   Updated: 2024/12/01 14:36:17 by mfanelli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_printf(const char *format, ...)
{
	va_list	args;
	va_start (args, *format);
	int	i;
	int	len;

	i = 0;
	len = 0;
	while(format[i] != NULL)
	{
		if (format[i] == '%')
		{
			if (format[i+1] == 's' || format[i+1] == 'c')
				ft_putstr(va_arg(args, char));
			if (format[i+1] == 'i' || format[i+1] == 'd')
				ft_putnmbr(va_arg(args, int));
			len -= 1;
		}
		ft_putchar(format[i]);
		i++;
		len++;
	}
	va_end(args);
	return(len);
}

// printf ("cacca %d nel puzzo", 5);