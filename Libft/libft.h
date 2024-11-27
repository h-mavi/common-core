/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfanelli <mfanelli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/20 13:36:11 by mfanelli          #+#    #+#             */
/*   Updated: 2024/11/27 17:00:28 by mfanelli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H
#include <unistd.h>

int ft_tolower(int value);

int ft_toupper(int value);

void    ft_striteri(char *s, void (*f)(unsigned int, char*))

#endif