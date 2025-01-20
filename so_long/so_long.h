/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfanelli <mfanelli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/10 13:40:31 by mfanelli          #+#    #+#             */
/*   Updated: 2025/01/20 09:48:51 by mfanelli         ###   ########.fr       */
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
	char	**map_copy;
	int		num_col;
	int		num_lines;
	int		x;
	int		y;
	void	*img_player_front;
	void	*img_player_back;
	void	*img_player_left;
	void	*img_player_right;
	void	*img_end;
	void	*img_coin;
	void	*img_wall;
	void	*img_floor;
	int		coin_count;
}       t_vars;

//in main.c
void	put_img_in_win(t_vars *info, int x, int y);
int	lets_print(t_vars *info);
int	create_img(t_vars *info);
int	start(t_vars info);

//in so_long_utils.c
int	map_gen(t_vars *info, char *file);
int	map_pars(t_vars *info, char *file);
int	win_command(int keycode, t_vars *info);
int	close_with_x(t_vars *info);

//in error_map.c
int	check_file_valid(char *file);
int	check_char(char **map);
int	check_if_rectangular(char **map, size_t x, size_t y);
int	check_wall(char **map, t_vars *info);
int	check_if_atleast(char **map, t_vars *info);

//in check_map.c
int	how_many_cl(char *file);
int	get_l(char **map);
int	get_h(char **map);
int	check_floor_ceiling(char **map, int	x, int y);
int	check_precise(char **map, char c);

//in moves.c
int where_is_player(t_vars *info);
int up(t_vars *info);
int down(t_vars *info);
int left(t_vars *info);
int right(t_vars *info);

//in path_finder.c
int	map_copy(t_vars *info, char *file);
int free_copy(t_vars *info);
int flood_fill(char **map_copy, int x, int y);
int	check_path(t_vars *info, char *file);

#endif