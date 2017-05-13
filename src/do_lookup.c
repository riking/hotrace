/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   do_lookup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyork <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/13 13:48:28 by kyork             #+#    #+#             */
/*   Updated: 2017/05/13 15:03:05 by kyork            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "hotrace.h"
#include <stdlib.h>

static void	chase_lookup(t_entry *e, char *key)
{
	while (e)
	{
		if (0 == sse_strcmp(e->key, key))
		{
			ft_putstr(e->value);
			ft_putstr("\n");
			return ;
		}
		e = e->next;
	}
	ft_putstr(key);
	ft_putstr(": Not found.\n");
}

void		do_lookup(t_race *r)
{
	char		*line;
	int			status;
	uint32_t	hash;
	t_entry		*e;

	while ((status = get_next_line0(&line)) == 1)
	{
		hash = key_hash(line) & r->bucket_mask;
		e = *(t_entry**)ft_ary_get(&r->hash_table, hash);
		chase_lookup(e, line);
		free(line);
		flush_stdout();
	}
	free(line);
}
