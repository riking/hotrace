/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   slab_dup.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyork <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/14 15:25:43 by kyork             #+#    #+#             */
/*   Updated: 2017/05/14 18:24:43 by kyork            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lib.h"
#include "../sse/str.h"
#include <stdlib.h>

static t_slab	*g_cur_slab;

static void		slab_next(void)
{
	void	*ptr;
	t_slab	*s;

	ptr = malloc(SLAB_SIZE);
	s = ptr;
	s->next = g_cur_slab;
	s->cur = ((char*)ptr) + sizeof(t_slab) + SLAB_ALIGN;
	g_cur_slab = s;
}

char			*slab_dup(const char *str)
{
	size_t	len;
	char	*end;
	char	*start;

	if (!g_cur_slab)
		slab_next();
	len = 0;
	end = ((char*)g_cur_slab) + SLAB_SIZE - 24;
	start = g_cur_slab->cur;
	while (str[len] && (g_cur_slab->cur < end))
		*g_cur_slab->cur++ = str[len++];
	if (str[len])
	{
		slab_next();
		return (sse_strdup(str));
	}
	*g_cur_slab->cur++ = 0;
	while (((uintptr_t)g_cur_slab->cur) & (SLAB_ALIGN - 1))
		g_cur_slab->cur++;
	return (start);
}

void			slab_free(void)
{
	t_slab	*s;
	t_slab	*next;

	s = g_cur_slab;
	while (s)
	{
		next = s->next;
		free(s);
		s = next;
	}
}
