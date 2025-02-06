/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfanelli <mfanelli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/05 14:35:50 by mfanelli          #+#    #+#             */
/*   Updated: 2025/02/06 18:15:40 by mfanelli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

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

void	count_len(int *cur_bit_pos, int *len_recived, char **str, int sig)
{
	static int	len = 0;

	if (sig == SIGUSR1)
		len += ft_recursive_power(2, *cur_bit_pos);
	if (*cur_bit_pos == 31)
	{
		*len_recived = 1;
		*str = (char *)ft_calloc(len + 1, sizeof(char));
		cur_bit_pos = 0;
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
		// ft_putendl_fd(*str, 1);
		// ft_putchar_fd('\n', 1);
		printf("jesus");
		free(*str);
		*str = 0;
	}
	*i = 0;
}

void	recive_from_client(int sig)
{
	static int	len_recived = 0;
	static int	cur_bit_pos = 0;
	static int	i = 0;
	static int	chara = 0;
	static char	*str = 0;
	
	if(!len_recived)
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

/* int	main(void)
{
	ft_printf("%d\n", getpid());
struct sigaction action;
	action.sa_handler = recive_from_client;
	sigemptyset(&action.sa_mask);
	action.sa_flags = 0;

	sigaction(SIGUSR1, &action, NULL);
	sigaction(SIGUSR2, &action, NULL);
	while(1)
		pause();
} */

int	main(void)
{
	ft_putnbr_fd((int)getpid(), 1);
	ft_putchar_fd('\n', 1);
	signal(SIGUSR1, recive_from_client);
	signal(SIGUSR2, recive_from_client);
	while(1)
		pause();
}
