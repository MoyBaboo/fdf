/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_horiz.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lvergero <lvergero@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/12 17:57:49 by lvergero          #+#    #+#             */
/*   Updated: 2015/01/13 14:13:18 by lvergero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

static void		horiz_init(t_draw *val, int i, int j)
{
	val->tmpx = val->x[j][i];
	val->tmpy = val->y[j][i];
	val->dx = val->x[j][i + 1] - val->x[j][i];
	val->dy = (val->y[j][i + 1] - val->y[j][i]);
	val->x_inc = (val->dx > 0) ? 1 : -1;
	val->y_inc = (val->dy > 0) ? 1 : -1;
	val->pile = ((val->x_inc * val->dx) > (val->y_inc * val->dy)) ?
	(val->x_inc * val->dx) / 2 : (val->y_inc * val->dy) / 2;
}

static void		horiz_dy_bigger(t_draw *val)
{
	if ((val->pile += (val->x_inc * val->dx)) >= (val->y_inc * val->dy))
		val->tmpx += val->x_inc;
	val->tmpy += val->y_inc;
	val->pile = (val->pile >= (val->y_inc * val->dy)) ?
	(val->pile - (val->y_inc * val->dy)) : val->pile;
}

static void		horiz_dx_bigger(t_draw *val)
{
	if ((val->pile += (val->y_inc * val->dy)) >= (val->x_inc * val->dx))
		val->tmpy += val->y_inc;
	val->tmpx += val->x_inc;
	val->pile = (val->pile >= (val->x_inc * val->dx)) ?
	(val->pile - (val->x_inc * val->dx)) : val->pile;
	return ;
}

void			draw_mlx_horiz(void *win, void *mlx, t_draw *val, t_print *m)
{
	int		i;
	int		j;

	j = 0;
	while (j < m->map_hei)
	{
		i = 0;
		while ((i + 1) < val->len[j])
		{
			horiz_init(val, i, j);
			while (val->tmpx <= val->x[j][i + 1])
			{
				mlx_pixel_put(win, mlx, val->tmpx, val->tmpy, 12000000);
				if ((val->x_inc * val->dx) > (val->y_inc * val->dy))
					horiz_dx_bigger(val);
				else if ((val->y_inc * val->dy) >= (val->x_inc * val->dx))
					horiz_dy_bigger(val);
			}
			i++;
		}
		j++;
	}
	return ;
}
