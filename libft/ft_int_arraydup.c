/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_int_arraydup.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lvergero <lvergero@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/12 13:05:26 by lvergero          #+#    #+#             */
/*   Updated: 2015/01/12 13:24:11 by lvergero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./libft.h"

int		**ft_int_arraydup(const int **t1)
{
	int		**t2;
	size_t	h;

	h = 0;
	while (t1[h])
		h++;
	if (t1 == NULL || (t2 = (int**)malloc(sizeof(int*) * h)) == NULL)
		return (NULL);
	h = 0;
	while (t1[h])
	{
		t2[h] = ft_intptrdup(t1[h]);
		h++;
	}
	return (t2);
}
