/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfanelli <mfanelli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/13 10:45:22 by mfanelli          #+#    #+#             */
/*   Updated: 2025/01/21 10:19:38 by mfanelli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	check_file_valid(char *file)
{
	int		i;
	char	*str;
	int		fd;

	i = 0;
	fd = open(file, O_RDONLY);
	if (fd < 0 || !file)
	{
		close(fd);
		ft_printf("Error\n[no map]\nwhat da fuck is <%s>?", file);
		return (0);
	}
	close(fd);
	str = ft_strchr(file, '.');
	if (!str)
	{
		ft_printf("Error\n[invalid map file]\nwhat da fuck is <%s>?", file);
		return (0);
	}
	if (str[0] == '.' && str[1] == 'b' && str[2] == 'e' && str[3] == 'r' \
	&& str[4] == '\0')
		return (1);
	ft_printf("Error\n[invalid map file]\nwhat da fuck is <%s>?", file);
	return (0);
}

int	check_char(char **map)
{
	int	i;
	int	y;

	i = 0;
	y = 0;
	while (map[i])
	{
		while (map[i][y] && map[i][y] != '\n')
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
	return (1);
}

int	check_if_rectangular(char **map, size_t x, size_t y)
{
	size_t	i;

	i = 0;
	while (map[++i] != NULL && i < y)
	{
		if (x != (ft_strlen(map[i]) - 2))
		{
			ft_printf("Error\n[wall is not rectangular]");
			return (0);
		}
	}
	if (x != (ft_strlen(map[y]) - 1))
	{
		ft_printf("Error\n[wall is not rectangular]");
		return (0);
	}
	return (1);
}

int	check_wall(char **map, t_vars *info)
{
	size_t	i;
	size_t	x;
	size_t	y;

	i = 1;
	x = get_l(map);
	y = get_h(map);
	info->num_lines = x;
	info->num_col = y;
	if (!check_if_rectangular(map, x, y))
		return (0);
	while (map[i] && i < y)
	{
		if (map[i][0] != '1' || map[i][x] != '1')
		{
			ft_printf("Error\n[map wall] type 1\ninvalid wall");
			return (0);
		}
		i++;
	}
	if (!check_floor_ceiling(map, x, y))
		return (0);
	return (1);
}

int	check_if_atleast(char **map, t_vars *info)
{
	char	p;
	char	e;
	char	c;

	p = 'P';
	e = 'E';
	c = 'C';
	p = check_precise(map, p);
	e = check_precise(map, e);
	c = check_precise(map, c);
	info->coin_count = c;
	if (p != 1 || e != 1 || c <= 0)
	{
		ft_printf("Error\n[too few or too many characters]");
		return (0);
	}
	return (1);
}
