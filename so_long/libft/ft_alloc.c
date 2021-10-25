/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_alloc.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vnastase <vnastase@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/15 13:20:16 by vnastase          #+#    #+#             */
/*   Updated: 2021/09/15 13:20:17 by vnastase         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** Allocates a memory segment of count * size + 1 and
** null terminates the result.
*/

void	*ft_alloc(size_t count, size_t size)
{
	void	*array;

	array = malloc(count * size + size);
	if (!array)
		return (NULL);
	ft_bzero(array + count * size, size);
	return ((void *)array);
}
