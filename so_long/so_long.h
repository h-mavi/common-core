/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfanelli <mfanelli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/10 13:40:31 by mfanelli          #+#    #+#             */
/*   Updated: 2025/01/16 17:39:44 by mfanelli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H
# define MAP 32
# include "./printf/ft_printf.h"
# include "./libft/libft.h"
# include "./minilibx-linux/mlx.h"
# include <X11/X.h>
# include <X11/keysym.h>
# include <stdlib.h>
# include <stdio.h>

typedef struct	s_vars
{
	void	*mlx;
	void	*win;
	char    **map;
	int		num_col;
	int		num_lines;
	int		x;
	int		y;
	void	*img_player;
	void	*img_end;
	void	*img_coin;
	void	*img_wall;
	void	*img_floor;
	int		coin_count;
}       t_vars;

int	start(t_vars info);
int	check_file_valid(char *file);
int	close_with_x(t_vars *info);
int	map_gen(t_vars *info, char *file);
int	how_many_cl(char *file);
int	map_pars(t_vars *info);
int	check_char(char **map);
int	check_wall(char **map, t_vars *info);
int	check_floor_ceiling(char **map, int	x, int y);
int	check_if_rectangular(char **map, size_t x, size_t y);
int	get_h(char **map);
int	get_l(char **map);
int	check_precise(char **map, char c);
int	check_if_atleast(char **map, t_vars *info);
int	lets_print(t_vars *info);
void	put_img_in_win(t_vars *info, int x, int y);
int	win_command(int keycode, t_vars *info);
int where_is_player(t_vars *info);
int up(t_vars *info);
int down(t_vars *info);
int left(t_vars *info);
int right(t_vars *info);

#endif