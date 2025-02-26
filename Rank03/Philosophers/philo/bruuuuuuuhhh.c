/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bruuuuuuuhhh.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfanelli <mfanelli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/26 15:56:05 by mfanelli          #+#    #+#             */
/*   Updated: 2025/02/26 16:01:11 by mfanelli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	mother_fucking_daaamn(t_data *th)
{
	if (((*th).max_dinners != 0 && (*th).dinners < (*th).max_dinners && \
	is_someone_dead((*th).head_th) != 0) || ((*th).max_dinners == 0 && \
	is_someone_dead((*th).head_th) != 0))
		return (1);
	return (0);
}
