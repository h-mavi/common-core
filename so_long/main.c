/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfanelli <mfanelli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/10 11:57:19 by mfanelli          #+#    #+#             */
/*   Updated: 2025/01/20 10:23:47 by mfanelli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	put_img_in_win(t_vars *info, int x, int y)
{
	if (info->map[y][x] != '\0' && info->map[y][x] == 'P')
		mlx_put_image_to_window(info->mlx, info->win, info->img_player_front, \
		x * MAP, y * MAP);
	else if (info->map[y][x] != '\0' && info->map[y][x] == 'E')
		mlx_put_image_to_window(info->mlx, info->win, info->img_end, \
		x * MAP, y * MAP);
	else if (info->map[y][x] != '\0' && info->map[y][x] == 'C')
		mlx_put_image_to_window(info->mlx, info->win, info->img_coin, \
		x * MAP, y * MAP);
	else if (info->map[y][x] != '\0' && info->map[y][x] == '1')
		mlx_put_image_to_window(info->mlx, info->win, info->img_wall, \
		x * MAP, y * MAP);
	else if (info->map[y][x] != '\0' && info->map[y][x] == '0')
		mlx_put_image_to_window(info->mlx, info->win, info->img_floor, \
		x * MAP, y * MAP);
}

int	lets_print(t_vars *info)
{
	int	x;
	int	y;

	x = 0;
	y = 0;
	while (info->map[y])
	{
		while (info->map[y][x])
		{
			put_img_in_win(info, x, y);
			x++;
		}
		x = 0;
		y++;
	}
	return (1);
}

int	create_img(t_vars *info)
{
	int		i;

	i = 32;
	info->img_player_front = mlx_xpm_file_to_image(info->mlx, \
	"./textures/player_32x32_front.xpm", &i, &i);
	info->img_player_back = mlx_xpm_file_to_image(info->mlx, \
	"./textures/player_32x32_back.xpm", &i, &i);
	info->img_player_left = mlx_xpm_file_to_image(info->mlx, \
	"./textures/player_32x32_left.xpm", &i, &i);
	info->img_player_right = mlx_xpm_file_to_image(info->mlx, \
	"./textures/player_32x32_right.xpm", &i, &i);
	info->img_end = mlx_xpm_file_to_image(info->mlx, \
	"./textures/end_save_32x32.xpm", &i, &i);
	info->img_coin = mlx_xpm_file_to_image(info->mlx, \
	"./textures/coin_heartshapeobject_32x32.xpm", &i, &i);
	info->img_wall = mlx_xpm_file_to_image(info->mlx, \
	"./textures/wall_stone_32x32.xpm", &i, &i);
	info->img_floor = mlx_xpm_file_to_image(info->mlx, \
	"./textures/floor0_32x32.xpm", &i, &i);
	return (1);
}

int	start(t_vars info)
{
	info.mlx = mlx_init();
	if (info.mlx == NULL)
		return (1);
	info.win = mlx_new_window(info.mlx, ((info.num_lines + 1) * MAP), \
	((info.num_col + 1) * MAP), "lil hooman");
	create_img(&info);
	lets_print(&info);
	mlx_key_hook(info.win, win_command, &info);
	mlx_hook(info.win, 17, 1L << 0, close_with_x, &info);
	mlx_loop(info.mlx);
	return (1);
}

int	main(int argc, char *argv[])
{
	int		i;
	t_vars	info;

	i = 0;
	(void)argc;
	if (!check_file_valid(argv[1]))
		return (0);
	if (!map_gen(&info, argv[1]))
	{
		while (info.map[i])
			free(info.map[i++]);
		free(info.map);
		return (0);
	}
	start(info);
}
