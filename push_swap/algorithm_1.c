/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algorithm_1.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfanelli <mfanelli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/28 09:24:56 by mfanelli          #+#    #+#             */
/*   Updated: 2025/01/29 10:46:36 by mfanelli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	is_it_sort(t_list *head_a)
{
	t_list	*tmp;	

	tmp = head_a;
	while(tmp != NULL && tmp->next != NULL) 
	{
		if (tmp->data > (tmp->next)->data)
			return (1);
		tmp = tmp->next;
	}
	return (0);
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
	// else if (len > 5)
	// 	algorithm(head_a, head_b);
}