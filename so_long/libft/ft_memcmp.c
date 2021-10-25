/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vnastase <vnastase@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/12 15:07:32 by vnastase          #+#    #+#             */
/*   Updated: 2019/12/16 10:34:31 by vnastase         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	size_t			i;
	unsigned char	*arr;
	unsigned char	*arr2;

	arr = (unsigned char *)s1;
	arr2 = (unsigned char *)s2;
	i = 0;
	while (i < n)
	{
		if (arr[i] != arr2[i])
			return (arr[i] - arr2[i]);
		i++;
	}
	return (0);
}
