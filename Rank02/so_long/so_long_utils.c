/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfanelli <mfanelli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/10 13:44:56 by mfanelli          #+#    #+#             */
/*   Updated: 2025/01/21 09:53:25 by mfanelli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	map_gen(t_vars *info, char *file)
{
	int		i;
	int		index;
	char	*line;
	int		fd;

	i = 0;
	index = how_many_cl(file);
	info->map = ft_calloc(index, sizeof(char *));
	fd = open(file, O_RDONLY);
	line = get_next_line(fd);
	if (fd < 0 || !line)
		return (0);
	while (line)
	{
		info->map[i] = ft_calloc(ft_strlen(line) + 1, sizeof(char));
		ft_strlcpy(info->map[i], line, ft_strlen(line) + 1);
		free(line);
		line = get_next_line(fd);
		i++;
	}
	close(fd);
	if (!map_pars(info, file))
		return (0);
	return (1);
}

int	map_pars(t_vars *info, char *file)
{
	if (!check_char(info->map))
		return (0);
	if (!check_wall(info->map, info))
		return (0);
	if (!check_if_atleast(info->map, info))
		return (0);
	if (!check_path(info, file))
	{
		ft_printf("Error\n[invalid path]\nno possible path");
		return (0);
	}
	return (1);
}

int	win_command(int keycode, t_vars *info)
{
	if (keycode == 119)
		up(info);
	else if (keycode == 97)
		left(info);
	else if (keycode == 115)
		down(info);
	else if (keycode == 100)
		right(info);
	else if (keycode == 65307)
		close_with_x(info);
	return (1);
}

int	close_with_x(t_vars *info)
{
	int	i;

	ft_printf("Bye Bye");
	i = 0;
	while (info->map[i])
		free(info->map[i++]);
	free(info->map);
	mlx_destroy_image(info->mlx, info->img_coin);
	mlx_destroy_image(info->mlx, info->img_player_front);
	mlx_destroy_image(info->mlx, info->img_player_back);
	mlx_destroy_image(info->mlx, info->img_player_left);
	mlx_destroy_image(info->mlx, info->img_player_right);
	mlx_destroy_image(info->mlx, info->img_end);
	mlx_destroy_image(info->mlx, info->img_wall);
	mlx_destroy_image(info->mlx, info->img_floor);
	mlx_destroy_window(info->mlx, info->win);
	mlx_destroy_display(info->mlx);
	free(info->mlx);
	exit (0);
}

// void print_matrix(t_vars *info, char **map)
// {
// 	int j;
// 	int i;
// 	int len;

// 	j = 0;
// 	len = get_h(info->map);
// 	ft_printf("matrix: \n");
// 	while (j < len + 1)
// 	{
// 		i = 0;
// 		while (i < (int)ft_strlen(map[0]))
// 		{
// 			ft_printf("%c ", map[j][i]);
// 			i++;
// 		}
// 		ft_printf("\n");
// 		j++;
// 	}
// 	ft_printf("\n");
// }
