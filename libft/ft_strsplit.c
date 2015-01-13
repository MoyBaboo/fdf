/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lvergero <lvergero@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/10/14 16:18:42 by lvergero          #+#    #+#             */
/*   Updated: 2015/01/03 18:01:03 by lvergero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./libft.h"

char	**ft_strsplit(char const *s, char c)
{
	char	*cpy;
	char	*tmp;
	char	**split;
	char	**current;

	cpy = ft_strtrimchar((char *)s, c);
	if (cpy == NULL)
	{
		split = (char**)malloc(sizeof(char*));
		split[0] = NULL;
		return (split);
	}
	current = (char**)malloc(sizeof(char*));
	split = NULL;
	while (cpy && (tmp = ft_strchr(cpy, c)) != NULL)
	{
		current[0] = ft_strsub(cpy, 0, (ft_strlen(cpy) - ft_strlen(tmp)));
		split = ft_arrayjoin((char const**)split, (char const**)current);
		cpy = tmp;
		while (*cpy == c)
			cpy++;
	}
	current[0] = ft_strsub(cpy, 0, (ft_strlen(cpy) - ft_strlen(tmp)));
	split = ft_arrayjoin((char const**)split, (char const**)current);
	return (split);
}
