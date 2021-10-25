/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vnastase <vnastase@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/15 13:23:17 by vnastase          #+#    #+#             */
/*   Updated: 2021/09/15 13:23:18 by vnastase         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strncpy(char *s2, int n)
{
	char	*s;

	if (!s2)
		return (ft_strdup(""));
	s = malloc(n + 1);
	if (!s)
		return (0);
	ft_strlcpy(s, s2, n + 1);
	return (s);
}
