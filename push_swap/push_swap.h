/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfanelli <mfanelli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/24 10:14:26 by mfanelli          #+#    #+#             */
/*   Updated: 2025/01/27 09:27:59 by mfanelli         ###   ########.fr       */
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

t_list	*ft_lstnew(int content);
t_list	*args_fill_list(int	argc, char *argv[]);
int		check_if_double(t_list *head);
long	ft_atol(const char *str);
void	ft_exit();
void	ft_lstadd_back(t_list **lst, t_list *new);

#endif