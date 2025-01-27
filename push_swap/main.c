/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfanelli <mfanelli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/24 10:54:28 by mfanelli          #+#    #+#             */
/*   Updated: 2025/01/27 09:47:30 by mfanelli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int argc, char *argv[])
{
	t_list	*head;

	head = NULL;
	if (argc == 2 && ft_strlen(argv[1]) == 0)
		ft_exit();
	else if (argc == 2 && ft_strlen(argv[1]) > 0)
	{
		head = split_str(argv);
	}
	else if (argc > 2 || argc == 2)
		head = args_fill_list(argc, argv);
	if(!check_if_double(head))
		ft_exit();
}
