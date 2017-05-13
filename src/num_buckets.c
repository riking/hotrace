/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   num_buckets.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyork <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/13 14:11:02 by kyork             #+#    #+#             */
/*   Updated: 2017/05/13 16:34:18 by kyork            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "hotrace.h"

int		num_buckets(t_race *r)
{
	size_t	n;

	n = r->init_read.item_count;
	if (n < 16)
	{
		r->hash_buckets = 32;
	}
	else
	{
		n = n * 7 / 4;
		n |= n >> 1;
		n |= n >> 2;
		n |= n >> 4;
		n |= n >> 8;
		n |= n >> 16;
		n |= n >> 32;
		r->hash_buckets = n + 1;
	}
	r->bucket_mask = r->hash_buckets - 1;
	return (r->hash_buckets);
}
