/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lvergero <lvergero@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/21 22:39:18 by lvergero          #+#    #+#             */
/*   Updated: 2014/12/03 15:13:34 by lvergero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

/*
*** SYSTEM LIBRARIES
*/
# include <mlx.h>

/*
*** LIBFT HEADER
*/
# include "../libft/libft.h"
# include "./get_next_line.h"

/*
*** STRUCTURE
*/
typedef struct 			s_env
{
	void				*mlx;
	void				*win;
}						t_env;

typedef struct 			s_map
{
	int					vert;
	char				*content;
	char 				**array_con;
	int 				con_len;
	int					**values;
	int 				val_li_len;
}						t_map;

typedef struct 			s_tmp
{
	char				**line;
	int					len;
	struct s_tmp		*next;
	struct s_tmp		*prev;	
}						t_tmp;

/*
*** FUNCTIONS
*/
t_map	*get_map(int fd, char **line);
//int 	**get_values(t_tmp *content, t_map *map);
int		get_values_count_per_line(t_map *map);
int		get_next_line(int const fd, char **line);
int 	parse_values_count(t_map *map, int flag, int count);
char	*read_input(int fd, char **line, t_map *map);

#endif
