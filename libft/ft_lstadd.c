/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lvergero <lvergero@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/10/14 17:08:47 by lvergero          #+#    #+#             */
/*   Updated: 2015/01/03 17:27:52 by lvergero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./libft.h"

void	ft_lstadd(t_list **alst, t_list *new)
{
	if (alst != NULL)
	{
		new->next = *alst;
		*alst = new;
	}
	return ;
}
