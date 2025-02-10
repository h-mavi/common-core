/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfanelli <mfanelli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/05 14:35:50 by mfanelli          #+#    #+#             */
/*   Updated: 2025/02/10 10:30:23 by mfanelli         ###   ########.fr       */
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

void	reset(int *len, char **str, int *pid_recived, pid_t *pid)
{
	*len = 0;
	*pid_recived = 0;
	*pid = 0;
	if (*str)
	{
		ft_putendl_fd(*str, 1);
		free(*str);
		*str = 0;
	}
}

void	get_pid(int *pid_recived, pid_t *pid, int *cur_bit_pos, int sig)
{
	if (sig == SIGUSR1)
		*pid += ft_recursive_power(2, *cur_bit_pos);
	if (*cur_bit_pos == 31)
	{
		*pid_recived = 1;
		*cur_bit_pos = 0;
		return ;
	}
	(*cur_bit_pos)++;
}

void	info_from_client(int sig)
{
	static int		len_recived = 0;
	static int		pid_recived = 0;
	static pid_t	pid = 0;
	static int		cur_bit_pos = 0;
	static char		*str = 0;

	if (pid_recived == 0)
		get_pid(&pid_recived, &pid, &cur_bit_pos, sig);
	else if (len_recived == 0)
		count_len(&cur_bit_pos, &len_recived, &str, sig);
	else
	{
		if (!print_str(pid, str, &cur_bit_pos, sig))
			return (reset(&len_recived, &str, &pid_recived, &pid));
	}
}

int	main(void)
{
	ft_putnbr_fd((int)getpid(), 1);
	ft_putchar_fd('\n', 1);
	signal (SIGUSR1, info_from_client);
	signal (SIGUSR2, info_from_client);
	while (1)
		pause();
}
