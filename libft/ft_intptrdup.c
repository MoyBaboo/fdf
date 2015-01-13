/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_intptrdup.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lvergero <lvergero@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/12 13:09:25 by lvergero          #+#    #+#             */
/*   Updated: 2015/01/12 13:17:28 by lvergero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./libft.h"

int		*ft_intptrdup(int const *t1)
{
	int		*dup;
	int		i;
	int		l;

	if (t1 == NULL)
		return (NULL);
	l = (sizeof(t1) / sizeof(t1[0]));
	if ((dup = (int*)malloc(sizeof(int) * l)) == NULL)
		return (NULL);
	i = 0;
	while (i < l)
	{
		dup[i] = t1[i];
		i++;
	}
	return (dup);
}