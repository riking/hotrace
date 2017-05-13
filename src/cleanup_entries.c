/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cleanup_entries.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyork <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/13 14:16:54 by kyork             #+#    #+#             */
/*   Updated: 2017/05/13 15:11:37 by kyork            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "hotrace.h"
#include <stdlib.h>

void		cleanup_entries(t_race *r)
{
	size_t	i;
	t_entry	*e;

	i = 0;
	while (i < r->init_read.item_count)
	{
		e = (t_entry*)ft_ary_get(&r->init_read, i);
		free(e->key);
		free(e->value);
		i++;
	}
}
