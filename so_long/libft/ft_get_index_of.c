/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_index_of.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vnastase <vnastase@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/15 13:21:09 by vnastase          #+#    #+#             */
/*   Updated: 2021/09/15 13:21:10 by vnastase         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_get_index_of(char *string, char c)
{
	int	index;

	index = 0;
	while (string[index])
	{
		if (string[index] == c)
			return (index);
		index++;
	}
	return (-1);
}
