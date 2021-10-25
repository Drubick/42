/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back_bonus.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vnastase <vnastase@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/26 15:59:36 by vnastase          #+#    #+#             */
/*   Updated: 2019/12/16 11:21:23 by vnastase         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstadd_back(t_list **alst, t_list *new)
{
	t_list	*buff;

	if (!alst)
		return ;
	buff = *alst;
	if (*alst == 0)
		*alst = new;
	else
	{
		while ((*buff).next)
			buff = (*buff).next;
		(*buff).next = new;
	}
}
