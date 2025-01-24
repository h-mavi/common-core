/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfanelli <mfanelli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/24 10:54:28 by mfanelli          #+#    #+#             */
/*   Updated: 2025/01/24 11:05:30 by mfanelli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int argc, int *argv[])
{
	int	i;
	int	x;

	x = 1;
	i = 1;
	while (i < argc)
	{
		if (sizeof(argv[i] != sizeof(int)))
		{
			ft_printf("Error\n");
			return (0);
		}
		while(x < argc)
		{
			if (argv[i] == argv[x])
			{
				ft_printf("Error\n");
				return (0);
			}
			x++;
		}
		i++;
	}
}