/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_striteri.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfanelli <mfanelli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/27 10:42:49 by mfanelli          #+#    #+#             */
/*   Updated: 2024/11/28 14:16:38 by mfanelli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_striteri(char *s, void (*f)(unsigned int, char*))
{
	unsigned int	i;

	i = 0;
	while (i < ft_strlen(s) && s[i] != '\0')
	{
		f(i, &s[i]);
		i++;
	}
}

/* void	iter(unsigned int i, char * s) 
{
	*s += i;
}


int main(void)
{
	char	a[] = "";
	ft_striteri(a, iter);
	printf("%s", a);
} */