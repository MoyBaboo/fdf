/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lvergero <lvergero@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/10/14 17:08:47 by lvergero          #+#    #+#             */
/*   Updated: 2015/01/03 17:49:41 by lvergero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./libft.h"

t_list	*ft_lstnew(void const *content, size_t content_size)
{
	t_list	*newl;

	if ((newl = (t_list *)malloc(sizeof(t_list))) == NULL)
		return (NULL);
	if (content == NULL)
	{
		newl->content_size = 0;
		newl->content = NULL;
		return (newl);
	}
	newl->content_size = content_size;
	if ((newl->content =
		(unsigned char *)malloc(sizeof(unsigned char) * content_size)) == NULL)
		return (NULL);
	newl->content = ft_memcpy(newl->content, content, content_size);
	newl->next = NULL;
	return (newl);
}
