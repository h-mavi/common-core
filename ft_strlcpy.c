/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfanelli <mfanelli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/27 10:44:00 by mfanelli          #+#    #+#             */
/*   Updated: 2024/11/27 10:44:08 by mfanelli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

unsigned int	ft_strlcpy(char *dest, char *src, unsigned int size)
{
	unsigned int	i;

	i = 0;
	if (!src)
		return (0);
	if (size < 1 || !dest)
	{
		while (src[i])
			i++;
		return (i);
	}
	while (src[i] != '\0' && i < size - 1)
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = '\0';
	i = 0;
	while (src[i])
		i++;
	return (i);
}

/* int	main(void)
{
	char	dest[70] = "cane e gatto";
	char	src[] = "07306802";
	int		count;

	count = ft_strlcpy(dest, src, 0);
	printf("%s\n", dest);
	printf("%s\n", src);
	printf("%d\n", count);
} */