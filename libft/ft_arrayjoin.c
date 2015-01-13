/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_arrayjoin.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lvergero <lvergero@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/03 16:23:53 by lvergero          #+#    #+#             */
/*   Updated: 2015/01/03 17:19:02 by lvergero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./libft.h"

char	**ft_arrayjoin(char const **t1, char const **t2)
{
	char	**join;
	int		len1;
	int		len2;
	int		i;

	if (t1 == NULL || t2 == NULL)
		return (t1 == NULL) ? ft_arraydup(t2) : ft_arraydup(t1);
	len1 = 0;
	len2 = 0;
	while (t2[len2] || t1[len1])
		(t1[len1]) ? len1++ : len2++;
	if ((join = (char **)malloc(sizeof(char*) * (len1 + len2 + 1))) == NULL)
		return (NULL);
	i = 0;
	while ((i - len1) < len2)
	{
		join[i] = (i < len1) ? ft_strdup(t1[i]) : ft_strdup(t2[i - len1]);
		i++;
	}
	join[i] = 0;
	return (join);
}
