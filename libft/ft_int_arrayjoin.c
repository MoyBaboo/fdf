/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_int_arrayjoin.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lvergero <lvergero@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/12 13:05:42 by lvergero          #+#    #+#             */
/*   Updated: 2015/01/12 13:21:18 by lvergero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./libft.h"

int	**ft_int_arrayjoin(int const **t1, int const **t2)
{
	int		**join;
	int		len1;
	int		len2;
	int		i;

	if (t1 == NULL || t2 == NULL)
		return (t1 == NULL) ? ft_int_arraydup(t2) : ft_int_arraydup(t1);
	len1 = 0;
	len2 = 0;
	while (t2[len2] || t1[len1])
		(t1[len1]) ? len1++ : len2++;
	if ((join = (int **)malloc(sizeof(int*) * (len1 + len2))) == NULL)
		return (NULL);
	i = 0;
	while ((i - len1) < len2)
	{
		join[i] = (i < len1) ? ft_intptrdup(t1[i]) : ft_intptrdup(t2[i - len1]);
		i++;
	}
	return (join);
}
