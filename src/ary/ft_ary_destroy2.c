/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ary_destroy2.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyork <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/24 14:54:39 by kyork             #+#    #+#             */
/*   Updated: 2017/05/13 10:14:47 by kyork            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ary.h"
#include <stdlib.h>

void	ft_ary_destroy2(t_array **pary)
{
	if (*pary)
	{
		if ((*pary)->item_cap == 0)
			;
		else
			free((*pary)->ptr);
	}
	free(*pary);
	*pary = NULL;
}
