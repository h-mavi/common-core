/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbrhex_MAX.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfanelli <mfanelli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/02 10:06:35 by mfanelli          #+#    #+#             */
/*   Updated: 2024/12/02 11:16:02 by mfanelli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_put_nbr_str_MAX(int *str)
{
	int	k;

	k = 0;
	while (str[k])
		write(1, &str[k++], 1);
	return ;
}

void	ft_rev_int_tab_MAX(int *tab, int size)
{
	int	count;
	int	c;

	count = 0;
	while (count < size / 2)
	{
		c = tab[count];
		tab[count] = tab[size - 1 - count];
		tab[size - 1 - count] = c;
		count++;
	}
	tab[size] = '\0';
	ft_put_nbr_str_MAX(tab);
	return ;
}

void	ft_putnbrhex_MAX(int nbr)
{
    int	    i;
	int	    j;
	int 	ris[1000000];
	unsigned int	ex;
    char    *hex;

	i = 16;
	j = 0;
	ex = nbr;
    hex = "0123456789ABCDEF";
	if (ex == 0)
		write(1, "0", 1);
    while (ex != 0 && hex[0] != '\0' && ex > 0)
	{
		ris[j++] = hex[ex % i];
		ex /= i;
	}
    ft_rev_int_tab_MAX(ris, j);
}