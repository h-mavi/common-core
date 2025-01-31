/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfanelli <mfanelli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/24 10:54:28 by mfanelli          #+#    #+#             */
/*   Updated: 2025/01/29 15:04:09 by mfanelli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	must_be_smaller(t_list **head_a)
{
	int		smol;
	t_list	*tmp;

	tmp = *head_a;
	smol = tmp->data;
	tmp = tmp->next;
	while(tmp)
	{
		if (smol> tmp->data)
			return (0);
		tmp = tmp->next;
	}
	return (1);
}

void	rr_reverse_rotate_a_b(t_list **head_a, t_list **head_b)
{
	rra_reverse_rotate_a(head_a, 0);
	rrb_reverse_rotate_b(head_b, 0);
	ft_printf("rr\n");
}

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
	ft_printf("---------------------\n");
}

int	ft_lslen(t_list *head_a)
{
	int		i;
	t_list	*tmp;

	i = 0;
	tmp = head_a;
	while(tmp != NULL)
	{
		i++;
		tmp = tmp->next;
	}
	return (i);
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
	if (!is_it_sort(head_a))
	{
		ft_printf("Before sorting:\n");
		print_lists(head_a, head_b);
		sorting(&head_a, &head_b, ft_lslen(head_a));
		ft_printf("---------------------\nAfter sorting:\n");
		print_lists(head_a, head_b);
	}
	if (is_it_sort(head_a))
		ft_exit_free(head_a, head_b, 0);
}
