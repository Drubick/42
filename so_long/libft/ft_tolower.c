/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tolower.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vnastase <vnastase@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/06 15:47:11 by vnastase          #+#    #+#             */
/*   Updated: 2021/09/17 14:39:42 by vnastase         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_tolower(int c)
{
	int	uppercase;

	uppercase = c;
	if (c >= 65 && c <= 90)
	{
		uppercase = c + 32;
		return (uppercase);
	}
	return (uppercase);
}
