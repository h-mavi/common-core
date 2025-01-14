/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfanelli <mfanelli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/10 13:44:56 by mfanelli          #+#    #+#             */
/*   Updated: 2025/01/14 16:16:06 by mfanelli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	close_with_esc(int keycode, t_vars *info)
{
	int	i;

	i = 0;
	if (keycode == 65307)
	{
		while(info->map[i])
			free(info->map[i++]);
		free(info->map);
		mlx_destroy_window(info->mlx, info->win);
		mlx_destroy_display(info->mlx);
		free(info->mlx);
		exit (0);
	}
	return (0);
}

int	close_with_x(t_vars *info)
{
	int	i;

	i = 0;
	while(info->map[i])
		free(info->map[i++]);
	free(info->map);
	mlx_destroy_window(info->mlx, info->win);
	mlx_destroy_display(info->mlx);
	free(info->mlx);
	exit (0);
}

int	map_pars(t_vars *info)
{
	if(!check_char(info->map))
		return(0);
	if(!check_wall(info->map))
		return(0);
	if(!check_if_atleast(info->map))
		return(0);
	return(1);
}

int	map_gen(t_vars *info)
{
	int		i;
	int		index;
	char	*line;
	int		fd;

	i = 0;
	index = how_many_cl();
	info->map = ft_calloc(index, sizeof(char *));
	fd = open("map.ber", O_RDONLY);
	line = get_next_line(fd);
	if(fd < 0 || !line)
		return(0);
	while(line)
	{
		info->map[i] = ft_calloc(ft_strlen(line), sizeof(char));
		ft_strlcpy(info->map[i], line, ft_strlen(line) + 1);
		free(line);
		line = get_next_line(fd);
		i++;
	}
	close(fd);
	if(!map_pars(info))
		return(0);
	return (1);
}
