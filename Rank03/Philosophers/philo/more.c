/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   more.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfanelli <mfanelli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/25 11:28:43 by mfanelli          #+#    #+#             */
/*   Updated: 2025/02/25 11:36:08 by mfanelli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

long long	get_curr_time(void)
{
	long long		tmp;
	struct timeval	tv;

	tmp = 0;
	gettimeofday(&tv, NULL);
	tmp = ((tv.tv_sec * 1000) + (tv.tv_usec / 1000));
	return (tmp);
}
