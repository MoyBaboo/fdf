/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lvergero <lvergero@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/10/13 18:14:21 by lvergero          #+#    #+#             */
/*   Updated: 2014/10/13 18:14:22 by lvergero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./libft.h"

char	*ft_strrchr(const char *s, int c)
{
	int		i;
	int		ret;
	int		l;

	if (c == '\0')
	{
		l = ft_strlen(s);
		return ((char *)s + l);
	}
	ret = -1;
	i = 0;
	while (s[i] != '\0')
	{
		if (s[i] == c)
			ret = i;
		i++;
	}
	if (ret != -1)
		return ((char *)s + ret);
	return (NULL);
}
