/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sse_strcmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyork <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/13 12:48:16 by kyork             #+#    #+#             */
/*   Updated: 2017/05/14 17:07:06 by kyork            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "str.h"

int			sse_strcmp(const char *s1, const char *s2)
{
	int		result;
	size_t	idx;

	__asm__("mov $-16, %1\n"
			"Lloop%=: add $16, %1\n"
			"movdqu (%1,%2), %%xmm1\n"
			"movdqu (%1,%3), %%xmm0\n"
			"pcmpistri $24, %%xmm0, %%xmm1\n"
			"jnbe Lloop%=\n"
			"jnc Lequal%=\n"
			"add %%rcx, %1\n"
			"mov $1, %0\n"
			"jmp Ldone%=\n"
			"Lequal%=: xor %0, %0\n"
			"Ldone%=:nop"
			: "=r"(result), "+r"(idx)
			: "r"(s1), "r"(s2)
			: "rcx", "cc", "xmm0", "xmm1");
	if (result)
		return (s2[idx] - s1[idx]);
	return (0);
}
