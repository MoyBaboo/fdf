/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lvergero <lvergero@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/06 17:08:20 by lvergero          #+#    #+#             */
/*   Updated: 2015/01/13 14:27:39 by lvergero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

/*
*** LIBRARIES
*/
# include <sys/types.h>
# include <sys/uio.h>
# include <unistd.h>
# include <fcntl.h>
# include "./libft.h"

/*
*** STRUCURES AND MACROS
*/
# define BUFF_SIZE	100
# define GNL_EOL	1
# define GNL_EOF	0
# define ERROR		-1

typedef struct		s_gnl
{
	int				fd;
	char			*tmp;
	char			*buf;
	struct s_gnl	*nxt;
	struct s_gnl	*prv;
}					t_gnl;

/*
*** FUNCTIONS
*/
int					get_next_line(int const fd, char **line);

#endif
