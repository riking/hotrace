/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   make_hash.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyork <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/13 13:30:04 by kyork             #+#    #+#             */
/*   Updated: 2017/05/13 13:32:54 by kyork            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "hotrace.h"

void		hash_insert(t_race *r, t_entry *e)
{
	uint32_t	h;

	h = key_hash(e->key);
}

void		make_hash(t_race *r)
{
	size_t	idx;
	t_entry	*it;

	idx = 0;
	while (idx < r->init_read.item_count)
	{
		it = (t_entry*)ft_ary_get(&r->init_read, idx);
		hash_insert(r, it);
		idx++;
	}
}
