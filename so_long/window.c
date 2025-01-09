/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tests.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfanelli <mfanelli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/08 16:29:42 by mfanelli          #+#    #+#             */
/*   Updated: 2025/01/09 08:57:04 by mfanelli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./minilibx-linux/mlx.h"
#include <stdlib.h>

typedef struct	s_vars
{
	void	*mlx;
	void	*win;
}				t_vars;

int	close(int keycode, t_vars *vars)
{
	(void)keycode;
	mlx_destroy_window(vars->mlx, vars->win);
	exit(1);
}

int	main(void)
{
	t_vars game;

	game.mlx = mlx_init();
	game.win = mlx_new_window(game.mlx, 500, 500, "Ciucciami la fava");
	mlx_hook(game.win, 2, 1L<<0, close, &game);
	mlx_loop(game.mlx);
	return (1);
}
