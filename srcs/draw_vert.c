/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_vert.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lvergero <lvergero@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/12 18:06:53 by lvergero          #+#    #+#             */
/*   Updated: 2015/01/13 14:13:22 by lvergero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

static void		vert_init(t_draw *val, int i, int j)
{
	val->dx = val->x[j + 1][i] - val->x[j][i];
	val->dy = (val->y[j + 1][i] - val->y[j][i]);
	val->tmpx = val->x[j][i];
	val->tmpy = val->y[j][i];
	val->x_inc = (val->dx > 0) ? 1 : -1;
	val->y_inc = (val->dy > 0) ? 1 : -1;
	val->pile = ((val->x_inc * val->dx) > (val->y_inc * val->dy)) ?
	(val->x_inc * val->dx) / 2 : (val->y_inc * val->dy) / 2;
	return ;
}

static void		vert_dy_bigger(t_draw *val)
{
	if ((val->pile += (val->x_inc * val->dx)) >= (val->y_inc * val->dy))
		val->tmpx += val->x_inc;
	val->tmpy += val->y_inc;
	val->pile = (val->pile >= (val->y_inc * val->dy)) ?
	(val->pile - (val->y_inc * val->dy)) : val->pile;
	return ;
}

static void		vert_dx_bigger(t_draw *val)
{
	if ((val->pile += (val->y_inc * val->dy)) >= (val->x_inc * val->dx))
		val->tmpy += val->y_inc;
	val->tmpx += val->x_inc;
	val->pile = (val->pile >= (val->x_inc * val->dx)) ?
	(val->pile - (val->x_inc * val->dx)) : val->pile;
	return ;
}

void			draw_mlx_vert(void *win, void *mlx, t_draw *val, t_print *m)
{
	int		i;
	int		j;

	j = 0;
	while ((j + 1) < m->map_hei)
	{
		i = 0;
		while (i < val->len[j + 1])
		{
			vert_init(val, i, j);
			while (val->tmpx >= val->x[j + 1][i])
			{
				mlx_pixel_put(win, mlx, val->tmpx, val->tmpy, 12000000);
				if ((val->x_inc * val->dx) > (val->y_inc * val->dy))
					vert_dx_bigger(val);
				else if ((val->y_inc * val->dy) >= (val->x_inc * val->dx))
					vert_dy_bigger(val);
			}
			i++;
		}
		j++;
	}
	return ;
}
