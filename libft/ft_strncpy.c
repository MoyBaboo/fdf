/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lvergero <lvergero@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/10/13 17:05:54 by lvergero          #+#    #+#             */
/*   Updated: 2015/01/03 13:51:47 by lvergero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./libft.h"

char	*ft_strncpy(char *dst, const char *src, size_t n)
{
	char	*local;

	local = (char*)src;
	while (n > 0)
	{
		if (*local != '\0')
			*dst++ = *local++;
		else
			*dst++ = '\0';
		n--;
	}
	return (dst);
}
