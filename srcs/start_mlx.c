/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   start_mlx.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lvergero <lvergero@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/08 19:00:14 by lvergero          #+#    #+#             */
/*   Updated: 2015/01/13 14:14:11 by lvergero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

void	draw_mlx_points(void *win, void *mlx, t_draw *val, t_print *master)
{
	int		i;
	int		j;

	j = 0;
	while (j < master->map_hei)
	{
		i = 0;
		while (i < val->len[j])
		{
			mlx_pixel_put(win, mlx, val->x[j][i], val->y[j][i], 7000000);
			mlx_pixel_put(win, mlx, val->x[j][i] + 1, val->y[j][i], 7000000);
			mlx_pixel_put(win, mlx, val->x[j][i] - 1, val->y[j][i], 7000000);
			mlx_pixel_put(win, mlx, val->x[j][i], val->y[j][i] + 1, 7000000);
			mlx_pixel_put(win, mlx, val->x[j][i], val->y[j][i] - 1, 7000000);
			i++;
		}
		j++;
	}
	return ;
}

void	open_mlx(t_print *master, t_draw *val)
{
	t_env	e;

	e.mlx = mlx_init();
	e.win = mlx_new_window(e.mlx, (val->max_x + (master->side * 2)),
		(val->max_y + (master->side * 2)), master->name);
	e.master = master;
	e.val = val;
	mlx_key_hook(e.win, key_hook, &e);
	mlx_expose_hook(e.win, expose_hook, &e);
	mlx_loop(e.mlx);
	return ;
}
