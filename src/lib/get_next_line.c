/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyork <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/26 12:34:56 by kyork             #+#    #+#             */
/*   Updated: 2017/05/13 15:18:59 by kyork            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lib.h"
#include "../ary/ft_ary.h"
#include "../sse/str.h"
#include "get_next_line_private.h"
#include <stdlib.h>
#include <unistd.h>

#define GRSZ_A(s) ((s)->chars.item_count + BUFF_SIZE)
#define GRSZ_B(s) ((s)->chars.item_cap * 2)
#define GROW_SIZE(s) MAX(GRSZ_A(s), GRSZ_B(s))
#define MAX(a,b) ((a)>(b)?(a):(b))

static t_gnl_fd	g_fd0 = {0, -1, {0, 1, 0, 1}};

ssize_t			gnl_read(t_gnl_fd *s)
{
	ssize_t read_ret;

	if (s->chars.item_cap < s->chars.item_count + BUFF_SIZE)
	{
		if (0 != ft_ary_grow(&s->chars, GROW_SIZE(s)))
			return (-1);
	}
	read_ret = read(s->fd, s->chars.item_count + (char*)s->chars.ptr,
			BUFF_SIZE);
	if (read_ret < 0)
		return (-1);
	if (read_ret == 0)
	{
		if (s->chars.item_count > 0)
		{
			s->nl_off = (ssize_t)s->chars.item_count;
			((char*)s->chars.ptr)[s->chars.item_count++] = 0;
			return (-2);
		}
		s->nl_off = -1;
		return (0);
	}
	s->chars.item_count += (size_t)read_ret;
	return (1);
}

static int		gnl_next(t_gnl_fd *s)
{
	char	*c;
	ssize_t	read_ret;

	if (0 != ft_ary_remove_mul(&s->chars, 0, (size_t)(s->nl_off + 1)))
		return (-1);
	while (1)
	{
		c = s->chars.ptr;
		while (c < ((char*)s->chars.ptr + s->chars.item_count) && *c != '\n')
			c++;
		if (c < ((char*)s->chars.ptr + s->chars.item_count) && *c == '\n')
		{
			s->nl_off = (c - (char*)s->chars.ptr);
			*c = 0;
			return (1);
		}
		read_ret = gnl_read(s);
		if (read_ret == -1 || read_ret == 0)
			return ((int)read_ret);
		if (read_ret == -2)
			return (1);
	}
}

int				get_next_line0(char **line)
{
	t_gnl_fd	*s;
	int			status;

	if (!line)
		return (-1);
	s = &g_fd0;
	if (!s->chars.ptr)
	{
		s->nl_off = -1;
		s->chars = ft_ary_create(sizeof(char));
	}
	status = gnl_next(s);
	if (status == 1)
		*line = sse_strdup(s->chars.ptr);
	else
	{
		*line = 0;
		ft_ary_destroy(&(s->chars));
		s->chars.ptr = 0;
		s->nl_off = -1;
	}
	return (status);
}

int				gnl_have_buffer(void)
{
	t_gnl_fd	*s;
	char		*c;

	s = &g_fd0;
	if (!s->chars.ptr || s->nl_off == -1)
		return (0);
	c = s->chars.ptr + s->nl_off;
	while (c < ((char*)s->chars.ptr + s->chars.item_count) && *c != '\n')
		c++;
	if (c < ((char*)s->chars.ptr + s->chars.item_count) && *c == '\n')
		return (1);
	return (0);
}
