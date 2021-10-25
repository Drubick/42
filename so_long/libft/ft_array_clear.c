/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_array_clear.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vnastase <vnastase@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/15 13:20:27 by vnastase          #+#    #+#             */
/*   Updated: 2021/09/15 13:20:29 by vnastase         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_array_clear(void **array, void (*del)(void *))
{
	int	i;

	i = 0;
	if (array)
	{
		if (del)
		{
			while (((char **)array)[i])
				del(array[i++]);
			del(array[i]);
		}
		free(array);
	}
}
