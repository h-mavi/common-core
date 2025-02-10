/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   common_file.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfanelli <mfanelli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/10 10:03:09 by mfanelli          #+#    #+#             */
/*   Updated: 2025/02/10 10:30:17 by mfanelli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	handler(int sig)
{
	if (sig == SIGUSR1)
		write(1, "Photos brintet\n", 15);
	else if (sig == SIGUSR2)
		write(1, "wtf just heappend\n", 18);
	exit (0);
}

int	ft_recursive_power(int nb, int power)
{
	if (power == 0)
		return (1);
	if (power < 0)
		return (0);
	if (nb == 0)
		return (0);
	return (nb * ft_recursive_power(nb, power - 1));
}

int	print_str(pid_t pid, char *str, int *cur_bit_pos, int sig)
{
	static char	chara = 0;
	static int	i = 0;

	if (sig == SIGUSR1)
		chara += ft_recursive_power(2, (*cur_bit_pos));
	if (*cur_bit_pos == 7)
	{
		str[i++] = chara;
		*cur_bit_pos = 0;
		if (chara == 0)
		{
			i = 0;
			kill(pid, SIGUSR1);
			return (0);
		}
		chara = 0;
		return (1);
	}
	(*cur_bit_pos)++;
	return (1);
}
