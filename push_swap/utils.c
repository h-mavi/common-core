/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfanelli <mfanelli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/27 09:22:41 by mfanelli          #+#    #+#             */
/*   Updated: 2025/01/27 12:17:00 by mfanelli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_exit()
{
	ft_putstr_fd("Error\n", 2);
	exit (0);
}

void	ft_exit_free(t_list *head_a, t_list *head_b)
{
	t_list	*sort;

	while(head_a != NULL)
	{
		sort = head_a->next;
		free(head_a);
		head_a = sort;
	}
	while(head_b != NULL)
	{
		sort = head_b->next;
		free(head_b);
		head_b = sort;
	}
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
	}
	return (head);
}

void	ft_lstadd_front(t_list **lst, t_list *new)
{
	if (!lst || !new)
		return ;
	new->next = *lst;
	*lst = new;
}
