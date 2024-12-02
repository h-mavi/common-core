/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfanelli <mfanelli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/20 13:36:11 by mfanelli          #+#    #+#             */
/*   Updated: 2024/12/02 11:14:39 by mfanelli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include <stdlib.h>
# include <stdio.h>
# include <unistd.h>
#include <stdarg.h>

int	ft_printf(const char *format, ...);
void	ft_putchar(char c);
void	ft_putstr(char *s);
void	ft_putnbr(int n);
void	ft_putnbrhex_min(int nbr);
void	ft_putnbrhex_MAX(int nbr);
void	ft_unsigned_putnbr(unsigned int n);
void    ft_check(va_list args, const char *format, int i);

#endif
