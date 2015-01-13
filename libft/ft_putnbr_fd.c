/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lvergero <lvergero@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/06 14:09:16 by lvergero          #+#    #+#             */
/*   Updated: 2015/01/03 17:24:58 by lvergero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./libft.h"

void	ft_putnbr_fd(int i, int fd)
{
	unsigned int	k;

	k = (i < 0) ? (unsigned int)-i : (unsigned int)i;
	if (i < 0)
		ft_putchar_fd('-', fd);
	if (k > 9)
	{
		ft_putnbr_fd(k / 10, fd);
		ft_putnbr_fd(k % 10, fd);
	}
	if (k < 10)
		ft_putchar_fd(k + '0', fd);
	return ;
}
