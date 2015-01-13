/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   struct_init.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lvergero <lvergero@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/12/31 16:06:25 by lvergero          #+#    #+#             */
/*   Updated: 2015/01/13 15:13:30 by lvergero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

t_map	*t_map_init(t_map *new_row)
{
	if ((new_row = (t_map*)malloc(sizeof(t_map))) == NULL ||
		(new_row->row_split = (char**)malloc(sizeof(char*))) == NULL ||
		(new_row->row_val = (int*)malloc(sizeof(int))) == NULL)
		return (NULL);
	new_row->row_len = 0;
	new_row->nxt = NULL;
	new_row->prv = NULL;
	return (new_row);
}

t_print	*t_print_init(t_print *master)
{
	if ((master = (t_print*)malloc(sizeof(t_print))) == NULL ||
		(master->rd = t_map_init(master->rd)) == NULL ||
		(master->name = (char*)malloc(sizeof(char))) == NULL)
		return (NULL);
	master->max_hei = 0;
	master->min_hei = 0;
	master->max_row = 0;
	return (master);
}

t_draw 	*t_draw_init(t_draw *val, int hei)
{
	if ((val = (t_draw*)malloc(sizeof(t_draw))) == NULL ||
		(val->x = (int**)malloc(sizeof(int*) * hei)) == NULL ||
		(val->h = (int**)malloc(sizeof(int*) * hei)) == NULL ||
		(val->y = (int**)malloc(sizeof(int*) * hei)) == NULL ||
		(val->len = (int*)malloc(sizeof(int) * hei)) == NULL)
		return (NULL);
	val->hei = 0;
	val->max_x = 0;
	val->max_y = 0;
	val->tmpx = 0;
	val->tmpy = 0;
	val->pile = 0;
	val->x_inc = 0;
	val->y_inc = 0;
	val->dx = 0;
	val->dy = 0;
	return (val);
}

t_draw	*to_t_draw(t_print *m, t_draw *val)
{
	int		i;
	int		j;

	val->hei = m->map_hei;
	j = 0;
	while (j < m->map_hei)
	{
		i = 0;
		if ((val->x[j] = (int*)malloc(sizeof(int) * m->rd->row_len)) == NULL ||
			(val->h[j] = (int*)malloc(sizeof(int) * m->rd->row_len)) == NULL ||
			(val->y[j] = (int*)malloc(sizeof(int) * m->rd->row_len)) == NULL)
				return (NULL);
		while (i < m->rd->row_len)
		{
			val->x[j][i] = X0 - (j * m->side * cos(M_PI / 6)) + (i * m->side * cos(M_PI / 6));
			val->y[j][i] = Y0 + (j * m->side * sin(M_PI / 6)) + (i * m->side * sin(M_PI / 6)) - (m->rd->row_val[i] * m->exp);
			val->h[j][i] = m->rd->row_val[i] * 2;
			val->max_x = (val->x[j][i] > val->max_x) ? val->x[j][i] : val->max_x;
			val->max_y = (val->y[j][i] > val->max_y) ? val->y[j][i] : val->max_y;
			i++;
		}
		val->len[j] = m->rd->row_len;
		m->rd = m->rd->nxt;
		j++;
	}
	return (val);
}
