/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putendl_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lvergero <lvergero@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/06 14:13:46 by lvergero          #+#    #+#             */
/*   Updated: 2014/11/06 14:13:48 by lvergero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./libft.h"

void	ft_putendl_fd(char const *s, int fd)
{
	int		l;

	l = ft_strlen(s);
	write(fd, s, l);
	ft_putchar_fd('\n', fd);
	return ;
}
