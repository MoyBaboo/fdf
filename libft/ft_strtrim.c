/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lvergero <lvergero@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/10/14 16:07:04 by lvergero          #+#    #+#             */
/*   Updated: 2014/10/14 16:07:06 by lvergero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./libft.h"

char	*ft_strtrim(char const *s)
{
	int		b;
	int		e;
	char	*str;

	b = 0;
	e = 0;
	if (!s)
		return (NULL);
	while ((s[b] == ' ' || s[b] == '\n' || s[b] == '\t') && (s[b]))
		b++;
	e = ft_strlen(s) - 1;
	while ((s[e] == ' ' || s[e] == '\n' || s[e] == '\t') && (b <= e))
		e--;
	str = ft_strsub(s, b, e - b + 1);
	return (str);
}
