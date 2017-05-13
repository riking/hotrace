/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   asm_strequ.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyork <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/13 12:48:16 by kyork             #+#    #+#             */
/*   Updated: 2017/05/13 12:51:21 by kyork            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "str.h"

int		asm_strequ(const char *s1, const char *s2)
{
	int	result;
	size_t idx;
	__asm__("mov $-16, %1\n"
			"cmploop: add $16, %1\n"
			"movdqu (%1,%2), %%xmm1\n"
			"movdqu (%1,%3), %%xmm0\n"
			"pcmpistri $24, %%xmm0, %%xmm1\n"
			"jnbe cmploop\n"
			"jnc equal\n"
			"mov $0, %0\n"
			"jmp done\n"
			"equal: mov $1, %0\n"
			"done:nop"
			: "=r"(result), "+r"(idx) : "r"(s1), "r"(s2) : "memory", "cc");
	return (result);
}
