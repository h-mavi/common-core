/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfanelli <mfanelli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/03 14:34:24 by mfanelli          #+#    #+#             */
/*   Updated: 2024/12/09 17:28:56 by mfanelli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_strlen(char *str) ///char al posto di const
{
	size_t	i;

	i = 0;
	if (str == NULL)
		return (0); //if
	while (str[i] != '\0')
		i++;
	return (i);
}

char	*ft_strchr(const char *s, int c)
{
	int		i;
	char	*str;

	if (s == NULL)
		return (NULL);
	str = (char *)s;
	i = 0;
	while (str[i] != '\0')
	{
		if (str[i] == (char)c)
			return (&str[i]);
		i++;
	}
	if (str[i] == (char)c)
		return (&str[i]);
	return (NULL);
}

char	*ft_substr(char const *s, unsigned int start, char stop_char)
{
	char	*str;
	size_t	i;//intera funzione copiata
	size_t	len;

	if (s == NULL || s[0] == '\0')
		return (NULL);
	len = 0;
	while (s[len] != stop_char && s[len] != '\0')
		len++;
	str = (char *)ft_calloc(((len - start) + 2), sizeof(char));
	if (!str)
		return (NULL);
	i = 0;
	while (s && s[start] != stop_char && s[start] != '\0')
		str[i++] = s[start++];
	if (s && s[start] == stop_char)
		str[i++] = '\n';
	str[i] = '\0';
	return (str);
}

char	*ft_calloc(size_t count, size_t size)
{
	char	*str;
	size_t	i;

	str = (char *)malloc(sizeof(char) * (count * size));
	if (!str)
		return (NULL);
	i = 0;
	while (i < (count * size))
	{
		str[i] = '\0';
		i++;
	}
	return (str);
}
