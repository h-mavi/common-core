/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   still_operation.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfanelli <mfanelli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/27 14:23:15 by mfanelli          #+#    #+#             */
/*   Updated: 2025/01/28 09:53:45 by mfanelli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ra_rotate_a(t_list **head_a)
{
	t_list	*sort;

	sort = *head_a;
	*head_a = (*head_a)->next;
	sort->next = NULL;
	ft_lstadd_back(head_a, sort);
}

void	rb_rotate_b(t_list **head_b)
{
	t_list	*sort;

	sort = *head_b;
	*head_b = (*head_b)->next;
	sort->next = NULL;
	ft_lstadd_back(head_b, sort);
}

void	rr_rotate_a_b(t_list **head_a, t_list **head_b)
{
	ra_rotate_a(head_a);
	rb_rotate_b(head_b);
}

void	rra_reverse_rotate_a(t_list **head_a)
{
	t_list	*sort;
	t_list	*find;

	sort = *head_a;
	while(sort->next != NULL)
		sort = sort->next;
	ft_lstadd_front(head_a, ft_lstnew(sort->data));
	find = *head_a;
	while (find->next != sort)
		find = find->next;
	find->next = NULL;
	free(sort);
}

void	rrb_reverse_rotate_b(t_list **head_b)
{
	t_list	*sort;
	t_list	*find;

	sort = *head_b;
	while(sort->next != NULL)
		sort = sort->next;
	ft_lstadd_front(head_b, ft_lstnew(sort->data));
	find = *head_b;
	while (find->next != sort)
		find = find->next;
	find->next = NULL;
	free(sort);
}
