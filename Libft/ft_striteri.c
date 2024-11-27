/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_striteri.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfanelli <mfanelli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/27 10:42:49 by mfanelli          #+#    #+#             */
/*   Updated: 2024/11/27 12:33:28 by mfanelli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "libft.h"

static size_t	ft_strlen(const char *str)
{
	size_t	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

void ft_striteri(char *s, void (*f)(unsigned int, char*))
{
	unsigned int i;

	i = 0;
	while(i < ft_strlen(s) && s[i] != '\0')
	{
		f(i, s);
		i++;
	}

}

/* static void	to_Upper(unsigned int index, char *c) 
{
	if (c[index] > 96 && c[index] < 123)
		c[index] -= 32;
}


int main(void)
{
	char	a[] = "la madonna puttana";
	ft_striteri(a, to_Upper);
	printf("%s", a);
} */