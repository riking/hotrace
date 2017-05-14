/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_entries.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyork <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/13 13:22:37 by kyork             #+#    #+#             */
/*   Updated: 2017/05/14 15:49:11 by kyork            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "hotrace.h"
#include <stdlib.h>

#define DONT_FREE(x)

int			read_entries(t_race *r)
{
	int			status;
	t_entry		e;

	e.next = 0;
	while ((status = get_next_line0(&e.key, 0)) == 1)
	{
		if (sse_strcmp(e.key, "") == 0)
			break ;
		if (get_next_line0(&e.value, 0) != 1)
		{
			DONT_FREE(e.key);
			return (1);
		}
		ft_ary_append(&r->init_read, &e);
	}
	DONT_FREE(e.key);
	if (status == 1)
		return (0);
	return (1);
}
