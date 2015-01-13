/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_map.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lvergero <lvergero@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/12/31 16:09:05 by lvergero          #+#    #+#             */
/*   Updated: 2015/01/13 15:07:49 by lvergero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

int		find_side(t_print *m)
{
	int		x;
	int		y;

	x = 1800 / (m->max_row + 2);
	y = 1000 / (m->map_hei + 2);
	while (x > 2 || y > 2)
	{
		if (x >= y && (((m->map_hei * x) + (m->max_hei * m->exp)) < 1000))
			return (x);
		else if ((m->max_row * y) < 1800)
			return (y);
		x = (x - (x / 10));
		y = (y - (y / 10));
	}
	return (2);
}

int		find_exp(int max_h, int min_h)
{
	int		lvl;

	lvl = max_h - min_h;
	if (lvl < 11)
		return (7);
	if (lvl < 21)
		return (6);
	if (lvl < 41)
		return (5);
	if (lvl < 81)
		return (4);
	if (lvl < 161)
		return (2);
	return (1);
}

t_print	*get_t_print(char *tmp, t_print *m)
{
	int		i;

	m->rd->row_split = ft_strsplit(tmp, ' ');
	while (m->rd->row_split[m->rd->row_len])
		m->rd->row_len++;
	if (m->rd->row_len > m->max_row)
		m->max_row = m->rd->row_len;
	if ((m->rd->row_val =
		(int*)malloc(sizeof(int) * m->rd->row_len)) == NULL)
		exit (-1);
	i = 0;
	while (m->rd->row_split[i])
	{
		m->rd->row_val[i] = ft_atoi(m->rd->row_split[i]);
		if (m->rd->row_val[i] > m->max_hei)
			m->max_hei = m->rd->row_val[i];
		if (m->rd->row_val[i] < m->min_hei)
			m->min_hei = m->rd->row_val[i];
		i++;
	}
	return (m);
}

void	get_map(int fd, t_print *m)
{
	t_map	*save;
	int		ret;
	char	*tmp;
	//int 	i = 0;

	save = m->rd;
	if ((tmp = (char*)malloc(sizeof(char))) == NULL)
		exit (-1);
	while ((ret = get_next_line(fd, &tmp)) > 0)
	{
		m->rd = (m->rd->nxt == NULL) ? m->rd : m->rd->nxt;
		m = get_t_print(tmp, m);
		m->rd->row_nb = (m->rd->prv == NULL) ?
		0 : ((m->rd->prv->row_nb) + 1);
		m->rd->nxt = t_map_init(m->rd->nxt);
		m->rd->nxt->prv = m->rd;
	//	ft_putnbrendl(i++);
	}
	m->rd->nxt = NULL;
	m->map_hei = (m->rd->row_nb + 1);
	m->rd = save;
}
