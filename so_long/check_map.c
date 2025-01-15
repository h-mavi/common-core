/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wall.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfanelli <mfanelli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/14 09:55:30 by mfanelli          #+#    #+#             */
/*   Updated: 2025/01/15 16:51:07 by mfanelli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	how_many_cl(void)
{
	int		index;
	int		fd;
	char	*line;

	index = 1;
	fd = open("map.ber", O_RDONLY);
	if (fd < 0)
		return (1);
	line = get_next_line(fd);
	while(line)
	{
		free(line);
		line = get_next_line(fd);
		index++;
	}
	close(fd);
	return(index);
}

int	get_l(char **map)
{
	size_t	i;
	size_t	x;

	i = 0;
	x = 0;
	if(!map || !map[i])
		return(0);
	while((map[i][x] != '\0' || map[i][x] != '\n') && map[i][x])
		x++;
	while(map[i])
	{
		if(map[i][0] == '\n' || map[i][0] == '\0')
			return(0);
		i++;
	}
	return(x - 2); //compenso che gli indici iniziano da 0 e il \0
}

int	get_h(char **map)
{
	int	y;

	y = 0;
	if (!map)
		return (0);
	while(map[y] != NULL)
		y++;
	return(y - 1); //compenso che gli indici iniziano da 0
}

int	check_floor_ceiling(char **map, int	x, int y)
{
	int	i;
	
	i = 0;
	while(map[0] && map[y] && i <= x)
	{
		if(map[0][i] != '1' || map[y][i] != '1')
		{
			ft_printf("Error\n[map wall] type 2\ninvalid floor and ceiling");
			return(0);
		}
		i++;
	}
	return (1);
}

int	check_precise(char **map, char c)
{
	int	i;
	int	x;
	int	count;

	i = 0;
	x = 0;
	count = 0;
	while(map[i])
	{
		while(map[i][x])
		{
			if(map[i][x] == c)
				count++;
			x++;
		}
		x = 0;
		i++;
	}
	return(count);
}

