/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_entries.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyork <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/13 13:22:37 by kyork             #+#    #+#             */
/*   Updated: 2017/05/13 13:30:56 by kyork            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "hotrace.h"
#include <stdlib.h>

void		read_entries(t_race *r)
{
	char		*line;
	int			status;
	t_entry		e;

	e.next = 0;
	while (get_next_line0(&e.key) == 1)
	{
		if (sse_strcmp(line, "") == 0)
			break ;
		if (get_next_line0(&e.value) != 1)
			break ;
		ft_ary_append(&r->init_read, &e);
	}
	free(e.key);
}
