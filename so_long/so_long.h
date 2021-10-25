/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vnastase <vnastase@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/19 16:06:31 by vnastase          #+#    #+#             */
/*   Updated: 2021/10/25 14:50:15 by vnastase         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "libft.h"
# include "mlx.h"
# include <stdio.h>

typedef struct s_render_images
{
	void	*player;
	void	*rock;
	void	*tile;
	void	*collectionable;
	void	*exit;
	void	*player_exit;
}	t_render_images;

typedef struct s_map_info
{
	int					position;
	int					collection;
	int					exit;
	char				**map;
	int					map_height;
	int					map_lenght;
	int					x;
	int					y;
	int					*mlx;
	int					*win;
	int					end_game;
	int					p_death;
	int					found_collect;
	int					p_direction;
	int					p_x;
	int					p_y;
	int					n_collect;
	int					moves;
	t_render_images		images;

}	t_map_info;

typedef struct s_image
{
	char	*path;
	int		w;
	int		h;
}	t_image;

t_bool		check_map(t_list *map);
void		initialize_map(t_list **map, char const *argv[]);
t_bool		check_tokens(t_list *map);
t_bool		is_rectangle(t_list *map);
void		map_memory_allocation(t_list *map_obsolete, t_map_info *map);
void		saving_map_array(t_list *map_obsolete, t_map_info *map);	
t_bool		initialize_andcheck_map(char const *argv[], t_map_info *map_info);
void		map_info_intializor(t_map_info *map_info, t_list *map);
void		render_map(t_map_info *map_info);
void		ft_render_tile(t_map_info *map_info, char *path, int off);
void		map_populate(t_map_info *map_info);
void		ft_render_rocks(t_map_info *map, int offset, int index);
void		ft_render_player(t_map_info *map, int offset, int x, int y);
void		ft_render_exit(t_map_info *map, int offset, int start);
void		ft_render_collectible(t_map_info *map, int offset, int start);
int			load_images(t_map_info *map_info);
void		listen_events(t_map_info *map_info);
void		player_movement(t_map_info *map_info, int x, int y);
int			key_event(t_map_info *map_info, int player_move_y,
				int player_move_x, int direction);
int			close_window(t_map_info *map_info);
void		print_error_exit(int exception, t_map_info *map_info);
void		free_map(t_map_info *map_info);
#endif