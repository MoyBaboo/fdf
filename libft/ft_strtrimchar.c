/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrimchar.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lvergero <lvergero@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/03 15:44:48 by lvergero          #+#    #+#             */
/*   Updated: 2015/01/03 15:49:19 by lvergero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./libft.h"

char	*ft_strtrimchar(char const *s, char c)
{
	int		b;
	int		e;
	char	*str;

	b = 0;
	e = 0;
	if (!s)
		return (NULL);
	while (s[b] == c)
		b++;
	if (s[b] == '\0')
		return (NULL);
	e = ft_strlen(s) - 1;
	while (s[e] == c)
		e--;
	str = ft_strsub(s, b, e - b + 1);
	return (str);
}
