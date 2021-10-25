/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_checkset.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vnastase <vnastase@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/15 13:22:55 by vnastase          #+#    #+#             */
/*   Updated: 2021/09/15 13:22:56 by vnastase         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_bool	ft_str_checkset(char *string, char *set)
{
	if (string)
	{
		while (*string)
		{
			if (ft_checkchar(*string, set))
				return (true);
			string++;
		}
	}
	return (false);
}
