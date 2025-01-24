/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfanelli <mfanelli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/01 13:03:14 by mfanelli          #+#    #+#             */
/*   Updated: 2024/12/12 10:23:44 by mfanelli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

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

/* int	main(void)
{
	// int x = 1;
	int	a = ft_printf(" %u \n", 4294967295);
	int	b = printf (" %lu \n", 4294967295);
	printf ("La lunghezza di ft_printf e' %d\n", a);
	printf ("La lunghezza di printf e' %d\n", b);
} */
