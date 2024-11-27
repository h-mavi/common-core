/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfanelli <mfanelli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/27 15:13:51 by mfanelli          #+#    #+#             */
/*   Updated: 2024/11/27 17:25:42 by mfanelli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

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

/* int	main(void)
{
	char	a[] = "lanon na cariola";
	char	**ptr;
	ptr = ft_split(a, ' ');
	printf("%s\n", ptr[0]);
	printf("%s", ptr[1]);
	free(ptr[0]);
	free(ptr[1]);
	free(ptr);
} */