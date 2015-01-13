/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_striteri.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lvergero <lvergero@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/10/13 21:03:35 by lvergero          #+#    #+#             */
/*   Updated: 2014/10/13 21:03:37 by lvergero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./libft.h"

void	ft_striteri(char *s, void (*f)(unsigned int, char *))
{
	int		i;

	if (s == NULL || (*f) == NULL)
		return ;
	i = 0;
	while (s[i] != '\0')
	{
		(f)(i, &(s[i]));
		i++;
	}
	return ;
}
