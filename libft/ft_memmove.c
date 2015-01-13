/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lvergero <lvergero@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/10/13 19:17:58 by lvergero          #+#    #+#             */
/*   Updated: 2014/10/13 19:18:00 by lvergero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	char		*dstbis;
	const char	*srcbis;

	if (src == NULL && dst == NULL)
		return (NULL);
	if (len == 0 || dst == src)
		return (dst);
	dstbis = dst;
	srcbis = src;
	if (dstbis < srcbis)
		return (ft_memcpy(dst, src, len));
	dstbis += len - 1;
	srcbis += len - 1;
	while (len > 0)
	{
		*dstbis = *srcbis;
		dstbis--;
		srcbis--;
		len--;
	}
	return (dst);
}
