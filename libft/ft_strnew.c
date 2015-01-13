/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lvergero <lvergero@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/10/13 16:39:56 by lvergero          #+#    #+#             */
/*   Updated: 2015/01/03 18:44:06 by lvergero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./libft.h"

char	*ft_strnew(size_t size)
{
	char	*s;

	if ((s = (char *)malloc(sizeof(char) * (size + 1))) == NULL)
		return (NULL);
	s = ft_memset(s, '\0', (size + 1));
	return (s);
}
