/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bruh.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfanelli <mfanelli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/13 11:12:53 by mfanelli          #+#    #+#             */
/*   Updated: 2025/03/17 09:57:58 by mfanelli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	*ft_calloc(size_t nmemb, size_t size)
{
	void	*str;

	str = malloc(nmemb * size);
	if (!str)
		return (NULL);
	ft_bzero(str, size * nmemb);
	return (str);
}

void	create_thread(t_philo *th, int i)
{
	pthread_t	thanos;

	while (++i < th[0].gen->num_philos)
	{
		if (th[i].whoami % 2 == 0)
			usleep(1000);
		if (pthread_create(&th[i].filo, NULL, &routine, (void *)&th[i]) != 0)
			return ;
	}
	if (pthread_create(&thanos, NULL, &check_death, (void *)&th) != 0)
		return ;
	i = -1;
	while (++i < th[0].gen->num_philos)
	{
		if (pthread_join(th[i].filo, NULL) != 0)
			return ;
	}
	if (pthread_join(thanos, NULL) != 0)
		return ;
}
