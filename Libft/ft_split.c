/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfanelli <mfanelli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/27 15:13:51 by mfanelli          #+#    #+#             */
/*   Updated: 2024/11/27 17:03:33 by mfanelli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
/* #include "libft.h" */

static int	mod_strchr(const char *str, int c)
{
	int	i;

	i = -1;
	while (str[++i])
		if (str[i] == (char)c)
			return (i);
	if (str[i] == (char)c)
		return (i);
	else
		return (1);
}

static size_t	ft_strlen(const char *str)
{
	size_t	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
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

char	**ft_split(char const *s, char c)
{
	int		y;
	int		x;
	char	**ptr;

	y = mod_strchr(s, c);
	x = ft_strlen(s) - 1;
	ptr = (char **)malloc(sizeof(char *) * 3);
	if (ptr == NULL)
		return (NULL);
	ptr[2] = '\0';
	ptr[0] = ft_substr(s, 0, y);
	ptr[1] = ft_substr(s, y + 1, (x - y) + 1);
	return (ptr);
}

int	main(void)
{
	char	a[] = "lanon na cariola";
	char	**ptr;
	ptr = ft_split(a, ' ');
	printf("%s\n", ptr[0]);
	printf("%s", ptr[1]);
	free(ptr[0]);
	free(ptr[1]);
	free(ptr);
}