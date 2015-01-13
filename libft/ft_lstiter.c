/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstiter.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lvergero <lvergero@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/09 20:23:56 by lvergero          #+#    #+#             */
/*   Updated: 2014/11/09 20:23:58 by lvergero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./libft.h"

void	ft_lstiter(t_list *lst, void (*f)(t_list *elem))
{
	while (lst->next != NULL)
	{
		(f)(lst);
		lst = lst->next;
	}
	(f)(lst);
	return ;
}
