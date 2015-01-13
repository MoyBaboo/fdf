/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lvergero <lvergero@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/10/13 17:23:11 by lvergero          #+#    #+#             */
/*   Updated: 2014/10/13 17:23:18 by lvergero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./libft.h"

char	*ft_strnstr(const char *s1, const char *s2, size_t n)
{
	size_t	beg;
	size_t	i;

	if (s2[0] == '\0')
		return ((char *)s1);
	i = 0;
	beg = 0;
	while (s1[beg + i] != '\0' && s2[i] != '\0' && (beg + i) < n)
	{
		while ((ft_memcmp(&(s1[beg + i]), &(s2[i]), 1) == 0) && (beg + i) < n)
		{
			i++;
			if (s2[i] == '\0' && (beg + i) <= n)
				return ((char *)s1 + beg);
		}
		i = 0;
		beg++;
	}
	return (NULL);
}
