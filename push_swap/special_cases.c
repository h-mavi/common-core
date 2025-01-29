/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   special_cases.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfanelli <mfanelli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/28 14:03:23 by mfanelli          #+#    #+#             */
/*   Updated: 2025/01/29 11:47:39 by mfanelli         ###   ########.fr       */
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
	if (!is_it_sort(*head_a))
		return ;
	special_case_1(head_a);
	return ;
}

void	special_case_2(t_list **head_a,t_list **head_b)
{
	(void)head_a;
	(void)head_b;
	return ;
}

void	special_case_3(t_list **head_a,t_list **head_b)
{
	(void)head_a;
	(void)head_b;
	return ;
}
