/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ary_foreach.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyork <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/24 15:37:14 by kyork             #+#    #+#             */
/*   Updated: 2017/05/13 10:14:52 by kyork            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ary.h"

void		ft_ary_foreach(t_array *ary, void (*func)(void*, size_t))
{
	size_t	idx;

	idx = 0;
	while (idx < ary->item_count)
	{
		func(ft_ary_get(ary, idx), ary->item_size);
		idx++;
	}
}
