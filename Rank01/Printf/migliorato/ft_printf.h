/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfanelli <mfanelli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/20 13:36:11 by mfanelli          #+#    #+#             */
/*   Updated: 2025/03/06 10:04:20 by mfanelli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdlib.h>
# include <stdio.h>
# include <unistd.h>
# include <limits.h>
# include <stdarg.h>

//in ft_printf.c
int	ft_printf(const char *format, ...);

//in ft_putchar.c
int	ft_putptr(unsigned long long ptr);
int	ft_putstr(char *s);
int	ft_putchar(char c);

//in ft_putint.c
int	ft_unsigned_putnbr(unsigned long n);
int	ft_putnbrhex(unsigned int n, char c);
int	ft_putnbr(int n);

#endif
