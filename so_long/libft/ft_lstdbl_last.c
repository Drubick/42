/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdbl_last.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vnastase <vnastase@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/15 13:21:56 by vnastase          #+#    #+#             */
/*   Updated: 2021/09/15 13:21:57 by vnastase         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list_dbl	*ft_lstdbl_last(t_list_dbl *lst)
{
	if (lst == 0)
		return (lst);
	else
		while (lst->next != 0)
			lst = lst->next;
	return (lst);
}
