/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfanelli <mfanelli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/27 13:10:15 by mfanelli          #+#    #+#             */
/*   Updated: 2024/11/27 17:01:24 by mfanelli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
/* #include "libft.h" */

static char	*ft_strchr(const char *str, int c)
{
	int		i;

	i = -1;
	while (str[++i])
		if (str[i] == (char)c)
			return ((char *)str + i);
	if (str[i] == (char)c)
		return ((char *)str + i);
	return (NULL);
}

static size_t	ft_strlen(const char *str)
{
	size_t	i;

	i = 0;
	while (str[i])
		i++;
}

static char	*ft_strdup(const char *s1)
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

static char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	size_t	i;
	char	*sub;

	if (!s)
		return (NULL);
	if (start >= ft_strlen(s))
		return (ft_strdup(""));
	sub = malloc(sizeof(char) * (len + 1));
	if (!sub)
		return (NULL);
	i = 0;
	while (s[start] && i < len)
		sub[i++] = s[start++];
	sub[i] = '\0';
	return (sub);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	int		y;
	int		x;
	char	*ptr;

	y = 0;
	while (ft_strchr(set, s1[y]))
		y++;
	x = ft_strlen(s1) - 1;
	while (ft_strchr(set, s1[x]))
		x--;
	ptr = ft_substr(s1, y, (x - y) + 1);
	return (ptr);
}

int	main(void)
{
	char	a[] = "casccasacoglio andare a casa";
	char	b[] = "cas ";
	char	*ptr = ft_strtrim(a, b);
	printf("%s", ptr);
	free(ptr);
}
