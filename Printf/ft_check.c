/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfanelli <mfanelli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/02 09:52:06 by mfanelli          #+#    #+#             */
/*   Updated: 2024/12/02 11:33:19 by mfanelli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int    ft_check(va_list args, const char *format, int i, int len)
{
    if (format[i+1] == 'c')
		len += ft_putchar(va_arg(args, int));
	if (format[i+1] == 's')
		len += ft_putstr(va_arg(args, char *));
	if (format[i+1] == '%')
		len += ft_putchar('%');
	if (format[i+1] == 'i' || format[i+1] == 'd')
		len += ft_putnbr(va_arg(args, int));
	if (format[i+1] == 'u')
		len += ft_unsigned_putnbr(va_arg(args, unsigned int));
    if (format[i+1] == 'x')
		len += ft_putnbrhex_min(va_arg(args, int));
    if (format[i+1] == 'X')
		len += ft_putnbrhex_MAX(va_arg(args, int));
	return (len);
}
