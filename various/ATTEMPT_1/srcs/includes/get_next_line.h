/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lvergero <lvergero@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/10/16 20:44:42 by lvergero          #+#    #+#             */
/*   Updated: 2014/11/28 20:21:00 by lvergero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

/*
*** SYSTEM LIBRARIES
*/
# include <sys/types.h>
# include <sys/uio.h>
# include <fcntl.h>

/*
*** CUSTOM LIBRARY
*/
# include "../libft/libft.h"

/*
*** MACROS
*/
# define LINE_READ		1
# define TO_END			0
# define FAILED			-1
# define M_FAILED		-2
# define BUF_SIZE		3

/*
*** STRUCTURE
*/
typedef struct			s_read
{
	char				*buf;
	char				*li;
	char				*ret;
	int					nd;
	int					r_fg;
	int					r_fd;
	struct s_read		*next;
	struct s_read		*prev;
}						t_read;

/*
*** FUNCTION PROTOTYPE
*/
int						get_next_line(int const fd, char **line);

#endif
