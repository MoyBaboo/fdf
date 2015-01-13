/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lvergero <lvergero@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/10/13 16:39:19 by lvergero          #+#    #+#             */
/*   Updated: 2015/01/03 13:35:25 by lvergero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./libft.h"

char	*ft_strdup(const char *s1)
{
	char	*s2;
	size_t	l;

	l = ft_strlen(s1);
	if ((s2 = ft_strnew(l)) == NULL)
		return (NULL);
	s2 = ft_strcpy(s2, s1);
	return (s2);
}
