/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_hash.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyork <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/13 13:05:22 by kyork             #+#    #+#             */
/*   Updated: 2017/05/13 13:52:41 by kyork            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "hotrace.h"

static uint32_t	mix_hash(uint32_t hash)
{
	hash = ((hash >> 16 ^ hash) * 0x45d9f3b);
	hash = ((hash >> 16 ^ hash) * 0x45d9f3b);
	hash = (hash >> 16 ^ hash);
	return (hash);
}

uint32_t		key_hash(const char *str)
{
	uint32_t	result;
	const char	*s;

	s = str;
	result = 13;
	while (*s)
	{
		result = result * 31 + *s;
		s++;
	}
	return (mix_hash(result));
}
