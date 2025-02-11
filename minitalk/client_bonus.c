/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfanelli <mfanelli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/05 14:35:48 by mfanelli          #+#    #+#             */
/*   Updated: 2025/02/11 09:06:27 by mfanelli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk_bonus.h"

int	ft_check_errors(int argc, char *argv[])
{
	int	i;

	if (argc != 3)
		return (0);
	i = -1;
	while (argv[1][++i])
	{
		if (!ft_strchr("0123456789", argv[1][i]))
			return (0);
	}
	return (1);
}

void	ft_send_strlen(pid_t pid, int len)
{
	int	i;

	i = -1;
	while (++i < 32)
	{
		if (len & 0X01)
			kill(pid, SIGUSR1);
		else
			kill(pid, SIGUSR2);
		len = len >> 1;
		usleep(EPPY);
	}
}

void	ft_send_str(pid_t pid, char c)
{
	int	i;

	i = -1;
	while (++i < 8)
	{
		if (c & 0X01)
			kill(pid, SIGUSR1);
		else
			kill(pid, SIGUSR2);
		c = c >> 1;
		usleep(EPPY);
	}
}

void	ft_send_pid(pid_t pid, pid_t clie_pid)
{
	int	i;

	i = -1;
	while (++i < 32)
	{
		if (clie_pid & 0X01)
			kill(pid, SIGUSR1);
		else
			kill(pid, SIGUSR2);
		clie_pid = clie_pid >> 1;
		usleep(EPPY);
	}
}

int	main(int argc, char *argv[])
{
	pid_t	pid;
	pid_t	clie_pid;
	int		i;

	signal(SIGUSR1, handler);
	signal(SIGUSR2, handler);
	if (!ft_check_errors(argc, argv))
		return (1);
	pid = ft_atoi(argv[1]);
	if (pid <= 0)
		return (1);
	clie_pid = getpid();
	ft_send_pid(pid, clie_pid);
	ft_send_strlen(pid, ft_strlen(argv[2]));
	i = -1;
	while (argv[2][++i])
		ft_send_str(pid, argv[2][i]);
	ft_send_str(pid, argv[2][i]);
	while (1)
		pause();
}
