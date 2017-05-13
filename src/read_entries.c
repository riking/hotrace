/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_entries.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyork <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/13 13:22:37 by kyork             #+#    #+#             */
/*   Updated: 2017/05/13 16:29:33 by kyork            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "hotrace.h"
#include <stdlib.h>

int			read_entries(t_race *r)
{
	int			status;
	t_entry		e;

	e.next = 0;
	while ((status = get_next_line0(&e.key)) == 1)
	{
		if (sse_strcmp(e.key, "") == 0)
			break ;
		if (get_next_line0(&e.value) != 1)
		{
			free(e.key);
			return (1);
		}
		ft_ary_append(&r->init_read, &e);
	}
	free(e.key);
	if (status == 1)
		return (0);
	return (1);
}
