/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfanelli <mfanelli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/02 09:52:06 by mfanelli          #+#    #+#             */
/*   Updated: 2024/12/02 11:12:18 by mfanelli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void    ft_check(va_list args, const char *format, int i)
{
    if (format[i+1] == 'c')
		ft_putchar(va_arg(args, int));
	if (format[i+1] == 's')
		ft_putstr(va_arg(args, char *));
	if (format[i+1] == '%')
		ft_putchar('%');
	if (format[i+1] == 'i' || format[i+1] == 'd')
		ft_putnbr(va_arg(args, int));
	if (format[i+1] == 'u')
		ft_unsigned_putnbr(va_arg(args, unsigned int));
    if (format[i+1] == 'x')
		ft_putnbrhex_min(va_arg(args, int));
    if (format[i+1] == 'X')
		ft_putnbrhex_MAX(va_arg(args, int));
}
