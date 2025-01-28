/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfanelli <mfanelli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/24 10:54:28 by mfanelli          #+#    #+#             */
/*   Updated: 2025/01/28 10:39:10 by mfanelli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	print_lists(t_list *head_a, t_list *head_b)
{
	ft_printf("---------------------\nStack A:\n");
	while (head_a != NULL)
	{
		ft_printf("%d\n", head_a->data);
		head_a = head_a->next;
	}
	ft_printf("Stack B:\n");
	while (head_b != NULL)
	{
		ft_printf("%d\n", head_b->data);
		head_b = head_b->next;
	}
}

int	main(int argc, char *argv[])
{
	t_list	*head_a;
	t_list	*head_b;

	head_a = NULL;
	head_b = NULL;
	if (argc == 2 && ft_strlen(argv[1]) == 0)
		ft_error();
	else if (argc == 2 && ft_strlen(argv[1]) > 0)
		head_a = split_str(argv);
	else if (argc > 2 || argc == 2)
		head_a = args_fill_list(argc, argv);
	if(!check_if_double(head_a))
		ft_exit_free(head_a, head_b, -1);
	print_lists(head_a, head_b);
	pb_push_b(&head_a, &head_b);
	pb_push_b(&head_a, &head_b);
	print_lists(head_a, head_b);
	pa_push_a(&head_a, &head_b);
	pa_push_a(&head_a, &head_b);
	print_lists(head_a, head_b);
	ft_exit_free(head_a, head_b, 0);
}
