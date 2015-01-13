/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lvergero <lvergero@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/21 22:39:08 by lvergero          #+#    #+#             */
/*   Updated: 2014/12/30 16:24:59 by lvergero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

#        include <stdio.h>

int		main(int ac, char **av)
{
	int		fd;
	char	**line;
	t_map	*map;
//	int		i;
//	int		j;

	if (!(line = (char**)malloc(sizeof(char*))))
		return (FAILURE);
	fd = (ac == 1) ? 0 : open(av[1], O_RDONLY);
	map = get_map(fd, line);
	ft_putendl(map->content);
//	i = 0;
	close(fd);
/*	i = 0;
	j = 0;
	while (map->values[i])
	{
		printf("map->values[%d] is : \n", i);
		while (map->values[i][j])
		{
			printf("%d  ", map->values[i][j]);
			j++;
		}
		ft_putchar('\n');
		j = 0;
		i++;
	}*/
	return (0);
}
