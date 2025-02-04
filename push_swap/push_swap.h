/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfanelli <mfanelli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/24 10:14:26 by mfanelli          #+#    #+#             */
/*   Updated: 2025/02/03 14:29:08 by mfanelli         ###   ########.fr       */
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
	int				up_mediana;
	int				cur_position;
	struct s_list	*target_node;
	int				price;
	int				is_cheapest;
}	t_list;

//in main.c
int		must_be_smaller(t_list **head_a);
void	rr_reverse_rotate_a_b(t_list **head_a, t_list **head_b);
void	print_lists(t_list *head_a, t_list *head_b);
int		ft_lslen(t_list *head_a);

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

//in bruh.c
void	ft_out(char **save, t_list *head);
t_list	*find_cheapest(t_list **head);
void	finish_r(t_list **head, t_list *top_node, char	ls);

//in operation.c
void	sa_swap_a(t_list *head_a, int p);
void	sb_swap_b(t_list *head_b, int p);
void	ss_swap_a_b(t_list *head_a, t_list *head_b);
void	pa_push_a(t_list **head_a, t_list **head_b);
void	pb_push_b(t_list **head_a, t_list **head_b);

//in still_operation.c
void	ra_rotate_a(t_list **head_a, int p);
void	rb_rotate_b(t_list **head_b, int p);
void	rr_rotate_a_b(t_list **head_a, t_list **head_b);
void	rra_reverse_rotate_a(t_list **head_a, int p);
void	rrb_reverse_rotate_b(t_list **head_b, int p);

//in algorithm_1.c
void	ft_move_node(t_list **head_a, t_list **head_b);
void	check_cheapest(t_list **head_b);
t_list	*smallest(t_list **head);
int		is_it_sort(t_list *head_a);
void	sorting(t_list **head_a, t_list **head_b, int len);

//in special_cases.c
void	special_case_0(t_list **head_a);
void	special_case_1(t_list **head_a);
void	special_case_2(t_list **head_a,t_list **head_b);
void	special_case_3(t_list **head_a,t_list **head_b);

//in ft_algorithm.c
void	set_position(t_list **head);
void	set_target(t_list **head_a, t_list **head_b);
void	set_prince(t_list **head_a, t_list **head_b);
void	ft_prepare(t_list **head_a, t_list **head_b);
void	algorithm(t_list **head_a, t_list **head_b);

#endif