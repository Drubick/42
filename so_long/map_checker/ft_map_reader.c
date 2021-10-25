/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_map_reader.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vnastase <vnastase@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/19 13:14:14 by vnastase          #+#    #+#             */
/*   Updated: 2021/10/19 16:05:16 by vnastase         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include <unistd.h>
#include <fcntl.h>
#include <stdio.h>
#include "libft.h"

t_bool	check_map(t_list *map)
{
	int			i;
	int			j;
	const int	endofmap = ft_lstsize(map) - 1;

	j = 0;
	i = 0;
	while (map)
	{
		if (((char *)map->content)[0] != '1' ||
			((char *)map->content)[ft_strlen(map->content) - 1] != '1')
			return (0);
		while (((char *)map->content)[i])
		{
			if ((((char *)map->content)[i] != '1' && j == 0) ||
				(((char *)map->content)[i] != '1' && j == endofmap))
				return (0);
			else if (!ft_strchr("10CEP", ((char *)map->content)[i]))
				return (0);
			i++;
		}
		i = 0;
		j++;
		map = map->next;
	}
	return (1);
}

void	initialize_map(t_list **map, char const *argv[])
{
	char	*buffer;
	int		fd;
	int		ctrl_line;

	buffer = NULL;
	*map = NULL;
	fd = open(argv[1], O_RDONLY);
	if (fd == -1)
	{
		printf("ERROR\n");
		exit(1);
	}
	ctrl_line = get_next_line(fd, &buffer);
	ft_lstadd_back(map, ft_lstnew(buffer));
	while (ctrl_line == 1)
	{
		ctrl_line = get_next_line(fd, &buffer);
		ft_lstadd_back(map, ft_lstnew(buffer));
	}
}

t_bool	check_tokens(t_list *map)
{
	int			i;
	t_map_info	map_info;

	ft_memset(&map_info, 0, sizeof(t_map_info));
	i = 0;
	while ((char *)map)
	{
		while (((char *)map->content)[i])
		{
			if (((char *)map->content)[i] == 'C')
				map_info.collection++;
			else if (((char *)map->content)[i] == 'E')
				map_info.exit++;
			else if (((char *)map->content)[i] == 'P')
				map_info.position++;
			i++;
		}
		i = 0;
		map = map->next;
	}
	if (map_info.collection >= 1 && map_info.exit >= 1
		&& map_info.position == 1)
		return (1);
	return (0);
}

t_bool	is_rectangle(t_list *map)
{
	int	aux;
	int	i;

	i = 0;
	while (((char *)map->content)[i])
		i++;
	aux = i;
	while ((char *)map)
	{
		i = 0;
		while (((char *)map->content)[i])
			i++;
		if (i != aux)
			return (0);
		map = map->next;
	}
	return (1);
}

t_bool	initialize_andcheck_map(char const *argv[], t_map_info *map_info)
{
	t_list	*map;

	map = NULL;
	initialize_map(&map, argv);
	saving_map_array(map, map_info);
	if (!is_rectangle(map))
		return (0);
	else if (!check_map(map))
		return (0);
	else if (!check_tokens(map))
		return (0);
	map_info_intializor(map_info, map);
	return (1);
}
