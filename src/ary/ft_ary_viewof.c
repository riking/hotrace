/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ary_viewof.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyork <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/24 14:23:42 by kyork             #+#    #+#             */
/*   Updated: 2017/05/13 10:16:14 by kyork            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ary.h"
#include <stdlib.h>

t_array		ft_ary_viewof(void *ptr, size_t count, const size_t sizeof_item)
{
	t_array	a;

	a = (t_array){ptr, sizeof_item, count, 0};
	return (a);
}
