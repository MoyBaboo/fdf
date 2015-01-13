/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbrendl.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lvergero <lvergero@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/10 23:07:25 by lvergero          #+#    #+#             */
/*   Updated: 2015/01/13 14:50:35 by lvergero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./libft.h"

void ft_putnbrendl(int i)
{
	char	*nbr;

	nbr = ft_itoa(i);
	ft_putendl(nbr);
	return ;
}
