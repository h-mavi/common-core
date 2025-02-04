/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bruh.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfanelli <mfanelli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/31 09:20:54 by mfanelli          #+#    #+#             */
/*   Updated: 2025/02/04 12:34:31 by mfanelli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_out(char **save, t_list *head)
{
	free_array(save);
	ft_exit_free(head, NULL, -1);
}

t_list	*find_cheapest(t_list **head)
{
	t_list	*tmp;

	tmp = *head;
	if (NULL == *head)
		return (NULL);
	while (tmp)
	{
		if (tmp->is_cheapest)
			return (tmp);
		tmp = tmp->next;
	}
	return (NULL);
}

void	finish_r(t_list **head, t_list *top_node, char	ls)
{
	int	i;

	i = top_node->data;
	while ((*head)->data != i && *head != top_node)
	{
		if (ls == 'a')
		{
			if (top_node->up_mediana)
				ra_rotate_a(head, 1);
			else
				rra_reverse_rotate_a(head, 1);
		}
		else if (ls == 'b')
		{
			if (top_node->up_mediana)
				rb_rotate_b(head, 1);
			else
				rrb_reverse_rotate_b(head, 1);
		}
	}
}
