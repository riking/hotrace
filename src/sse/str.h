/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   str.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyork <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/13 10:18:30 by kyork             #+#    #+#             */
/*   Updated: 2017/05/13 10:33:34 by kyork            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SSE_STR_H
# define SSE_STR_H

# include <stdint.h>
# include <sys/types.h>

void		sse_memmove(void *dst, void *src, size_t len);
void		sse_bzero(void *ptr, size_t len);

#endif
