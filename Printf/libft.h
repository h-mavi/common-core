/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfanelli <mfanelli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/20 13:36:11 by mfanelli          #+#    #+#             */
/*   Updated: 2024/12/02 11:41:44 by mfanelli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include <stdlib.h>
# include <stdio.h>
# include <unistd.h>
#include <stdarg.h>

int	ft_printf(const char *format, ...);
int	ft_putchar(char c);
int	ft_putstr(char *s);
int	ft_putnbr(int n);
int	ft_putnbrhex_min(int nbr);
int	ft_putnbrhex_MAX(int nbr);
int	ft_unsigned_putnbr(unsigned int n);
int ft_check(va_list args, const char *format, int i, int len);

#endif
