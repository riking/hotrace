/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyork <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/13 11:35:50 by kyork             #+#    #+#             */
/*   Updated: 2017/05/13 13:33:57 by kyork            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "hotrace.h"

int		main(void)
{
	t_race	r;
	int		buckets;

	r.init_read = ft_ary_create(sizeof(t_entry));
	read_entries(&r);
	r.hash_table = ft_ary_create(sizeof(t_entry*));
	buckets = num_buckets(r.init_read.item_count);
	ft_ary_grow(&r.hash_table, buckets);
	r.hash_table.item_count = buckets;
	make_hash(&r);
	do_lookup(&r);
}
