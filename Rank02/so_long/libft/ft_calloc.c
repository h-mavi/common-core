/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfanelli <mfanelli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/27 10:33:49 by mfanelli          #+#    #+#             */
/*   Updated: 2025/01/10 15:24:39 by mfanelli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t nmemb, size_t size)
{
	void	*str;

	str = malloc(nmemb * size);
	if (!str)
		return (NULL);
	ft_bzero(str, size * nmemb);
	return (str);
}

/* int main()
{
    size_t nmemb = 5;
    size_t size = sizeof(int);

    int *arr_original = (int *)calloc(nmemb, size);
    int *arr_comparato = (int *)ft_calloc(nmemb, size);

    for (size_t i = 0; i < nmemb; i++) {
        printf;
    }

    free(arr_original);
    free(arr_comparato);

    return 0;
} */