/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memalloc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyork <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/13 11:01:30 by kyork             #+#    #+#             */
/*   Updated: 2017/05/13 11:06:50 by kyork            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lib.h"
#include <stdlib.h>

/*
** this looks pretty good when compiled with -O2 -fno-builtin
*/

void		*ft_memalloc(size_t len)
{
	void	*ptr;
	char	*p;
	size_t	i;

	ptr = malloc(len);
	if (ptr)
	{
		p = ptr;
		i = 0;
		while (len--)
		{
			p[i++] = 0;
		}
	}
	return (ptr);
}
