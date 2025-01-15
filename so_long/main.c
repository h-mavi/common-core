/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   win.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfanelli <mfanelli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/10 11:57:19 by mfanelli          #+#    #+#             */
/*   Updated: 2025/01/15 16:36:43 by mfanelli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	start(char *file)
{
	t_vars	info;
	int		i;
	int		frisk = 48;
	int		save = 40;
	int		heart = 32;

	i = 0;
	if(!check_file_valid(file))
		return(0);
	if(!map_gen(&info, file))
	{
		while(info.map[i])
			free(info.map[i++]);
		free(info.map);
		return(0);
	}
	while(info.map[i])
		ft_printf("%s", info.map[i++]);
	info.mlx = mlx_init();
	if (info.mlx == NULL)
		return (1);
	info.win = mlx_new_window(info.mlx, WIDTH, HEIGHT, "lil hooman");
	info.img_player = mlx_xpm_file_to_image(info.mlx, "/nfs/homes/mfanelli/Desktop/common-core/so_long/sprites/frisk_player.xpm", &frisk, &frisk);
	info.img_end = mlx_xpm_file_to_image(info.mlx, "/nfs/homes/mfanelli/Desktop/common-core/so_long/sprites/save_end.xpm", &save, &save);
	info.img_coin = mlx_xpm_file_to_image(info.mlx, "/nfs/homes/mfanelli/Desktop/common-core/so_long/sprites/coin_hear_shape_obj.xpm", &heart, &heart);
	mlx_put_image_to_window(info.mlx, info.win, info.img_player, 0, 0);
	mlx_put_image_to_window(info.mlx, info.win, info.img_end, 50, 0);
	mlx_put_image_to_window(info.mlx, info.win, info.img_coin, 0, 50);
	mlx_hook(info.win, 17, 1L << 0, close_with_x, &info);
	mlx_hook(info.win, 2, 1L << 0, close_with_esc, &info);
	mlx_loop(info.mlx);
	return(1);
}

int main(int argc, char *argv[])
{
	(void)argc;
	start(argv[1]);
}
