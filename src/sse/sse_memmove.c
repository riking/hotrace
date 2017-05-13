/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sse_memmove.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyork <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/21 09:29:10 by kyork             #+#    #+#             */
/*   Updated: 2017/05/13 10:59:11 by kyork            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "str.h"

static void	ft_memmove_backwards(void *dst, const void *src, size_t length)
{
	size_t		t;
	char		*d;
	char const	*s;

	d = dst;
	s = src;
	s += length;
	d += length;
	t = length / 1;
	while (t > 0)
	{
		s -= 1;
		d -= 1;
		*d = *s;
		t--;
	}
}

static void	ft_memmove_forwards(void *dst, const void *src, size_t length)
{
	size_t		t;
	char		*d;
	char const	*s;

	d = dst;
	s = src;
	t = length / 1;
	while (t > 0)
	{
		*d = *s;
		s += 1;
		d += 1;
		t--;
	}
}

void		sse_memmove(void *dst, void *src, size_t length)
{
	if (src < dst)
		ft_memmove_backwards(dst, src, length);
	else
		ft_memmove_forwards(dst, src, length);
}
