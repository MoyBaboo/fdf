/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lvergero <lvergero@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/10/13 16:36:27 by lvergero          #+#    #+#             */
/*   Updated: 2014/11/07 21:54:29 by lvergero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./libft.h"

int		ft_atoi(const char *str)
{
	int				i;
	unsigned int	ret;
	int				sign;

	i = 0;
	ret = 0;
	sign = 1;
	while (str[i] == ' ' || str[i] == '\t' || str[i] == '\n' || str[i] == '\v'
		|| str[i] == '\r' || str[i] == '\f' || str[i] == '\b')
		i++;
	if (str[i] == '+' || str[i] == '-')
	{
		sign = (str[i] == '-') ? -1 : 1;
		i++;
	}
	while (str[i] != '\0' && ft_isdigit(str[i]) == SUCCESS)
	{
		ret = (ret * 10) + (str[i] - 48);
		i++;
	}
	return ((ret * sign));
}
