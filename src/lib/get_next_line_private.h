/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_private.h                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyork <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/26 12:34:19 by kyork             #+#    #+#             */
/*   Updated: 2017/05/13 17:05:54 by kyork            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_PRIVATE_H
# define GET_NEXT_LINE_PRIVATE_H

# include <sys/types.h>

typedef struct		s_gnl_fd {
	int		fd;
	ssize_t	nl_off;
	ssize_t	nl_start;
	t_array	chars;
}					t_gnl_fd;

typedef struct		s_gnlstate {
	t_array fds;
}					t_gnlstate;

# ifndef BUFF_SIZE
#  define BUFF_SIZE 4096
# endif

extern t_gnlstate	g_bufio_state;

int					get_next_line0(char **line, int mode);

t_gnl_fd			*gnl_setup(void);
ssize_t				gnl_read(t_gnl_fd *s);

#endif
