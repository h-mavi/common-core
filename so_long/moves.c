/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfanelli <mfanelli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/16 15:51:43 by mfanelli          #+#    #+#             */
/*   Updated: 2025/01/20 17:22:44 by mfanelli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	where_is_player(t_vars *info)
{
	int	x;
	int	y;

	x = 0;
	y = 0;
	while (info->map[y])
	{
		while (info->map[y][x])
		{
			if (info->map[y][x] == 'P')
			{
				info->x = x;
				info->y = y;
				return (1);
			}
			x++;
		}
		x = 0;
		y++;
	}
	return (0);
}

int	up(t_vars *info)
{
	int	y;
	int	x;

	where_is_player(info);
	y = info->y;
	x = info->x;
	if (info->map[y - 1][x] == 'C' || info->map[y - 1][x] == '0'\
	|| info->map[y - 1][x] == 'E')
	{
		if (info->map[y - 1][x] == 'C')
			info->coin_count--;
		if (info->map[y - 1][x] == 'E' && info->coin_count == 0)
			close_with_x(info);
		else if (info->map[y - 1][x] == 'E' && info->coin_count != 0)
			return (0);
		info->map[y - 1][x] = 'P';
		info->map[y][x] = '0';
		mlx_put_image_to_window(info->mlx, info->win, info->img_player_back, \
		x * MAP, (y - 1) * MAP);
		mlx_put_image_to_window(info->mlx, info->win, info->img_floor, \
		x * MAP, y * MAP);
		info->count_move = info->count_move + 1;
		ft_printf("Move nb = %d\n", info->count_move);
	}
	return (1);
}

int	down(t_vars *info)
{
	int	y;
	int	x;

	where_is_player(info);
	y = info->y;
	x = info->x;
	if (info->map[y + 1][x] == 'C' || info->map[y + 1][x] == '0'\
	|| info->map[y + 1][x] == 'E')
	{
		if (info->map[y + 1][x] == 'C')
			info->coin_count--;
		if (info->map[y + 1][x] == 'E' && info->coin_count == 0)
			close_with_x(info);
		else if (info->map[y + 1][x] == 'E' && info->coin_count != 0)
			return (0);
		info->map[y + 1][x] = 'P';
		info->map[y][x] = '0';
		mlx_put_image_to_window(info->mlx, info->win, info->img_player_front, \
		x * MAP, (y + 1) * MAP);
		mlx_put_image_to_window(info->mlx, info->win, info->img_floor, \
		x * MAP, y * MAP);
		info->count_move = info->count_move + 1;
		ft_printf("Move nb = %d\n", info->count_move);
	}
	return (1);
}

int	left(t_vars *info)
{
	int	y;
	int	x;

	where_is_player(info);
	y = info->y;
	x = info->x;
	if (info->map[y][x - 1] == 'C' || info->map[y][x - 1] == '0'\
	|| info->map[y][x - 1] == 'E')
	{
		if (info->map[y][x - 1] == 'C')
			info->coin_count--;
		if (info->map[y][x - 1] == 'E' && info->coin_count == 0)
			close_with_x(info);
		else if (info->map[y][x - 1] == 'E' && info->coin_count != 0)
			return (0);
		info->map[y][x - 1] = 'P';
		info->map[y][x] = '0';
		mlx_put_image_to_window(info->mlx, info->win, info->img_player_left, \
		(x - 1) * MAP, y * MAP);
		mlx_put_image_to_window(info->mlx, info->win, info->img_floor, \
		x * MAP, y * MAP);
		info->count_move = info->count_move + 1;
		ft_printf("Move nb = %d\n", info->count_move);
	}
	return (1);
}

int	right(t_vars *info)
{
	int	y;
	int	x;

	where_is_player(info);
	y = info->y;
	x = info->x;
	if (info->map[y][x + 1] == 'C' || info->map[y][x + 1] == '0'\
	|| info->map[y][x + 1] == 'E')
	{
		if (info->map[y][x + 1] == 'C')
			info->coin_count--;
		if (info->map[y][x + 1] == 'E' && info->coin_count == 0)
			close_with_x(info);
		else if (info->map[y][x + 1] == 'E' && info->coin_count != 0)
			return (0);
		info->map[y][x + 1] = 'P';
		info->map[y][x] = '0';
		mlx_put_image_to_window(info->mlx, info->win, info->img_player_right, \
		(x + 1) * MAP, y * MAP);
		mlx_put_image_to_window(info->mlx, info->win, info->img_floor, \
		x * MAP, y * MAP);
		info->count_move = info->count_move + 1;
		ft_printf("Move nb = %d\n", info->count_move);
	}
	return (1);
}
