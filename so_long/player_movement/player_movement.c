/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_movement.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vnastase <vnastase@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/18 15:40:01 by vnastase          #+#    #+#             */
/*   Updated: 2021/10/25 14:51:47 by vnastase         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	redraw_character(t_map_info *map_info, int x, int y)
{
	if (map_info->map[map_info->p_y][map_info->p_x] == 'E')
	{
		mlx_put_image_to_window(map_info->mlx, map_info->win,
			map_info->images.exit, map_info->p_x * 32, map_info->p_y * 32);
		map_info->map[map_info->p_y][map_info->p_x] = 'E';
	}
	else
	{	
		mlx_put_image_to_window(map_info->mlx, map_info->win,
			map_info->images.tile, map_info->p_x * 32, map_info->p_y * 32);
		map_info->map[map_info->p_y][map_info->p_x] = '0';
	}
	mlx_put_image_to_window(map_info->mlx, map_info->win,
		map_info->images.tile, (map_info->p_x + x) * 32,
		(map_info->p_y + y) * 32);
	mlx_put_image_to_window(map_info->mlx, map_info->win,
		map_info->images.player, (map_info->p_x + x) * 32,
		(map_info->p_y + y) * 32);
	map_info->p_x += x;
	map_info->p_y += y;
}

void	redraw_character_collectionable(t_map_info *map_info, int x, int y)
{
	if (map_info->map[map_info->p_y][map_info->p_x] == 'E')
	{
		mlx_put_image_to_window(map_info->mlx, map_info->win,
			map_info->images.exit,
			map_info->p_x * 32, map_info->p_y * 32);
		map_info->map[map_info->p_y][map_info->p_x] = 'E';
	}
	else
	{	
		mlx_put_image_to_window(map_info->mlx, map_info->win,
			map_info->images.tile, map_info->p_x * 32, map_info->p_y * 32);
		map_info->map[map_info->p_y][map_info->p_x] = '0';
	}
	mlx_put_image_to_window(map_info->mlx, map_info->win, map_info->images.tile,
		(map_info->p_x + x) * 32, (map_info->p_y + y) * 32);
	mlx_put_image_to_window(map_info->mlx, map_info->win,
		map_info->images.player,
		(map_info->p_x + x) * 32, (map_info->p_y + y) * 32);
	map_info->collection--;
	map_info->p_x += x;
	map_info->p_y += y;
}

void	redraw_character_exit(t_map_info *map_info, int x, int y)
{
	if (map_info->map[map_info->p_y][map_info->p_x] == 'E')
	{
		mlx_put_image_to_window(map_info->mlx, map_info->win,
			map_info->images.exit, map_info->p_x * 32, map_info->p_y * 32);
		map_info->map[map_info->p_y][map_info->p_x] = 'E';
	}
	else
	{	
		mlx_put_image_to_window(map_info->mlx, map_info->win,
			map_info->images.tile, map_info->p_x * 32, map_info->p_y * 32);
		map_info->map[map_info->p_y][map_info->p_x] = '0';
	}
	mlx_put_image_to_window(map_info->mlx, map_info->win, map_info->images.exit,
		(map_info->p_x + x) * 32, (map_info->p_y + y) * 32);
	mlx_put_image_to_window(map_info->mlx, map_info->win,
		map_info->images.player_exit, (map_info->p_x + x) * 32,
		(map_info->p_y + y) * 32);
	map_info->p_x += x;
	map_info->p_y += y;
	if (map_info->collection == 0)
		close_window(map_info);
}

void	player_movement(t_map_info *map_info, int x, int y)
{
	int	p_y;
	int	p_x;

	p_y = map_info->p_y;
	p_x = map_info->p_x;
	if (map_info->map[p_y + y][p_x + x] != '1')
	{
		map_info->moves ++;
		printf("Movements: %i\n", map_info->moves);
		if (map_info->map[p_y + y][p_x + x] == '0')
			redraw_character(map_info, x, y);
		else if (map_info->map[p_y + y][p_x + x] == 'C')
			redraw_character_collectionable(map_info, x, y);
		else if (map_info->map[p_y + y][p_x + x] == 'E')
			redraw_character_exit(map_info, x, y);
	}
}
