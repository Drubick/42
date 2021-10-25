/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_toupper.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vnastase <vnastase@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/06 15:47:11 by vnastase          #+#    #+#             */
/*   Updated: 2021/09/17 14:39:51 by vnastase         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_toupper(int c)
{
	int	uppercase;

	uppercase = c;
	if (c >= 97 && c <= 122)
	{
		uppercase = c - 32;
		return (uppercase);
	}
	return (uppercase);
}
