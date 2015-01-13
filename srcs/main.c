/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lvergero <lvergero@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/12/30 16:49:16 by lvergero          #+#    #+#             */
/*   Updated: 2015/01/13 14:28:54 by lvergero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

int		main(int ac, char **av)
{
	int		fd;
	t_print	*master;
	t_draw	*val;

	master = NULL;
	val = NULL;
	master = t_print_init(master);
	fd = (ac == 1) ? 0 : open(av[1], O_RDONLY);
	get_map(fd, master);
	master->name = (ac == 1) ? ft_strdup("FROM STDIN") : ft_strdup(av[1]);
	master->f_points = (ac >= 3 && ft_strcmp("POINTS", av[2]) == 0) ? 1 : 0;
	master->exp = find_exp(master->max_hei, master->min_hei);
	master->side = find_side(master);
	if (master->exp > (master->side / 3))
		master->exp = 2;
	val = t_draw_init(val, master->map_hei);
	val = to_t_draw(master, val);
	open_mlx(master, val);
	return (0);
}
