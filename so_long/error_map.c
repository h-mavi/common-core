/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfanelli <mfanelli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/13 10:45:22 by mfanelli          #+#    #+#             */
/*   Updated: 2025/01/14 10:25:55 by mfanelli         ###   ########.fr       */
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
				ft_printf("Error\n[invalid character]\nwhat da fuck is <%c>?"\
				, map[i][y]);
				return (0);
			}
			y++;
		}
		y = 0;
		i++;
	}
	return(1);
}

int	check_wall(char **map)
{
	size_t	i;
	size_t	x;
	size_t	y;

	i = 1;
	x = get_l(map);
	y = get_h(map); 
	if (!check_if_rectangular(map, x, y))
		return(0);
	while(map[i] && i < y)
	{
		if(map[i][0] != '1' || map[i][x] != '1')
		{
			ft_printf("Error\n[map wall] type 1\ninvalid wall");
			return(0);
		}
		i++;
	}
	if (!check_floor_ceiling(map, x, y))
		return(0);
	return (1);
}
