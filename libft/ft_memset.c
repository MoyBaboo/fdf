/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lvergero <lvergero@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/10/13 18:37:28 by lvergero          #+#    #+#             */
/*   Updated: 2014/10/13 18:37:30 by lvergero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./libft.h"

void	*ft_memset(void *b, int c, size_t len)
{
	size_t			i;

	if (len == 0)
		return (b);
	i = 0;
	while (i < len)
	{
		((unsigned char*)b)[i] = c;
		i++;
	}
	return (b);
}
