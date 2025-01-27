/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfanelli <mfanelli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/27 09:22:41 by mfanelli          #+#    #+#             */
/*   Updated: 2025/01/27 10:03:18 by mfanelli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_exit()
{
	ft_putstr_fd("Error\n", 2);
	exit (0);
}

t_list	*split_str(char *argv[])
{
	int		i;
	int		x;
	long	num;
	t_list	*head;
	char	**save;

	head = NULL;
	i = -1;
	save = ft_split(argv[1], ' ');
	while (save[++i] != NULL)
	{
		x = 0;
		while (save[i][x] != '\0')
		{
			if (x == 0 && (save[i][0] == '+' || save[i][0] == '-'))
				x++;
			if(!ft_isdigit(save[i][x++]))
				ft_exit();
		}
		num = ft_atol(save[i]);
		if (num > 2147483647 || num < -2147483648)
			ft_exit();
		ft_lstadd_back(&head, ft_lstnew(num));
		ft_printf("av[%d]: %d\n", i, num);
	}
	return (head);
}
