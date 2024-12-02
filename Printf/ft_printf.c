/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfanelli <mfanelli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/01 13:03:14 by mfanelli          #+#    #+#             */
/*   Updated: 2024/12/02 14:29:20 by mfanelli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_printf(const char *format, ...)
{
	va_list	args;
	int		i;
	int		len;

	va_start (args, format);
	i = 0;
	len = 0;
	while (format[i])
	{
		if (format[i] == '%')
		{
			len = ft_check(args, format, i, len);
			i += 2;
		}
		ft_putchar(format[i]);
		i++;
		len++;
	}
	va_end (args);
	return (len);
}
/* int	main(void)
{
	unsigned int	i  = 1;
	unsigned int	*ptr = &i;
	int	a = ft_printf("cacca %p nel puzzo\n", (void *)ptr);
	int	b = printf ("cacca %p nel puzzo\n", (void *)ptr);
	printf ("La lunghezza di ft_printf e' %d\n", a);
	printf ("La lunghezza di ft_printf e' %d\n", b);
}
 */