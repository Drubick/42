/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vnastase <vnastase@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/11 14:44:53 by vnastase          #+#    #+#             */
/*   Updated: 2021/10/19 15:54:21 by vnastase         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	another_function(t_file *file_buffer, int *bytes_read,
char *buffer)
{
	char			*aux;

	aux = 0;
	while (ft_get_index_of(file_buffer->buffer, '\n') == -1 && *bytes_read)
	{
		*bytes_read = read(file_buffer->fd, buffer, BUFFER_SIZE);
		if (*bytes_read == 0 || *bytes_read == -1)
			free(buffer);
		if (*bytes_read == -1)
			return (-1);
		else if (*bytes_read)
		{
			buffer[*bytes_read] = '\0';
			aux = file_buffer->buffer;
			file_buffer->buffer = ft_strjoin(file_buffer->buffer, buffer);
			free(aux);
		}
	}
	return (1);
}

int	get_next_line(int fd, char **line)
{
	char			*buffer;
	static t_file	*files[1];
	int				bytes_read;
	char			*aux;
	t_file			*file_buffer;

	aux = NULL;
	if (fd == -1)
		return (-1);
	buffer = malloc(sizeof(char) * (BUFFER_SIZE + 1));
	file_buffer = get_file_buffer(fd, &(files[0]));
	bytes_read = 1;
	if (another_function(file_buffer, &bytes_read, buffer) == -1)
		return (-1);
	if (bytes_read == 0)
		return (get_next_line_utils(file_buffer, line, files));
	bytes_read = ft_get_index_of(file_buffer->buffer, '\n');
	*line = ft_substr(file_buffer->buffer, 0, bytes_read);
	aux = file_buffer->buffer;
	file_buffer->buffer = ft_substr(file_buffer->buffer, bytes_read + 1,
			ft_strlen(file_buffer->buffer) - bytes_read);
	free(aux);
	free(buffer);
	return (1);
}

int	get_next_line_utils(t_file *file_buffer, char **line, t_file *files[1])
{
	if (ft_strlen(file_buffer->buffer))
	{
		*line = ft_substr(file_buffer->buffer, 0,
				ft_strlen(file_buffer->buffer));
		delete_file_struct(file_buffer->fd, files);
	}
	else
		*line = ft_strdup("");
	return (0);
}

t_file	*get_file_buffer(int fd, t_file *files[1])
{
	t_file			*p;

	p = files[0];
	if (files[0] == NULL)
	{
		files[0] = (t_file *)malloc(sizeof(t_file));
		files[0]->next = NULL;
		files[0]->fd = fd;
		files[0]->buffer = ft_strdup("");
		return (files[0]);
	}
	while (p->fd != fd && p->next != NULL)
		p = p->next;
	if (p->fd == fd)
		return (p);
	else
	{
		p->next = malloc(sizeof(t_file));
		p->fd = fd;
		p->next->next = NULL;
		p->next->buffer = ft_strdup("");
	}
	return (p);
}

void	delete_file_struct(int fd, t_file *files[1])
{
	t_file			*aux;
	t_file			*iter;

	if (files[0]->fd == fd)
	{
		free(files[0]->buffer);
		aux = files[0]->next;
		free(files[0]);
		files[0] = aux;
		return ;
	}
	iter = files[0];
	while (iter->next->fd != fd)
	{
		iter = iter->next;
	}
	aux = iter->next;
	free(iter->next->buffer);
	iter->next = aux->next;
	free(aux);
}
