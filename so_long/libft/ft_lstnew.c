/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vnastase <vnastase@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/26 12:23:42 by vnastase          #+#    #+#             */
/*   Updated: 2021/09/15 13:38:21 by vnastase         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstnew(void *content)
{
	t_list	*ptr;
	void	*contenido;

	contenido = (void *)content;
	ptr = malloc(sizeof(t_list));
	if (!ptr)
		return (NULL);
	ptr->content = contenido;
	ptr->next = NULL;
	return (ptr);
}
