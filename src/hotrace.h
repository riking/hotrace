/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hottrace.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyork <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/13 11:36:04 by kyork             #+#    #+#             */
/*   Updated: 2017/05/13 12:45:15 by kyork            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HOTRACE_H
# define HOTRACE_H

# include "lib/lib.h"

typedef struct	s_readentry {
	char				*key;
	char				*value;
	struct s_readentry	*next;
}				t_readentry;

/*
** init_read: t_array<t_readentry>
** hash_table: t_array<t_readentry*>
**   (points into init_read)
** we can keep the items in the init_read table; the hashtable consists of
** pointers to the first item with a given hash
*/
typedef struct	s_race {
	t_array		knit_read;
	int			hash_buckets;
	t_array		hash_table;
}				t_race;

void			read_entries(t_race *r);
void			make_hash(t_race *r);
void			do_lookup(t_race *r);

uint64_t		key_hash(const char *str);
char			*lookup(t_race *r, char *key);


#endif
