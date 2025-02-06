/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfanelli <mfanelli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/27 10:38:14 by mfanelli          #+#    #+#             */
/*   Updated: 2024/11/27 10:38:25 by mfanelli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	unsigned char	*dest;
	unsigned char	*search;
	size_t			i;

	if (!dst && !src)
		return (NULL);
	dest = (unsigned char *) dst;
	search = (unsigned char *) src;
	i = -1;
	while (++i < n)
		dest[i] = search[i];
	return (dst);
}

/* int main()
{
	char *cane[12];
	char *gatto = "ciao min va!";
	printf("%s", (char *)ft_memcpy(cane, gatto, 12));
} */