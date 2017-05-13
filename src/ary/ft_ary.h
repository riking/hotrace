/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ary.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyork <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/08/18 11:01:11 by kyork             #+#    #+#             */
/*   Updated: 2017/05/13 14:02:15 by kyork            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_ARY_H
# define FT_ARY_H

# include <sys/types.h>
# include "../lib/lib.h"
# include "../sse/str.h"

/*
** Growing Array
**
** t_array is an autogrowing array implementation. The size of an element
** is provided when the array is constructed, and used in every function.
**
** ft_ary_create() allocates a t_array structure with the given size. destroy()
** must be called to free the memory.
**
** set(), append(), and insert() perform a memory copy to insert the item.
**
** Any references into the array's ptr are stale after a call to grow(),
** insert(), append(), or clear().
**
** Functions returning int return one of the FT_ARY_ERR_* constants.
** Functions returning void do not fail.
** The get() function performs no bounds checking - don't pass invalid indices.
**
** If item_cap is 0, the array is a view of other memory and cannot be grown.
** Functions changing the size will fail (grow, append, remove).
*/

# ifdef __APPLE__
#  define CONSTSIZET const size_t
# else
#  define CONSTSIZET size_t
# endif

typedef struct		s_array
{
	void			*ptr;
	CONSTSIZET		item_size;
	size_t			item_count;
	size_t			item_cap;
}					t_array;

# define FT_ARY_NULL ((t_array){0, 0, 0, 0})
# define FT_ARY_DEFAULT_CAP 4
# define FT_ARY_GROW_FACTOR 2
# define FT_ARY_ERR_OKAY 0
# define FT_ARY_ERR_ALLOC -1
# define FT_ARY_ERR_ISVIEW -2
# define FT_ARY_ERR_BOUNDS -3

t_array				ft_ary_create(const size_t sizeof_item);
t_array				ft_ary_clone(t_array ary, size_t min_size);
t_array				ft_ary_viewof(void *ptr, size_t count,
						const size_t sizeof_item);
void				*ft_ary_get(t_array *ary, size_t idx);
int					ft_ary_set(t_array *ary, void *item, size_t idx);
int					ft_ary_grow(t_array *ary, size_t min_item_cap);
int					ft_ary_append(t_array *ary, void *item);
int					ft_ary_insert(t_array *ary, void *item, size_t idx);
int					ft_ary_poplast(t_array *ary);
int					ft_ary_remove(t_array *ary, size_t idx);
int					ft_ary_remove_mul(t_array *ary, size_t idx, size_t count);
int					ft_ary_clear(t_array *ary);
void				ft_ary_foreach(t_array *ary, void (*func)(void*, size_t));
void				ft_ary_destroy(t_array *ary);
void				ft_ary_destroy2(t_array **pary);
void				ft_ary_swap(t_array *ary, size_t i, size_t j);

typedef int			(*t_sortfunc)(void *left, void *right, size_t size,
						void *data);
void				ft_ary_sort(t_array *ary, t_sortfunc cmp, void *cmp_data);

#endif
