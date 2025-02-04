/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   still_operation.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfanelli <mfanelli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/27 14:23:15 by mfanelli          #+#    #+#             */
/*   Updated: 2025/02/04 17:49:28 by mfanelli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ra_rotate_a(t_list **head_a, int p)
{
	t_list	*sort;

	sort = *head_a;
	*head_a = (*head_a)->next;
	sort->next = NULL;
	ft_lstadd_back(head_a, sort);
	if (p == 1)
		ft_printf("ra\n");
}

void	rb_rotate_b(t_list **head_b, int p)
{
	t_list	*sort;

	sort = *head_b;
	*head_b = (*head_b)->next;
	sort->next = NULL;
	ft_lstadd_back(head_b, sort);
	if (p == 1)
		ft_printf("rb\n");
}

void	rr_rotate_a_b(t_list **head_a, t_list **head_b)
{
	ra_rotate_a(head_a, 0);
	rb_rotate_b(head_b, 0);
	ft_printf("rr\n");
}

void	rra_reverse_rotate_a(t_list **head_a, int p)
{
	t_list	*sort;
	t_list	*find;

	if (*head_a == NULL || (*head_a)->next == NULL)
		return ;
	sort = *head_a;
	while (sort->next != NULL)
		sort = sort->next;
	ft_lstadd_front(head_a, sort);
	find = *head_a;
	while (find->next != sort)
		find = find->next;
	find->next = NULL;
	if (p == 1)
		ft_printf("rra\n");
}

void	rrb_reverse_rotate_b(t_list **head_b, int p)
{
	t_list	*sort;
	t_list	*find;

	if (*head_b == NULL || (*head_b)->next == NULL)
		return ;
	sort = *head_b;
	while (sort->next != NULL)
		sort = sort->next;
	ft_lstadd_front(head_b, sort);
	find = *head_b;
	while (find->next != sort)
		find = find->next;
	find->next = NULL;
	if (p == 1)
		ft_printf("rrb\n");
}
