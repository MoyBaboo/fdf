/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_map.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lvergero <lvergero@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/23 15:36:25 by lvergero          #+#    #+#             */
/*   Updated: 2014/12/30 16:32:47 by lvergero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

int		**get_values(t_map *map)
{
	char	**maploc;
	char	**tmp;
	int 	**array;
	int 	i;
	int 	j;

	if ((array = (int **)malloc(sizeof(int*) * map->vert)) == NULL)
		exit (FAILURE);
	maploc = ft_strsplit(map->content, '\n');
	i = 0;
	while (i < map->vert)
	{
		if ((array[i] = (int *)malloc(sizeof(int) * map->val_li_len)) == NULL)
			exit (FAILURE);
		j = 0;
		tmp = ft_strsplit(maploc[i], ' ');
		ft_putendl
		j = 0;
		ft_putstr(tmp[map->val_li_len]);
		while (j < map->val_li_len)
		{
			array[i][j] = ft_atoi(tmp[j]);
			ft_putnbr(array[i][j]);
			ft_putchar('\t');
			j++;
		}
		ft_putchar('\n');
		j = 0;
		i++;
	}
	i = 0;
	return (array);
}

int 	parse_values_count(t_map *map, int flag, int count)
{
	int 	ck;
	int 	i;

	ck = 0;
	i = 0;
	if (flag == map->vert)
		return (FAILURE);
	flag *= map->con_len;
	while (i < map->con_len)
	{
		if (ft_isdigit(map->content[flag + i]) == SUCCESS)
		{
			ck++;
			while (ft_isdigit(map->content[flag + i]) == SUCCESS)
				i++;
		}
		if (i < map->con_len)
			i++;
	}
	if (ck != count)
	{
		ft_putendl("All lines must have the same number of values");
		exit (FAILURE);
	}
	return (SUCCESS);
}

int		get_values_count_per_line(t_map *map)
{
	int 	count;
	int 	i;
	int 	flag;

	count = 0;
	i = 0;
	while (i < map->con_len)
	{
		if (ft_isdigit(map->content[i]) == SUCCESS)
		{
			count++;
			while (ft_isdigit(map->content[i]) == SUCCESS)
				i++;
		}
		if (i < map->con_len)
			i++;
	}
	flag = 1;
	while (parse_values_count(map, flag, count) == SUCCESS)
		flag++;
	return (count); 
}

char	*read_input(int fd, char **line, t_map *map)
{
	char	*content;
	char	sp[2] = "\n";
	int 	len;

	content = ft_strnew(0);
	map->vert = 0;
	while (get_next_line(fd, line) != TO_END)
	{
		*line = ft_strjoin(*line, sp);
		content = ft_strjoin(content, *line);
		len = ft_strlen(*line);
		if (map->vert == 0)
			map->con_len = len;
		else if (len != map->con_len || len == 0)
		{
			len == 0 ?
			ft_putendl("Map is invalid: must be at least one unit wide") :
			ft_putendl("Map is invalid: not all lines are the same length");
			exit (FAILURE);
		}
		map->vert++;
	}
	return (content);
}

t_map	*get_map(int fd, char **line)
{
	t_map		*map;
//	int i = 0;

	if ((map = (t_map*)malloc(sizeof(t_map))) == NULL ||
		(map->content = (char*)malloc(sizeof(char))) == NULL)
		return (NULL);
	map->content = read_input(fd, line, map);
	if (map->vert == 0)
	{
		ft_putendl("Map is invalid: must be at least one unit high");
		exit (-1);
	}
	map->array_con = ft_strsplit(map->content, '\n');
/*	while (map->array_con[i])
	{
		ft_putendl(map->array_con[i]);
		i++;
	}*/
	map->val_li_len = get_values_count_per_line(map);
	map->values = get_values(map);
	return (map);
}
