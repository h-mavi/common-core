/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   special_cases.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfanelli <mfanelli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/28 14:03:23 by mfanelli          #+#    #+#             */
/*   Updated: 2025/01/31 15:30:53 by mfanelli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	special_case_0(t_list **head_a)
{
	sa_swap_a(*head_a, 1);
}

void	special_case_1(t_list **head_a)
{
	t_list	*tmp;

	tmp = *head_a;
	if (((tmp->next)->next)->data && tmp->data > (tmp->next)->data \
		&& (tmp->next)->data < ((tmp->next)->next)->data && \
		tmp->data > ((tmp->next)->next)->data)
		ra_rotate_a(head_a, 1);
	else if (tmp->data > (tmp->next)->data)
		sa_swap_a(*head_a, 1);
	tmp = *head_a;
	if ((tmp->next)->next != NULL)
		tmp = tmp->next;
	if (tmp->data > (tmp->next)->data)
		rra_reverse_rotate_a(head_a, 1);
	if (is_it_sort(*head_a))
		return ;
	special_case_1(head_a);
	return ;
}

void	special_case_2(t_list **head_a,t_list **head_b)
{
	t_list	*tmp;

	tmp = *head_a;
	while(!must_be_smaller(head_a))
	{
		tmp = *head_a;
		if((tmp->next)->data < tmp->data && (tmp->next)->data < \
		((tmp->next)->next)->data && (tmp->next)->data < \
		(((tmp->next)->next)->next)->data)
			ra_rotate_a(head_a, 1);
		else if((((tmp->next)->next)->next)->data < tmp->data && \
		(((tmp->next)->next)->next)->data < (tmp->next)->data && \
		(((tmp->next)->next)->next)->data < ((tmp->next)->next)->data)
			rra_reverse_rotate_a(head_a, 1);
		else
			ra_rotate_a(head_a, 1);
	}
	if (is_it_sort(*head_a))
		return ;
	pb_push_b(head_a, head_b);
	special_case_1(head_a);
	pa_push_a(head_a, head_b);
	if (is_it_sort(*head_a))
		return ;
}

void	special_case_3(t_list **head_a,t_list **head_b)
{
	t_list	*tmp;

	tmp = *head_a;
	if (tmp->data > (tmp->next)->data && tmp->data > ((tmp->next)->next)->data\
	&& tmp->data > (((tmp->next)->next)->next)->data && tmp->data > \
	((((tmp->next)->next)->next)->next)->data)
		ra_rotate_a(head_a, 1);
	while (!must_be_smaller(head_a))
	{
		tmp = *head_a;
		if (tmp->data > (tmp->next)->data)
			sa_swap_a(*head_a, 1);
		else
			rra_reverse_rotate_a(head_a, 1);
	}
	if (is_it_sort(*head_a))
		return ;
	pb_push_b(head_a, head_b);
	special_case_2(head_a, head_b);
	pa_push_a(head_a, head_b);
	if (is_it_sort(*head_a))
		return ;
}
