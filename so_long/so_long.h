/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfanelli <mfanelli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/10 13:40:31 by mfanelli          #+#    #+#             */
/*   Updated: 2025/01/14 10:26:19 by mfanelli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H
# define WIDTH 500
# define HEIGHT 500
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
}       t_vars;

int	close_with_x(t_vars *info);
int	close_with_esc(int keycode, t_vars *info);
int	map_gen(t_vars *info);
int	how_many_cl(void);
int	map_pars(t_vars *info);
int	check_char(char **map);
int	check_wall(char **map);
int	check_floor_ceiling(char **map, int	x, int y);
int	check_if_rectangular(char **map, size_t x, size_t y);
int	get_h(char **map);
int	get_l(char **map);

#endif