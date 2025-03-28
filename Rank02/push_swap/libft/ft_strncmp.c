/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfanelli <mfanelli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/27 10:45:17 by mfanelli          #+#    #+#             */
/*   Updated: 2024/11/27 10:45:27 by mfanelli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strncmp(char *s1, char *s2, unsigned int n)
{
	unsigned int	i;
	unsigned char	*str1;
	unsigned char	*str2;

	i = 0;
	str1 = (unsigned char *)s1;
	str2 = (unsigned char *)s2;
	while (i < n && (str1[i] || str2[i]))
	{
		if (str1[i] != str2[i])
		{
			if (str1[i] > str2[i])
				return (1);
			else if (str1[i] < str2[i])
				return (-1);
		}
		i++;
	}
	return (0);
}

/* int	main(void)
{
	char *s1 = "test\200";
	char *s2 = "test\0";
	printf("%d\n\n\n", ft_strncmp(s1, s2, 6));
	printf("%c", (char)s1[4]);
} */