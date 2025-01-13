/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   win.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfanelli <mfanelli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/10 11:57:19 by mfanelli          #+#    #+#             */
/*   Updated: 2025/01/11 17:26:38 by mfanelli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	main(void)
{
	t_vars	info;
	int		i;

	i = 0;
	map_gen(&info);
	while(info.map[i])
		ft_printf("%s", info.map[i++]);
	info.mlx = mlx_init();
	if (info.mlx == NULL)
		return (1);
	info.win = mlx_new_window(info.mlx, 500, 500, "Ciucciami la fava");
	mlx_hook(info.win, 17, 1L << 0, close_with_x, &info);
	mlx_hook(info.win, 2, 1L << 0, close_with_esc, &info);
	mlx_loop(info.mlx);
}
