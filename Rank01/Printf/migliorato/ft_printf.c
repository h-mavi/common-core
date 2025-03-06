/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfanelli <mfanelli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/01 13:03:14 by mfanelli          #+#    #+#             */
/*   Updated: 2025/03/06 09:53:24 by mfanelli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_check(va_list args, const char *format, int i, int len)
{
	if (format[i + 1] == 'c')
		len += ft_putchar(va_arg(args, int));
	if (format[i + 1] == 's')
		len += ft_putstr(va_arg(args, char *));
	if (format[i + 1] == '%')
		len += ft_putchar('%');
	if (format[i + 1] == 'i' || format[i + 1] == 'd')
		len += ft_putnbr(va_arg(args, int));
	if (format[i + 1] == 'u')
		len += ft_unsigned_putnbr(va_arg(args, unsigned int));
	if (format[i + 1] == 'x')
		len += ft_putnbrhex(va_arg(args, int), 'x');
	if (format[i + 1] == 'X')
		len += ft_putnbrhex(va_arg(args, int), 'X');
	if (format[i + 1] == 'p')
		len += ft_putptr((unsigned long)va_arg(args, void *));
	return (len);
}

int	ft_printf(const char *format, ...)
{
	va_list	args;
	int		i;
	int		len;

	if (format == NULL)
		return (0);
	va_start (args, format);
	i = 0;
	len = 0;
	while (format[i])
	{
		if ((format[i] == '%' && format[i + 1] != '\0'))
		{
			len = ft_check(args, format, i, len);
			i += 2;
		}
		else if (format[i] != '%')
		{
			ft_putchar(format[i++]);
			len++;
		}
	}
	va_end (args);
	return (len);
}

// int	main(void)
// {
// 	int	a = ft_printf(" %p %p ", LONG_MIN, LONG_MAX);
// 	int	b = printf(" %ld %ld ", LONG_MIN, LONG_MAX);
// 	printf ("\nLa lunghezza di ft_printf e' %d\n", a);
// 	printf ("La lunghezza di printf e' %d\n", b);
// }
