/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfanelli <mfanelli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/27 10:33:23 by mfanelli          #+#    #+#             */
/*   Updated: 2025/01/10 16:31:35 by mfanelli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_bzero(void *buffer, size_t count)
{
	char	*str;
	size_t	i;

	if (buffer == NULL)
		return (NULL);
	str = (char *)buffer;
	i = 0;
	while (i < count)
		str[i++] = 0;
	return (buffer);
}
/* int main()
{
    char buffer[10] = "123456789";
    printf("Prima di ft_bzero: \"%s\"\n", buffer);

    ft_bzero(buffer, 5);
    printf("Dopo ft_bzero (5 byte): \"%s\"\n", buffer);

    char buffer2[10] = "abcdefghi";
    printf("Prima di bzero (standard): \"%s\"\n", buffer2);
    bzero(buffer2, 5);
    printf("Dopo bzero (5 byte): \"%s\"\n", buffer2);
} */