/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vnastase <vnastase@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/18 14:05:23 by vnastase          #+#    #+#             */
/*   Updated: 2021/10/25 14:55:15 by vnastase         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	free_map(t_map_info *map_info)
{
	int	i;

	i = 0;
	while (map_info->map[i])
	{
		free(map_info->map[i]);
		i++;
	}
	free(map_info->map);
}

int	close_window(t_map_info *map_info)
{
	int	i;

	i = 0;
	mlx_destroy_image(map_info->mlx, map_info->images.collectionable);
	mlx_destroy_image(map_info->mlx, map_info->images.exit);
	mlx_destroy_image(map_info->mlx, map_info->images.player);
	mlx_destroy_image(map_info->mlx, map_info->images.rock);
	mlx_destroy_image(map_info->mlx, map_info->images.tile);
	mlx_destroy_window(map_info->mlx, map_info->win);
	free_map(map_info);
	exit(0);
	return (0);
}

int	key_hook(int key, t_map_info *map_info)
{
	if (key == 53)
		close_window(map_info);
	if (map_info->end_game != 1)
	{
		if (key == 13)
			player_movement(map_info, 0, -1);
		else if (key == 0)
			player_movement(map_info, -1, 0);
		else if (key == 1)
			player_movement(map_info, 0, 1);
		else if (key == 2)
			player_movement(map_info, 1, 0);
	}
	else
		close_window(map_info);
	return (0);
}

void	listen_events(t_map_info *map_info)
{
	mlx_key_hook(map_info->win, *key_hook, map_info);
	mlx_hook(map_info->win, 17, (1L << 8), close_window, map_info);
}
