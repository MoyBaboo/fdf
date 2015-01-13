/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lvergero <lvergero@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/06 17:08:12 by lvergero          #+#    #+#             */
/*   Updated: 2015/01/10 20:11:28 by lvergero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static int		error_display(int fd, char **line, int ret, int bufsz)
{
	if (fd < 0)
	{
		ft_putstr("File descriptor must be 0 or greater ; your fd was : ");
		ft_putnbrendl(fd);
	}
	if (line == NULL)
		ft_putendl("The line you sent was uninitialized (line == NULL)");
	if (ret == -1)
		ft_putendl("read(2) has failed; check your open(2)");
	if (bufsz < 1)
	{
		ft_putstr("read(2)'s nbytes must be 1 or greater ; your nbytes was : ");
		ft_putnbrendl(bufsz);
	}
	return (ERROR);
}

static int		eof_or_l(t_gnl *gnl, char **line, int flag)
{
	char	*eol;

	gnl->tmp = ft_strjoin(gnl->tmp, gnl->buf);
	ft_strclr(gnl->buf);
	if (flag == BUFF_SIZE && (eol = ft_strchr(gnl->tmp, '\n')) != NULL)
	{
		*line = ft_strsub(gnl->tmp, 0, (ft_strlen(gnl->tmp) - ft_strlen(eol)));
		gnl->tmp = ft_strsub(eol, 1, (ft_strlen(eol)));
		return (GNL_EOL);
	}
	if (flag != BUFF_SIZE && (eol = ft_strchr(gnl->tmp, '\n')) != NULL)
	{
		*line = ft_strsub(gnl->tmp, 0, (ft_strlen(gnl->tmp) - ft_strlen(eol)));
		gnl->tmp = ft_strsub(eol, 1, (ft_strlen(eol)));
		return (GNL_EOL);
	}
	if (flag != BUFF_SIZE && (eol = ft_strchr(gnl->tmp, '\n')) == NULL)
	{
		*line = gnl->tmp;
		return (GNL_EOF);
	}
	return (-1);
}

static t_gnl	*struct_init(t_gnl *gnl, int fd)
{
	if (gnl == NULL)
	{
		if ((gnl = (t_gnl*)malloc(sizeof(t_gnl))) == NULL ||
			(gnl->buf = (char*)malloc(sizeof(char) * BUFF_SIZE)) == NULL ||
			(gnl->tmp = (char*)malloc(sizeof(char))) == NULL)
			return (NULL);
		gnl->fd = fd;
		gnl->prv = NULL;
		gnl->nxt = NULL;
		return (gnl);
	}
	while (gnl->prv != NULL && gnl->fd != fd)
		gnl = gnl->prv;
	while (gnl->nxt != NULL && gnl->fd != fd)
		gnl = gnl->nxt;
	if (gnl->fd == fd)
		return (gnl);
	gnl->nxt = struct_init(gnl->nxt, fd);
	gnl->nxt->prv = gnl;
	return (gnl->nxt);
}

int				get_next_line(int const fd, char **line)
{
	static t_gnl	*gnl = NULL;
	int				ret;

	if (fd < 0 || line == NULL || BUFF_SIZE < 1)
		return (error_display(fd, line, 0, BUFF_SIZE));
	gnl = (gnl == NULL || gnl->fd != fd) ? struct_init(gnl, fd) : gnl;
	ft_strclr(*line);
	while ((ret = read(fd, gnl->buf, BUFF_SIZE)) == BUFF_SIZE)
	{
		if (eof_or_l(gnl, line, ret) == GNL_EOL)
			return (GNL_EOL);
	}
	if (ret == -1 || gnl == NULL)
		return (error_display(fd, line, 0, BUFF_SIZE));
	return (eof_or_l(gnl, line, ret));
}
