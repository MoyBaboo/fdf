/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lvergero <lvergero@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/10/13 18:51:21 by lvergero          #+#    #+#             */
/*   Updated: 2014/10/13 18:51:23 by lvergero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./libft.h"

void	*ft_memccpy(void *dst, const void *src, int c, size_t n)
{
	size_t		i;
	char		*dstbis;
	const char	*srcbis;

	i = 0;
	dstbis = (char*)dst;
	srcbis = (char*)src;
	while (i < n && srcbis[i] != (char)c)
	{
		dstbis[i] = srcbis[i];
		i++;
	}
	if (i < n && srcbis[i] == (char)c)
	{
		dstbis[i] = srcbis[i];
		return (&dstbis[i + 1]);
	}
	return (NULL);
}
