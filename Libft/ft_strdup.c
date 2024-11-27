/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfanelli <mfanelli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/27 10:42:16 by mfanelli          #+#    #+#             */
/*   Updated: 2024/11/27 10:42:24 by mfanelli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s1)
{
	int		len;
	char	*copy;
	int		i;

	len = ft_strlen(s1);
	copy = malloc(sizeof(char) * (len + 1));
	if (!copy)
		return (NULL);
	i = -1;
	while (s1[++i] != '\0')
		copy[i] = s1[i];
	copy[i] = '\0';
	return (copy);
}