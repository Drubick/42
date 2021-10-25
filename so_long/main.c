/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vnastase <vnastase@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/19 12:54:43 by vnastase          #+#    #+#             */
/*   Updated: 2021/10/25 15:10:54 by vnastase         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include <unistd.h>
#include <fcntl.h>
#include "libft.h"
#include "stdio.h"

void	print_error_exit(int exception, t_map_info *map_info)
{
	if (exception == 1)
	{
		printf("Error\nNOT A VALID MAP FORMAT\n");
		free_map(map_info);
		exit (1);
	}
	else if (exception == 2)
	{
		printf("Error\nIMAGE NOT FOUND\n");
		free(map_info->mlx);
		free(map_info->win);
		free_map(map_info);
		exit (1);
	}
	else if (exception == 3)
	{
		printf("Error\nNOT A VALID MAP FILE");
		exit (1);
	}
}

void	valid_map_file(char const *argv, t_map_info *map_info)
{
	int	i;

	i = ft_strlen(argv);
	if (i < 5)
		print_error_exit(3, map_info);
	if (ft_strncmp(&(argv[i - 4]), ".ber", 4))
		print_error_exit(3, map_info);
}

void	saving_map_array(t_list *map_obsolete, t_map_info *map_info)
{
	int	j;

	j = 0;
	map_info->map = ft_calloc(ft_lstsize(map_obsolete) + 1, sizeof(char *));
	while (map_obsolete)
	{
		map_info->map[j] = ((char *)map_obsolete->content);
		map_obsolete = map_obsolete->next;
		j++;
	}
	map_info->map[j] = NULL;
}

int	main(int argc, char const *argv[])
{
	t_map_info	map_info;

	valid_map_file(argv[1], &map_info);
	ft_memset(&map_info, 0, sizeof(t_map_info));
	if (argc == 1)
		return (0);
	if (!initialize_andcheck_map(argv, &map_info))
		print_error_exit(1, &map_info);
	render_map(&map_info);
	return (0);
}
