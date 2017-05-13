/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyork <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/21 11:39:50 by kyork             #+#    #+#             */
/*   Updated: 2017/05/13 15:02:27 by kyork            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lib.h"
#include <unistd.h>

static char		g_buf[256];
static int		g_used_buf;

void	ft_putstr(char const *str)
{
	size_t	len;

	len = 0;
	while (str[len])
	{
		if (g_used_buf == 256)
		{
			write(1, g_buf, 256);
			g_used_buf = 0;
		}
		g_buf[g_used_buf++] = str[len++];
	}
}

void	flush_stdout(void)
{
	if (g_used_buf)
		write(1, g_buf, g_used_buf);
	g_used_buf = 0;
}
