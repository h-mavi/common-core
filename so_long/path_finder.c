/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   path_finder.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfanelli <mfanelli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/20 09:09:57 by mfanelli          #+#    #+#             */
/*   Updated: 2025/01/20 10:29:19 by mfanelli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	map_copy(t_vars *info, char *file)
{
	int		i;
	int		index;
	char	*line;
	int		fd;

	i = 0;
	index = how_many_cl(file);
	info->map_copy = ft_calloc(index, sizeof(char *));
	fd = open(file, O_RDONLY);
	line = get_next_line(fd);
	if (fd < 0 || !line)
		return (0);
	while (line)
	{
		info->map_copy[i] = ft_calloc(ft_strlen(line) + 1, sizeof(char));
		ft_strlcpy(info->map_copy[i], line, ft_strlen(line) + 1);
		free(line);
		line = get_next_line(fd);
		i++;
	}
	close(fd);
	return (1);
}

int	free_copy(t_vars *info)
{
	int	i;

	i = 0;
	while (info->map_copy[i])
		free(info->map_copy[i++]);
	free(info->map_copy);
	return (1);
}

int	flood_fill(char **map_copy, int x, int y)
{
	if ((map_copy[y][x] == '1') || \
	(map_copy[y][x] == 'x'))
		return (0);
	map_copy[y][x] = 'x';
	flood_fill(map_copy, (x + 1), y);
	flood_fill(map_copy, (x - 1), y);
	flood_fill(map_copy, x, (y + 1));
	flood_fill(map_copy, x, (y - 1));
	return (1);
}

int	check_path(t_vars *info, char *file)
{
	int	y;
	int	x;

	if (!map_copy(info, file))
		return (0);
	where_is_player(info);
	x = info->x;
	y = info->y;
	flood_fill(info->map_copy, x, y);
	y = 0;
	while (info->map_copy[y])
	{
		x = 0;
		while (info->map_copy[y][x])
		{
			if (info->map_copy[y][x] != '1' && info->map_copy[y][x] != '0'\
			&& info->map_copy[y][x] != 'x' && info->map_copy[y][x] != '\n')
				return (0);
			x++;
		}
		y++;
	}
	free_copy(info);
	return (1);
}
