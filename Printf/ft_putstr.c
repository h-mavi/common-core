/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfanelli <mfanelli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/27 10:41:10 by mfanelli          #+#    #+#             */
/*   Updated: 2024/12/01 14:26:40 by mfanelli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putstr(char *s)
{
	int	i;

	i = 0;
	while (s[i])
	{
		write(1, &s[i], 1);
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
