/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ary_insert.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyork <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/24 14:47:04 by kyork             #+#    #+#             */
/*   Updated: 2017/05/13 10:22:09 by kyork            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ary.h"

int		ft_ary_insert(t_array *ary, void *item, size_t idx)
{
	int		status;

	if (ary->item_cap == 0)
		return (FT_ARY_ERR_ISVIEW);
	if (idx == ary->item_count)
		return (ft_ary_append(ary, item));
	if (idx > ary->item_count)
		return (FT_ARY_ERR_BOUNDS);
	if (ary->item_count + 1 == ary->item_cap)
	{
		status = ft_ary_grow(ary, ary->item_cap * FT_ARY_GROW_FACTOR);
		if (status != 0)
			return (status);
	}
	sse_memmove(((char*)ary->ptr) + ((idx + 1) * ary->item_size),
			((char*)ary->ptr) + (idx * ary->item_size),
			(ary->item_count - idx) * ary->item_size);
	sse_memmove(((char*)ary->ptr) + (idx * ary->item_size),
			item,
			ary->item_size);
	ary->item_count += 1;
	return (FT_ARY_ERR_OKAY);
}
