/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lvergero <lvergero@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/12/30 16:50:08 by lvergero          #+#    #+#             */
/*   Updated: 2015/01/13 14:20:35 by lvergero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include <mlx.h>
# include <math.h>
# include "../libft/libft.h"

/*
*** STRUCTURES AND MACROS
*/

# define X0			m->side + (m->map_hei * m->side * cos(M_PI / 6))
# define Y0			m->side + ((m->max_hei - m->min_hei) * m->exp)

typedef struct		s_print
{
	char			*name;
	struct s_map	*rd;
	int				max_hei;
	int				min_hei;
	int				map_hei;
	int				max_row;
	int				side;
	int				exp;
	int 			f_points;
}					t_print;

typedef struct		s_map
{
	int				row_nb;
	int				row_len;
	char			**row_split;
	int				*row_val;
	struct s_map	*nxt;
	struct s_map	*prv;
}					t_map;

typedef struct		s_draw
{
	int				**x;
	int				**y;
	int				**h;
	int				*len;
	int				tmpx;
	int				tmpy;
	int				x_inc;
	int				y_inc;
	int				max_x;
	int				max_y;
	int				hei;
	int				pile;
	int				dx;
	int				dy;
}					t_draw;

typedef struct		s_env
{
	void			*win;
	void			*mlx;
	t_print			*master;
	t_draw			*val;
}					t_env;

/*
*** EXEC FUNCTIONS PROTOTYPES
*/
int					find_exp(int max_h, int min_h);
int					find_side(t_print *master);
void				get_map(int fd, t_print *master);
t_draw				*t_draw_init(t_draw *val, int hei);
t_map				*t_map_init(t_map *new_row);
t_draw				*to_t_draw(t_print *master, t_draw *val);
t_print				*t_print_init(t_print *master);

/*
*** DISPLAY FUNCTIONS PROTOTYPES
*/
void				draw_mlx_horiz(void *win, void *mlx, t_draw *val, t_print *master);
void				draw_mlx_points(void *win, void *mlx, t_draw *val, t_print *master);
void				draw_mlx_vert(void *win, void *mlx, t_draw *val, t_print *master);
void				open_mlx(t_print *master, t_draw *val);

/*
*** MLX EVENTS FUNCTIONS PROTOTYPES
*/
int					key_hook(int keycode, t_env *e);
int					expose_hook(t_env *e);

#endif
