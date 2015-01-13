/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lvergero <lvergero@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/10/13 18:17:09 by lvergero          #+#    #+#             */
/*   Updated: 2014/11/07 18:16:36 by lvergero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	i;
	size_t	j;
	size_t	len;

	if (size == 0)
		return (ft_strlen(src));
	i = ft_strlen(dst);
	j = ft_strlen(src);
	len = i + j;
	if (i > size)
		return ((((j + size) > i + j) ? i + j : j + size));
	j = 0;
	while (src[j] != '\0' && (i + j) < (size - 1))
	{
		dst[i + j] = src[j];
		j++;
	}
	dst[i + j] = '\0';
	j++;
	return (len);
}
