/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   window.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfanelli <mfanelli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/08 16:29:42 by mfanelli          #+#    #+#             */
/*   Updated: 2025/01/10 12:00:02 by mfanelli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// si chiude solo con esc

// #include "./minilibx-linux/mlx.h"
// #include <stdlib.h>
// #include <stdio.h>

// typedef struct	s_vars
// {
// 	void	*mlx;
// 	void	*win;
// }				t_vars;

// int	close(int keycode, t_vars *vars)
// {
// 	if (keycode == 65307)
//     {
// 		printf("Keycode: %d\n", keycode);
// 		mlx_destroy_window(vars->mlx, vars->win);
//     }
// 	return (0);
// }

// int	handle_no_event(void *data)
// {
//     (void)data;
// 	return (0);
// }

// int	main(void)
// {
// 	t_vars game;

// 	game.mlx = mlx_init();
// 	game.win = mlx_new_window(game.mlx, 500, 500, "Ciucciami la fava");
// 	mlx_loop_hook(game.mlx, &handle_no_event, &game);
//     mlx_hook(game.win, 2, 1L<<0, close, &game);
// 	mlx_loop(game.mlx);
//     mlx_destroy_display(game.mlx);
// 	free(game.mlx);
// }

















// si chiude con la x della finestra ma in SEGFAULT

// int	close(t_vars *vars)
// {
// 	mlx_destroy_window(vars->mlx, vars->win);
//     mlx_destroy_display(vars->mlx);
//     free(vars->mlx);
//     exit (0);
// }

// int	main(void)
// {
// 	t_vars game;

// 	game.mlx = mlx_init();
// 	game.win = mlx_new_window(game.mlx, 500, 500, "Ciucciami la fava");
//     // mlx_loop_hook(game.mlx, &handle_no_event, &game);
// 	mlx_hook(game.win, 17, 1L << 0, close, &game);
// 	mlx_loop(game.mlx);
// }

// int	main(void)
// {
// 	t_struct	data;

// 	data.mlx = mlx_init();
// 	if (data.mlx == NULL)
// 		return (MALLOC_ERROR);
// 	data.win = mlx_new_window(data.mlx, WIDTH, HEIGHT, "corbezzoli!");
// 	mlx_hook(data.win, 17, 1L << 0, ft_cross_close, &data);
// 	mlx_hook(data.win, 2, 1L << 0, ft_close, &data);
// 	mlx_loop(data.mlx);
// }















// #include <X11/keysym.h>

// typedef struct s_data
// {
//     void	*mlx_ptr;
//     void	*win_ptr;
// }	t_data;

// int	handle_no_event(void *data)
// {
//     /* This function needs to exist, but it is useless for the moment */
//     (void)data;
// 	return (0);
// }

// int	handle_input(int keysym, t_data *data)
// {
//     if (keysym == 65307)
//         mlx_destroy_window(data->mlx_ptr, data->win_ptr);
//     return (0);
// }

// int	main(void)
// {
//     t_data	data;

//     data.mlx_ptr = mlx_init();
//     if (data.mlx_ptr == NULL)
//         return (1);
//     data.win_ptr = mlx_new_window(data.mlx_ptr, 500, 500,
//             "My first window!");
//     if (data.win_ptr == NULL)
//     {
//         free(data.win_ptr);
//         return (1);
//     }

//     /* Setup hooks */ 
//     mlx_loop_hook(data.mlx_ptr, &handle_no_event, &data);
//     mlx_key_hook(data.win_ptr, &handle_input, &data);

//     mlx_loop(data.mlx_ptr);

//     /* we will exit the loop if there's no window left, and execute this code */
//     mlx_destroy_display(data.mlx_ptr);
//     free(data.mlx_ptr);
// }

































// int	handle_keypress(int keysym, t_data *data)
// {
//     if (keysym == 65307)
//         mlx_destroy_window(data->mlx_ptr, data->win_ptr);

//     printf("Keypress: %d\n", keysym);
//     return (0);
// }

// // int	handle_keyrelease(int keysym, void *data)
// // {
// //     (void)data;
// // 	printf("Keyrelease: %d\n", keysym);
// //     return (0);
// // }

// int	main(void)
// {
//     t_data	data;

//     data.mlx_ptr = mlx_init();
//     if (data.mlx_ptr == NULL)
//         return (1);
//     data.win_ptr = mlx_new_window(data.mlx_ptr, 500, 500, "My first window!");
//     if (data.win_ptr == NULL)
//     {
//         free(data.win_ptr);
//         return (1);
//     }

//     /* Setup hooks */ 
//     mlx_loop_hook(data.mlx_ptr, &handle_no_event, &data);
//     mlx_hook(data.win_ptr, 2, 1L<<0, &handle_keypress, &data); /* ADDED */
//     // mlx_hook(data.win_ptr, 3, 1L<<1, &handle_keyrelease, &data); /* CHANGED */

//     mlx_loop(data.mlx_ptr);

//     /* we will exit the loop if there's no window left, and execute this code */
//     mlx_destroy_display(data.mlx_ptr);
//     free(data.mlx_ptr);
// }


