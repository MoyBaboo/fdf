/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lvergero <lvergero@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/10/13 21:05:01 by lvergero          #+#    #+#             */
/*   Updated: 2014/10/13 21:05:03 by lvergero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./libft.h"

char	*ft_strmap(char const *s, char (*f)(char))
{
	int		i;
	int		l;
	char	*snew;

	if (s == NULL || (*f) == NULL)
		return (NULL);
	i = 0;
	l = ft_strlen(s);
	if ((snew = (char *)malloc(sizeof(char) * (l + 1))) == NULL)
		return (NULL);
	while (s[i] != '\0')
	{
		snew[i] = (f)(s[i]);
		i++;
	}
	snew[i] = '\0';
	return (snew);
}
