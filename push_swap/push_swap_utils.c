/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfanelli <mfanelli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/24 14:32:26 by mfanelli          #+#    #+#             */
/*   Updated: 2025/01/27 10:47:44 by mfanelli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

long	ft_atol(const char *str)
{
	int			i;
	long	num;
	int			sign;

	num = 0;
	i = 0;
	sign = 1;
	while (ft_iswhitespace(str[i]))
		i++;
	if (str[i] == '-')
	{
		sign = -1;
		i++;
	}
	while (str[i] != '\0' && ft_isdigit(str[i]))
		num = (num * 10) + (str[i++] - '0');
	num = num * sign;
	return (num);
}

t_list	*ft_lstnew(int content)
{
	t_list	*new;

	new = malloc(sizeof(t_list));
	if (new == NULL)
		return (NULL);
	new->data = content;
	new->next = NULL;
	return (new);
}

void	ft_lstadd_back(t_list **lst, t_list *new)
{
	t_list	*ex;

	ex = NULL;
	if (!new || !lst)
		return ;
	if (*lst && lst[0])
	{
		ex = *lst;
		while (ex->next != NULL)
			ex = ex->next;
		ex->next = new;
	}
	else
		*lst = new;
	return ;
}

int	check_if_double(t_list *head)
{
	t_list			*lst1;
	t_list			*lst2;

	lst1 = head;
	lst2 = head;
	while (lst1->next != NULL)
	{
		lst2 = lst2->next;
		if (lst2 != NULL && lst1->data == lst2->data)
			return (0);
		if (lst2 == NULL)
		{
			lst2 = lst1->next;
			lst1 = lst1->next;
		}
	}
	return (1);
}

t_list *args_fill_list(int	argc, char *argv[])
{
	int		i;
	int		x;
	long	num;
	t_list	*head;

	i = 0;
	head = NULL;
	while(++i < argc)
	{
		x = 0;
		while (argv[i][x] != '\0')
		{
			if (x == 0 && (argv[i][0] == '+' || argv[i][0] == '-'))
				x++;
			if (!ft_isdigit(argv[i][x++]))
				ft_exit();
		}
		num = ft_atol(argv[i]);
		if (num > 2147483647 || num < -2147483648)
			ft_exit();
		ft_lstadd_back(&head, ft_lstnew(num));
	}
	return (head);
}
