/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ma_che_cazz.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfanelli <mfanelli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/06 17:37:40 by mfanelli          #+#    #+#             */
/*   Updated: 2025/02/06 18:11:11 by mfanelli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void    handler(int sig)
{
    if (sig == SIGUSR1)
        printf("1\n");
    else if (sig == SIGUSR2)
        printf("0\n");
}

int main(void)
{
    printf("PID = %d\n", (int)getpid());
    signal(SIGUSR1, handler);
    signal(SIGUSR2, handler);
    while (1)
        pause();
}
