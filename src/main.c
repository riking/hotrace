/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyork <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/13 11:35:50 by kyork             #+#    #+#             */
/*   Updated: 2017/05/13 15:06:51 by kyork            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "hotrace.h"

int		main(int argc, char **argv)
{
	t_race	r;
	int		buckets;
	int		fd;

	r.init_read = ft_ary_create(sizeof(t_entry));
	if (0 == read_entries(&r))
	{
		r.hash_table = ft_ary_create(sizeof(t_entry*));
		buckets = num_buckets(&r);
		ft_ary_grow(&r.hash_table, r.hash_buckets);
		r.hash_table.item_count = buckets;
		make_hash(&r);
		do_lookup(&r);
		ft_ary_destroy(&r.hash_table);
	}
	cleanup_entries(&r);
}
