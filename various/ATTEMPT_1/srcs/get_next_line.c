/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lvergero <lvergero@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/10/16 13:49:42 by lvergero          #+#    #+#             */
/*   Updated: 2014/11/28 20:22:44 by lvergero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/get_next_line.h"

static int		find_eol(t_read *rd)
{
	int		ret_len;
	int		rem_len;

	while (rd->li[rd->nd] != '\n' && rd->li[rd->nd] != '\0')
		rd->nd++;
	if ((rd->li[rd->nd] == '\n') || (rd->li[rd->nd] == '\0' && rd->r_fg == 1))
	{
		ret_len = rd->nd;
		rem_len = ft_strlen(rd->li) - ret_len;
		if ((rd->ret = (char *)malloc(sizeof(char) * (ret_len + 1))) == NULL)
			return (-2);
		rd->ret = ft_strncpy(rd->ret, rd->li, ret_len);
		rd->li = ft_strsub(rd->li, (rd->nd + 1), rem_len);
		return (LINE_READ);
	}
	return (FAILED);
}

static t_read	*struct_init(t_read *rd, int const fd)
{
	if (rd == NULL)
	{
		if ((rd = (t_read *)malloc(sizeof(t_read))) == NULL ||
			(rd->buf = (char *)malloc(sizeof(char) * BUF_SIZE)) == NULL ||
			(rd->li = (char *)malloc(sizeof(char) * 1)) == NULL)
			return (NULL);
		rd->r_fg = 0;
		rd->r_fd = fd;
		rd->next = NULL;
		rd->prev = NULL;
	}
	if (rd->r_fd != fd)
	{
		while (rd->prev != NULL && rd->r_fd != fd)
			rd = rd->prev;
		if (rd->r_fd == fd)
			return (rd);
		while (rd->next != NULL && rd->r_fd != fd)
			rd = rd->next;
		if (rd->r_fd == fd)
			return (rd);
		rd->next = struct_init(rd->next, fd);
		rd->next->prev = rd;
	}
	return ((rd->next == NULL) ? rd : rd->next);
}

static int		error_display(int const fd, t_read *rd, int ret_r)
{
	if (rd == NULL)
	{
		ft_putendl("Malloc failed to allocate sufficient memory; try again");
		return (FAILED);
	}
	if (fd < 0)
	{
		ft_putendl("File descriptor is invalid (must be greater than 0)");
		return (FAILED);
	}
	if (BUF_SIZE < 1)
	{
		ft_putendl("BUF_SIZE defined in get_next_line.h must be over 0");
		return (FAILED);
	}
	if (ret_r == -1)
	{
		ft_putendl("read(2) has failed; check your open(2) and close(2)");
		return (FAILED);
	}
	return (SUCCESS);
}

static int		struct_mem(t_read *rd)
{
	free(rd->li);
	free(rd->buf);
	free(rd->ret);
	if (rd->prev != NULL)
		rd->prev->next = rd->next;
	if (rd->next != NULL)
		rd->next->prev = rd->prev;
	free(rd);
	return (TO_END);
}

int				get_next_line(int const fd, char **line)
{
	int				ret_eol;
	int				ret_r;
	static t_read	*rd = NULL;

	if (rd == NULL || rd->r_fd != fd)
		rd = struct_init(rd, fd);
	rd->nd = 0;
	ret_r = 0;
	if ((error_display(rd->r_fd, rd, ret_r)) == FAILED)
		return (FAILED);
	while ((ret_eol = find_eol(rd)) == FAILED)
	{
		if ((ret_r = read(rd->r_fd, rd->buf, BUF_SIZE)) == -1)
			return (error_display(rd->r_fd, rd, ret_r));
		rd->li = ft_strjoin(rd->li, rd->buf);
		ft_strclr(rd->buf);
		if (ret_r == 0)
			rd->r_fg = 1;
	}
	*line = (rd->ret);
	ret_r = (ft_strcmp(rd->li, rd->ret) == 0 && rd->r_fg == 1) ?
	struct_mem(rd) : LINE_READ;
	return (ret_r);
}
