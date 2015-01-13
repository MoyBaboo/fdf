/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lvergero <lvergero@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/10/13 17:10:59 by lvergero          #+#    #+#             */
/*   Updated: 2015/01/03 13:56:53 by lvergero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./libft.h"

char	*ft_strstr(const char *s1, const char *s2)
{
	int		start;

	if (s2[0] == '\0')
		return ((char*)s1);
	start = 0;
	while (s1[start] != '\0')
	{
		if (ft_memcmp(&(s1[start]), s2, ft_strlen(s2)) == 0)
			return ((char *)s1 + start);
		start++;
	}
	return (NULL);
}
