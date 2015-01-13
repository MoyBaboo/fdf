/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_arraydup.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lvergero <lvergero@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/03 17:02:53 by lvergero          #+#    #+#             */
/*   Updated: 2015/01/12 13:16:00 by lvergero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./libft.h"

char	**ft_arraydup(const char **t1)
{
	char	**t2;
	size_t	h;

	h = 0;
	while (t1[h])
		h++;
	if (t1 == NULL || (t2 = (char**)malloc(sizeof(char*) * (h + 1))) == NULL)
		return (NULL);
	h = 0;
	while (t1[h])
	{
		t2[h] = ft_strdup(t1[h]);
		h++;
	}
	t2[h] = 0;
	return (t2);
}
