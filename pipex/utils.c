/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vnastase <vnastase@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/04 14:11:47 by vnastase          #+#    #+#             */
/*   Updated: 2021/11/09 16:02:41 by vnastase         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

char	*path_join(char *dir, char *instruction)
{
	char	*joined;
	int		i;
	int		j;

	joined = malloc(sizeof(char) * (str_ichr(dir, 0)
				+ str_ichr(instruction, 0) + 2));
	i = 0;
	j = 0;
	while (dir[j])
		joined[i++] = dir[j++];
	joined[i++] = '/';
	j = 0;
	while (instruction[j])
		joined[i++] = instruction[j++];
	joined[i] = 0;
	return (joined);
}

int	str_ichr(char *str, char c)
{
	int	i;

	i = 0;
	while (str[i] && str[i] != c)
		i++;
	if (str[i] == c)
		return (i);
	return (-1);
}

char	*str_ndup(char *str, unsigned int n)
{
	char				*duped;
	unsigned int		i;

	i = 0;
	duped = malloc(sizeof(char) * (n + 1));
	while (i < n)
		duped[i++] = *str++;
	duped[n] = 0;
	return (duped);
}

void	print_pemrission_error(char *file)
{
	write(STDERR, "pipex: ", 7);
	write(STDERR, file, str_ichr(file, 0));
	write(STDERR, ": permission denied\n", 22);
}
