/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ary_create.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyork <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/24 14:23:42 by kyork             #+#    #+#             */
/*   Updated: 2017/05/13 10:14:36 by kyork            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ary.h"
#include <stdlib.h>

t_array		ft_ary_create(size_t sizeof_item)
{
	t_array	ary;

	ary = (t_array){(void*)ft_memalloc(sizeof_item * FT_ARY_DEFAULT_CAP),
		sizeof_item, 0, FT_ARY_DEFAULT_CAP};
	if (!ary.ptr)
	{
		return ((t_array){0, 0, 0, 0});
	}
	return (ary);
}
