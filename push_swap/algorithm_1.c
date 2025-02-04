/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algorithm_1.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfanelli <mfanelli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/28 09:24:56 by mfanelli          #+#    #+#             */
/*   Updated: 2025/02/04 12:21:33 by mfanelli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_move_node(t_list **head_a, t_list **head_b)
{
	t_list	*cheap;

	cheap = find_cheapest(head_b);
	if (cheap->up_mediana && cheap->target_node->up_mediana && \
	cheap->data != (*head_b)->data && cheap->target_node->data != (*head_a)->data)
		rr_rotate_a_b(head_a, head_b);
	else if (!(cheap->up_mediana) && !(cheap->target_node->up_mediana))
		rr_reverse_rotate_a_b(head_a, head_b);
	finish_r(head_b, cheap, 'b');
	finish_r(head_a, cheap->target_node, 'a');
	pa_push_a(head_a, head_b);
}

void	check_cheapest(t_list **head_b)
{
	long	best;
	t_list	*node;
	t_list	*tmp;

	if (NULL == *head_b)
		return ;
	best = LONG_MAX;
	tmp = *head_b;
	while (tmp)
	{
		if (tmp->price < best)
		{
			best = tmp->price;
			node = tmp;
		}
		tmp->is_cheapest = 0;
		tmp = tmp->next;
	}
	node->is_cheapest = 1;
}

t_list	*smallest(t_list **head)
{
	t_list	*tmp;
	t_list	*smol;

	if (NULL == *head)
		return (NULL);
	tmp = *head;
	smol = tmp;
	while(tmp && tmp->next)
	{
		if (tmp->data > (tmp->next)->data)
			smol = tmp->next;
		tmp = tmp->next;
	}
	return (smol);
}

int	is_it_sort(t_list *head_a)
{
	t_list	*tmp;	

	tmp = head_a;
	while(tmp != NULL && tmp->next != NULL) 
	{
		if (tmp->data > (tmp->next)->data)
			return (0);
		tmp = tmp->next;
	}
	return (1);
}

void	sorting(t_list **head_a, t_list **head_b, int len)
{
	if (len == 2)
		special_case_0(head_a);
	else if (len == 3)
		special_case_1(head_a);
	else if (len == 4)
		special_case_2(head_a, head_b);
	else if (len == 5)
		special_case_3(head_a, head_b);
	else if (len > 5)
		algorithm(head_a, head_b);
}