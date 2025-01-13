/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfanelli <mfanelli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/13 10:45:22 by mfanelli          #+#    #+#             */
/*   Updated: 2025/01/13 13:25:49 by mfanelli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	check_char(char **map)
{
	int	i;
	int	y;

	i = 0;
	y = 0;
	while(map[i])
	{
		while(map[i][y] && map[i][y] != '\n')
		{
			if (map[i][y] != 'E' && map[i][y] != 'P' && map[i][y] != '0' \
				&& map[i][y] != 'C' && map[i][y] != '1')
			{
				ft_printf("Error\n[invalid character found]");
				return (0);
			}
			y++;
		}
		y = 0;
		i++;
	}
	return(1);
}

int	get_l(char **map)
{
	size_t	i;
	size_t	x;

	i = 0;
	x = 0;
	if (!map || !map[i])
		return (0);
	while(map[i][x])
		x++;
	while(map[i])
	{
		if (map[i][0] == '\n' || map[i][0] == '\0')
			return(0);
		i++;
	}
	return(x);
}

int	get_h(char **map)
{
	int	i;

	i = 0;
	if (!map)
		return (0);
	while(map[i])
		i++;
	return(i);
}

int	check_wall(char **map)
{
	int	i;
	int	x;
	int	y;

	i = 1;
	x = get_l(map);
	y = get_h(map);
	while(map[i] && i < y)
	{
		if(map[i][0] != '1' || map[i][x] != '1')
		{
			ft_printf("Error\n[map wall]");
			return(0);
		}
		i++;
	}
	i = 0;
	while(map[0] && map[y])
	{
		if(map[0][i] != '1' || map[y][i] != '1')
		{
			ft_printf("Error\n[map wall]");
			return(0);
		}
		i++;
	}
	return (1);
}
