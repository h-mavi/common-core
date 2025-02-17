/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfanelli <mfanelli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/27 10:38:36 by mfanelli          #+#    #+#             */
/*   Updated: 2024/11/27 10:38:44 by mfanelli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	int	i;

	if (!dst && !src)
		return (NULL);
	i = len;
	if (dst > src)
		while (--i >= 0)
			((char *)dst)[i] = ((char *)src)[i];
	else
		ft_memcpy(dst, src, len);
	return (dst);
}

/* int main()
{
	char wer[6] = "gatto";
	char ter[6] = "catto";

	printf("%s", (char *)ft_memmove(wer, ter, 5));
} */