/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lvergero <lvergero@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/12 19:19:32 by lvergero          #+#    #+#             */
/*   Updated: 2015/01/13 14:23:18 by lvergero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

int		expose_hook(t_env *e)
{
	if (e->master->f_points == 1)
		draw_mlx_points(e->mlx, e->win, e->val, e->master);
	draw_mlx_horiz(e->mlx, e->win, e->val, e->master);
	draw_mlx_vert(e->mlx, e->win, e->val, e->master);
	return (0);
}

int		key_hook(int keycode, t_env *e)
{
	if (!e)
	{
		ft_putstr("nope");
		exit (-1);
	}
	ft_putnbrendl(keycode);
	if (keycode == 65307)
		exit (0);
	if (keycode == 65362)
	{
		e->master->exp += 1;
		open_mlx(e->master, e->val);
	}
	return (0);
}
