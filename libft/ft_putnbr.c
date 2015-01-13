/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lvergero <lvergero@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/10/13 16:38:24 by lvergero          #+#    #+#             */
/*   Updated: 2015/01/03 15:13:53 by lvergero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./libft.h"

void	ft_putnbr(int i)
{
	unsigned int	k;

	k = (i < 0) ? (unsigned int)-i : (unsigned int)i;
	if (i < 0)
		ft_putchar('-');
	if (k > 9)
	{
		ft_putnbr(k / 10);
		ft_putnbr(k % 10);
	}
	if (k < 10)
		ft_putchar(k + '0');
	return ;
}
