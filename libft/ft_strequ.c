/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strequ.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lvergero <lvergero@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/10/14 15:47:03 by lvergero          #+#    #+#             */
/*   Updated: 2014/10/14 15:47:05 by lvergero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./libft.h"

int		ft_strequ(char const *s1, char const *s2)
{
	int		i;

	if (s1 == NULL || s2 == NULL)
		return (FAILURE);
	i = 0;
	while (s1[i] != '\0' && s2[i] != '\0')
	{
		if (s1[i] != s2[i])
			return (FAILURE);
		i++;
	}
	if (s1[i] != s2[i])
		return (FAILURE);
	return (SUCCESS);
}
