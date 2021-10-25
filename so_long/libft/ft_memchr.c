/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vnastase <vnastase@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/06 17:11:24 by vnastase          #+#    #+#             */
/*   Updated: 2021/09/15 13:32:40 by vnastase         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	unsigned char	s1;
	unsigned char	*s2;
	size_t			i;

	i = 0;
	s1 = c;
	s2 = (unsigned char *)s;
	while (i < n)
	{
		if (s2[i] == s1)
			return ((void *)s);
		s++;
		i++;
	}
	return (NULL);
}
