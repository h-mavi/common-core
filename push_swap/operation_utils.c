/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operation_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfanelli <mfanelli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/28 09:24:56 by mfanelli          #+#    #+#             */
/*   Updated: 2025/01/28 09:26:30 by mfanelli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rr_reverse_rotate_a_b(t_list **head_a, t_list **head_b)
{
	rra_reverse_rotate_a(head_a);
	rrb_reverse_rotate_b(head_b);
}