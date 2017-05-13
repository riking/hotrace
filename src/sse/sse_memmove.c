/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sse_memmove.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyork <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/13 10:30:06 by kyork             #+#    #+#             */
/*   Updated: 2017/05/13 10:48:01 by kyork            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "str.h"
#include <stdio.h>

void		sse_memmove(void *dst, void *src, size_t len)
{
	uint64_t	mask;

	mask = -1ULL;
	__asm__("bzhiq %1, %0, %0" : "+r" (mask) : "r" (len));
	printf("%#3llx\n", mask);
}

int main(void)
{
	sse_memmove(NULL, NULL, 0);
	sse_memmove(NULL, NULL, 1);
	sse_memmove(NULL, NULL, 2);
	sse_memmove(NULL, NULL, 3);
	sse_memmove(NULL, NULL, 16);
	sse_memmove(NULL, NULL, 64);
}
