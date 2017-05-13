/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hotrace.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyork <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/13 11:36:04 by kyork             #+#    #+#             */
/*   Updated: 2017/05/13 13:30:45 by kyork            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HOTRACE_H
# define HOTRACE_H

# include "ary/ft_ary.h"
# include "lib/lib.h"
# include "sse/str.h"

typedef struct	s_entry {
	char			*key;
	char			*value;
	struct s_entry	*next;
}				t_entry;

/*
** init_read: t_array<t_entry>
** hash_table: t_array<t_entry*>
**   (points into init_read)
** we can keep the items in the init_read table; the hashtable consists of
** pointers to the first item with a given hash
*/
typedef struct	s_race {
	t_array		init_read;
	int			hash_buckets;
	t_array		hash_table;
}				t_race;

void			read_entries(t_race *r);
void			make_hash(t_race *r);
void			do_lookup(t_race *r);

int				num_buckets(int num_items);
uint32_t		key_hash(const char *str);
char			*lookup(t_race *r, char *key);

int				get_next_line0(char **line);

#endif
