/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_algorithm.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfanelli <mfanelli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/03 09:21:10 by mfanelli          #+#    #+#             */
/*   Updated: 2025/02/03 12:22:41 by mfanelli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	set_position(t_list **head)
{
	int		i;
	t_list	*tmp;
	int		mediana;

	i = 0;
	tmp = *head;
	mediana = ft_lslen(*head) / 2;
	while (tmp)
	{
		tmp->cur_position = i;
		if (i <= mediana)
			tmp->up_mediana = 1;
		else
			tmp->up_mediana = 0;
		tmp = tmp->next;
		++i;
	}
}

void	set_target(t_list **head_a, t_list **head_b)
{
	t_list	*tmp_a;
	t_list	*tmp_b;
	t_list	*target;
	long	best_index;

	tmp_b = *head_b;
	while(tmp_b)
	{
		best_index = LONG_MAX;;
		tmp_a = *head_a;
		while (tmp_a)
		{
			if (tmp_a->data > tmp_b->data && tmp_a->data < best_index)
			{
				best_index = tmp_a->data;
				target = tmp_a;
			}
			tmp_a = tmp_a->next;
		}
		if (best_index == LONG_MAX)
			tmp_b->target_node = smallest(head_a);
		else
			tmp_b->target_node = target;
		tmp_b = tmp_b->next;
	}
}

void	set_prince(t_list **head_a, t_list **head_b)
{
	int		len_a;
	int		len_b;
	t_list	*tmp_a;
	t_list	*tmp_b;

	len_a = ft_lslen(*head_a);
	len_b = ft_lslen(*head_b);
	tmp_a = *head_a;
	tmp_b = *head_b;
	while (tmp_b)
	{
		tmp_b->price = tmp_b->cur_position;
		if (!tmp_b->up_mediana)
			tmp_b->price = len_b - tmp_b->cur_position;
		if (tmp_b->target_node->up_mediana)
			tmp_b->price += tmp_b->target_node->cur_position;
		else
			tmp_b->price = len_a - tmp_b->target_node->cur_position;
		tmp_b = tmp_b->next;
	}
}

void	ft_prepare(t_list **head_a, t_list **head_b)
{
	set_position(head_a);
	set_position(head_b);
	set_target(head_a, head_b);
	set_prince(head_a, head_b);
	check_cheapest(head_b);
}

void	algorithm(t_list **head_a, t_list **head_b)
{
	t_list	*smol;
	int		i;

	while(ft_lslen(*head_a) != 5)
		pb_push_b(head_a, head_b);
	special_case_3(head_a, head_b);
	while (*head_b != NULL)
	{
		ft_prepare(head_a, head_b);
		ft_move_node(head_a, head_b);
	}
	set_position(head_a);
	smol = smallest(head_a);
	i = smol->data;
	if (smol->up_mediana)
		while((*head_a)->data != i)
			ra_rotate_a(head_a, 1);
	else
		while((*head_a)->data != i)
			rra_reverse_rotate_a(head_a, 1);
}