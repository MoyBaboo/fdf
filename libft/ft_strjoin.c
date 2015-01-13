/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lvergero <lvergero@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/10/14 15:59:34 by lvergero          #+#    #+#             */
/*   Updated: 2015/01/02 22:39:02 by lvergero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*join;
	int		len;

	if (s1 == NULL || s2 == NULL)
		return (NULL);
	len = (ft_strlen(s1)) + (ft_strlen(s2)) + 1;
	if ((join = (char *)malloc(sizeof(char) * len)) == NULL)
		return (NULL);
	join = ft_strcpy(join, s1);
	join = ft_strcat(join, s2);
	return (join);
}
