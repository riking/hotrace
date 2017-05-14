/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   aligned_strdup.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyork <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/13 13:09:38 by kyork             #+#    #+#             */
/*   Updated: 2017/05/14 16:38:58 by kyork            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "str.h"
#include <stdlib.h>

static size_t	strlen_16(const char *s1)
{
	size_t len;

	len = 0;
	while (s1[len])
		len++;
	len = len + 16;
	len = len & ~0xF;
	return (len);
}

char			*sse_strdup(const char *s1)
{
	size_t	len;
	char	*dst;
	char	*d;

	len = strlen_16(s1);
	dst = malloc(len);
	if (!dst)
		return (0);
	d = dst;
	while (*s1)
		*d++ = *s1++;
	*d = 0;
	return (dst);
}
