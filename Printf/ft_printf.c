/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfanelli <mfanelli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/01 13:03:14 by mfanelli          #+#    #+#             */
/*   Updated: 2024/12/02 12:05:49 by mfanelli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_printf(const char *format, ...)
{
	va_list	args;
	va_start (args, format);
	int	i;
	int	len;

	i = 0;
	len = 0;
	while(format[i])
	{
		if (format[i] == '%')
		{
			len = ft_check(args ,format, i, len);
			i += 2;
		}	
		ft_putchar(format[i]);
		i++;
		len++;
	}
	va_end(args);
	return(len);
}
int	main(void)
{
	/* unsigned int	i  = 4294967295;
	unsigned int	*ptr = &i; */
	int	a = ft_printf("cacca %c nel puzzo\n", 'i');
	int	b = printf ("cacca %c nel puzzo\n", 'i');
	printf ("La lunghezza di ft_printf e' %d\n", a);
	printf ("La lunghezza di ft_printf e' %d\n", b);
}
