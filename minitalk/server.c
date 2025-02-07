/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfanelli <mfanelli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/05 14:35:50 by mfanelli          #+#    #+#             */
/*   Updated: 2025/02/07 10:30:38 by mfanelli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	count_len(int *cur_bit_pos, int *len_recived, char **str, int sig)
{
	static int	len = 0;

	if (sig == SIGUSR1)
		len += ft_recursive_power(2, *cur_bit_pos);
	if (*cur_bit_pos == 31)
	{
		*len_recived = 1;
		*str = (char *)malloc((len + 1) * sizeof(char));
		if (*str == NULL)
			return ;
		*cur_bit_pos = 0;
		len = 0;
		return ;
	}
	(*cur_bit_pos)++;
}

void	reset(int *len_recived, char **str, int *i)
{
	*len_recived = 0;
	if (*str)
	{
		ft_putendl_fd(*str, 1);
		free(*str);
		*str = 0;
	}
	*i = 0;
}

void	info_from_client(int sig)
{
	static int	len_recived = 0;
	static int	cur_bit_pos = 0;
	static int	i = 0;
	static char	chara = 0;
	static char	*str = 0;
	
	if(len_recived == 0)
		count_len(&cur_bit_pos, &len_recived, &str, sig);
	else
	{
		if (sig == SIGUSR1)
			chara += ft_recursive_power(2 ,cur_bit_pos);
		if (cur_bit_pos == 7)
		{
			str[i++] = chara;
			cur_bit_pos = 0;
			if (chara == 0)
				return (reset(&len_recived, &str, &i));
			chara = 0;
			return ;
		}
		cur_bit_pos++;
	}
}

int	main(void)
{
	ft_putnbr_fd((int)getpid(), 1);
	ft_putchar_fd('\n', 1);
	signal(SIGUSR1, info_from_client);
	signal(SIGUSR2, info_from_client);
	while(1)
		pause();
}
