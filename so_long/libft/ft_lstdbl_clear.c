/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdbl_clear.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vnastase <vnastase@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/15 13:21:41 by vnastase          #+#    #+#             */
/*   Updated: 2021/09/15 13:21:41 by vnastase         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstdbl_clear(t_list_dbl **lst, void (*del)(void *))
{
	t_list_dbl		*aux;

	if (lst == NULL || *lst == NULL)
		return ;
	while ((*lst)->prev)
		*lst = (*lst)->prev;
	while (*lst)
	{
		aux = (*lst)->next;
		ft_lstdbl_delone(*lst, del);
		*lst = aux;
	}
}
