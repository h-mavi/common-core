/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfanelli <mfanelli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/27 10:41:10 by mfanelli          #+#    #+#             */
/*   Updated: 2024/11/28 15:43:20 by mfanelli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putstr_fd(char *s, int fd)
{
	int	i;

	if (fd < 0)
		return ;
	i = 0;
	while (s[i])
	{
		write(fd, &s[i], 1);
		i++;
	}
}

/* int main()
{
	ft_putstr_fd("abcdef", 1);
	ft_putstr_fd("|\n1234", 1);
	ft_putstr_fd("|\t567", 1);
	ft_putstr_fd("", 1);
	ft_putstr_fd("|\nend!", 1);
} */
