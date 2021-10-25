/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_map.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vnastase <vnastase@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/12 13:50:17 by vnastase          #+#    #+#             */
/*   Updated: 2021/10/19 16:56:00 by vnastase         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include <stdio.h>

void	map_populate_conditional(t_map_info *map_info, int x, int y)
{
	if (map_info->map[y][x] == '1')
		mlx_put_image_to_window(map_info->mlx, map_info->win,
			map_info->images.rock, x * 32, y * 32);
	else if (map_info->map[y][x] == 'C')
		mlx_put_image_to_window(map_info->mlx, map_info->win,
			map_info->images.collectionable, x * 32, y * 32);
	else if (map_info->map[y][x] == '0')
		mlx_put_image_to_window(map_info->mlx, map_info->win,
			map_info->images.tile, x * 32, y * 32);
	else if (map_info->map[y][x] == 'P')
	{
		mlx_put_image_to_window(map_info->mlx, map_info->win,
			map_info->images.player, x * 32, y * 32);
		map_info->p_x = x;
		map_info->p_y = y;
	}
	else if (map_info->map[y][x] == 'E')
		mlx_put_image_to_window(map_info->mlx, map_info->win,
			map_info->images.exit, x * 32, y * 32);
}

void	map_populate(t_map_info *map_info)
{
	int	x;
	int	y;

	y = 0;
	while (map_info->map[y])
	{
		x = 0;
		while (map_info->map[y][x] != '\0')
		{
			if (map_info->map[y][x] == 'C')
				map_info->collection++;
			map_populate_conditional(map_info, x, y);
			x++;
		}
		y ++;
	}
}

void	render_map(t_map_info *map_info)
{
	int	screen_w;
	int	screen_h;

	screen_w = map_info->map_lenght * 32;
	screen_h = map_info->map_height * 32;
	map_info->mlx = mlx_init();
	map_info->win = mlx_new_window(map_info->mlx, screen_w,
			screen_h, "so_long");
	if (!load_images(map_info))
		print_error_exit(2, map_info);
	map_populate(map_info);
	listen_events(map_info);
	mlx_loop(map_info->mlx);
}
