/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lib.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyork <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/13 10:17:22 by kyork             #+#    #+#             */
/*   Updated: 2017/05/13 13:53:17 by kyork            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIB_LIB_H
# define LIB_LIB_H

# include <sys/types.h>

void		*ft_memalloc(size_t size);
void		ft_bzero(void *ptr, size_t size);
int			get_next_line0(char **line);

#endif
