/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfanelli <mfanelli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/14 17:02:26 by mfanelli          #+#    #+#             */
/*   Updated: 2025/01/14 17:46:50 by mfanelli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "./minilibx-linux/mlx.h"
# include <X11/X.h>
# include <X11/keysym.h>
# include <stdlib.h>
# include <stdio.h>

int main(void)
{
    void *mlx;
    void *win;
    void *img;
    int a = 10;
    int b = 30;

    mlx = mlx_init();
    win = mlx_new_window(mlx, 150, 150, "lil hooman");
    img = mlx_xpm_file_to_image(mlx, "/nfs/homes/mfanelli/Desktop/frisk_big.xpm", &a, &b);
    mlx_put_image_to_window(mlx, win, img, 0, 0);
    mlx_loop(mlx);
}