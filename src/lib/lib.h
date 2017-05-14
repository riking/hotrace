/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lib.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyork <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/13 10:17:22 by kyork             #+#    #+#             */
/*   Updated: 2017/05/14 16:05:19 by kyork            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIB_LIB_H
# define LIB_LIB_H

# include <sys/types.h>

void			*ft_memalloc(size_t size);
void			ft_bzero(void *ptr, size_t size);
void			ft_putstr(const char *str);
void			flush_stdout(void);

#define SLAB_SIZE (1024 * 1024)
#define SLAB_ALIGN 8

typedef struct	s_slab {
	struct s_slab	*next;
	char			*cur;
}				t_slab;

char			*slab_dup(const char *str);
void			slab_free(void);

#define GNL_NODUP 2
#define GNL_SLAB 3

int			get_next_line0(char **line, int mode);
int			gnl_have_buffer(void);

#endif
