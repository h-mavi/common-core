/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfanelli <mfanelli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/24 10:14:26 by mfanelli          #+#    #+#             */
/*   Updated: 2025/01/28 10:46:03 by mfanelli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# include "./printf/ft_printf.h"
# include "./libft/libft.h"
# include <stdlib.h>
# include <stdio.h>
#include <unistd.h>

typedef struct s_list
{
	int				data;
	struct s_list	*next;
}	t_list;

//in main.c
void	rr_reverse_rotate_a_b(t_list **head_a, t_list **head_b);
void	print_lists(t_list *head_a, t_list *head_b);

//in push_swap_utils.c
long	ft_atol(const char *str);
t_list	*ft_lstnew(int content);
void	ft_lstadd_back(t_list **lst, t_list *new);
int		check_if_double(t_list *head);
t_list	*args_fill_list(int	argc, char *argv[]);

//in utils.c
void	ft_error(void);
void	ft_exit_free(t_list *head_a, t_list *head_b, int err);
void	free_array(char **array);
t_list	*split_str(char *argv[]);
void	ft_lstadd_front(t_list **lst, t_list *new);

//in operation.c
void	sa_swap_a(t_list *head);
void	sb_swap_b(t_list *head_b);
void	ss_swap_a_b(t_list *head_a, t_list *head_b);
void	pa_push_a(t_list **head_a, t_list **head_b);
void	pb_push_b(t_list **head_a, t_list **head_b);

//in still_operation.c
void	ra_rotate_a(t_list **head_a);
void	rb_rotate_b(t_list **head_b);
void	rr_rotate_a_b(t_list **head_a, t_list **head_b);
void	rra_reverse_rotate_a(t_list **head_a);
void	rrb_reverse_rotate_b(t_list **head_b);

//in algorithm_1.c

#endif