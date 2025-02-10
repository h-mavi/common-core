/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   common_file.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfanelli <mfanelli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/10 10:03:09 by mfanelli          #+#    #+#             */
/*   Updated: 2025/02/10 10:05:14 by mfanelli         ###   ########.fr       */
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
