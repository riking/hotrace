/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sse_memmove.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyork <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/13 10:30:06 by kyork             #+#    #+#             */
/*   Updated: 2017/05/13 10:55:46 by kyork            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "str.h"
#include <stdio.h>

void		sse_memmove(void *dst, void *src, size_t len)
{
	uint64_t	mask;

	mask = -1ULL;
	__asm__("bzhiq %1, %0, %0;kmovq %0, k1; vmovdqu8 (%2), zmm16{k1}{z}; vmovdqu8 zmm16, (%3){k1}" : "+r" (mask) :
			"r" (len), "r" (src), "r" (dst) : "memory");
}

#include <string.h>
int main(void)
{
	char	buf1[21];
	char	buf2[21];

	memset(buf1, 'A', 20);
	memset(buf2, 'B', 20);
	sse_memmove(buf1, buf2, 0);
	sse_memmove(buf1, buf2, 1);
	sse_memmove(buf2, buf1, 2);
	buf2[20] = 0;
	printf("%s\n", buf2);
	return 0;
	sse_memmove(NULL, NULL, 3);
	sse_memmove(NULL, NULL, 16);
	sse_memmove(NULL, NULL, 64);
}
