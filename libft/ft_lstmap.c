/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lvergero <lvergero@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/09 20:28:54 by lvergero          #+#    #+#             */
/*   Updated: 2015/01/03 18:18:45 by lvergero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./libft.h"

t_list		*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem))
{
	t_list	*mod;
	t_list	*start;

	if (lst == NULL)
		return (NULL);
	start = NULL;
	while (lst != NULL)
	{
		if (start == NULL)
		{
			mod = ft_lstnew(lst->content, lst->content_size);
			mod = (f)(mod);
			start = mod;
		}
		else
		{
			mod->next = ft_lstnew(lst->content, lst->content_size);
			mod->next = (f)(mod->next);
			mod = mod->next;
		}
		lst = lst->next;
	}
	return (start);
}
