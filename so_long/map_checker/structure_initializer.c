/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   structure_initializer.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vnastase <vnastase@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/12 13:58:19 by vnastase          #+#    #+#             */
/*   Updated: 2021/10/25 14:54:48 by vnastase         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	load_images(t_map_info *map_info)
{
	int	p;
	int	j;

	map_info->images.rock = mlx_xpm_file_to_image(map_info->mlx,
			"./img/rock.xpm", &p, &j);
	map_info->images.player = mlx_xpm_file_to_image(map_info->mlx,
			"./img/player.xpm", &p, &j);
	map_info->images.tile = mlx_xpm_file_to_image(map_info->mlx,
			"./img/tile.xpm", &p, &j);
	map_info->images.exit = mlx_xpm_file_to_image(map_info->mlx,
			"./img/exit.xpm", &p, &j);
	map_info->images.collectionable = mlx_xpm_file_to_image(map_info->mlx,
			"./img/star.xpm", &p, &j);
	map_info->images.player_exit = mlx_xpm_file_to_image(map_info->mlx,
			"./img/player_exit.xpm", &p, &j);
	if (map_info->images.rock && map_info->images.player
		&& map_info->images.tile
		&& map_info->images.exit && map_info->images.collectionable)
		return (1);
	return (0);
}

void	map_info_intializor(t_map_info *map_info, t_list *map)
{
	map_info->map_height = ft_lstsize(map);
	map_info->map_lenght = ft_strlen(map->content);
	map_info->p_direction = 2;
	ft_lstclear(&map, NULL);
}
