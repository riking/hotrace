/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   str.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyork <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/13 10:18:30 by kyork             #+#    #+#             */
/*   Updated: 2017/05/13 13:01:01 by kyork            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SSE_STR_H
# define SSE_STR_H

# include <stdint.h>
# include <sys/types.h>

void		sse_memmove(void *dst, void *src, size_t len);
int			sse_strcmp(const char *a, const char *b);

#endif
