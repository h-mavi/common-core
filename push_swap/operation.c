/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operation.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfanelli <mfanelli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/24 10:40:38 by mfanelli          #+#    #+#             */
/*   Updated: 2025/01/28 11:09:15 by mfanelli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sa_swap_a(t_list *head_a)
{
	int		i;
	t_list	*sort;

	i = -1;
	sort = head_a;
	while (sort != NULL && ++i != -1)
		sort = sort->next;
	if (i < 2)
		return ;
	sort = head_a->next;
	i = head_a->data;
	head_a->data = sort->data;
	sort->data = i;
}

void	sb_swap_b(t_list *head_b)
{
	int		i;
	t_list	*sort;

	i = -1;
	sort = head_b;
	while (sort != NULL && ++i != -1)
		sort = sort->next;
	if (i < 2)
		return ;
	sort = head_b->next;
	i = head_b->data;
	head_b->data = sort->data;
	sort->data = i;
}

void	ss_swap_a_b(t_list *head_a, t_list *head_b)
{
	sa_swap_a(head_a);
	sb_swap_b(head_b);
}

void	pa_push_a(t_list **head_a, t_list **head_b)
{
	t_list	*sort;

	if (*head_b == NULL)
		return ;
	sort = *head_b;
	*head_b = (*head_b)->next;
	ft_lstadd_front(head_a, ft_lstnew(sort->data));
	free(sort);
}

void	pb_push_b(t_list **head_a, t_list **head_b)
{
	t_list	*sort;

	if (*head_a == NULL)
		return ;
	sort = *head_a;
	*head_a = (*head_a)->next;
	ft_lstadd_front(head_b, ft_lstnew(sort->data));
	free(sort);
}
