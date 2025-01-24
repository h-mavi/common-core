/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfanelli <mfanelli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/24 10:54:28 by mfanelli          #+#    #+#             */
/*   Updated: 2025/01/24 15:58:20 by mfanelli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int argc, char *argv[])
{
	int		i;
	int		num;
	t_list	*head;

	i = 0;
	head = NULL;
	if (argc == 1 || (argc == 2 && ft_strlen(argv[1]) == 0))
	{
		ft_putstr_fd("Error\n", 2);
		return (0);
	}
	else if (argc >= 2)
	{
		while(++i < argc)
		{
			ft_printf("av[%d]: %s\n", i, argv[i]);
			num = ft_atol(argv[i]);
			if (num > 2147483647 || num < -2147483648)
			{
				ft_putstr_fd("Error\n", 2);
				return (0);
			}
			ft_lstadd_back(&head, ft_lstnew(num));
		}
	}
}
