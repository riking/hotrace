# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: kyork <marvin@42.fr>                       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/10/09 19:11:26 by kyork             #+#    #+#              #
#    Updated: 2017/05/14 15:42:43 by kyork            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		= hotrace

RELEASE = 1

COMMONSRC	+= $(addprefix ary/, ft_ary_create.c    ft_ary_get.c      ft_ary_remove.c      ft_ary_swap.c \
ft_ary_append.c  ft_ary_destroy.c   ft_ary_grow.c     ft_ary_remove_mul.c  ft_ary_viewof.c \
ft_ary_clear.c   ft_ary_destroy2.c  ft_ary_insert.c   ft_ary_set.c \
ft_ary_clone.c   ft_ary_foreach.c   ft_ary_poplast.c  ft_ary_sort.c)
COMMONSRC	+= $(addprefix lib/, ft_memalloc.c ft_bzero.c ft_putstr.c get_next_line.c)
COMMONSRC	+= $(addprefix sse/, sse_memmove.c sse_strcmp.c aligned_strdup.c)
COMMONSRC	+= key_hash.c main.c read_entries.c make_hash.c do_lookup.c
COMMONSRC	+= num_buckets.c cleanup_entries.c
COMMONSRC	+= 
COMMONSRC	+= 
COMMONSRC	+= 
COMMONSRC	+= 
COMMONSRC	+= 

OBJS		= $(addprefix build/, $(COMMONSRC:.c=.o))

LIBS		=

# Flags start
CFLAGS		+= -Wall -Wextra -Wmissing-prototypes -msse4.2
LDFLAGS		+= -Wall -Wextra
CFLAGS		+= -I includes/
# needed to prevent forbidden function use
CFLAGS		+= -fno-builtin

ifndef NO_WERROR
	CFLAGS += -Werror
	LDFLAGS += -Werror
endif

ifdef DEBUG
	CFLAGS += -fsanitize=address -g
	LDFLAGS += -fsanitize=address -g
endif

ifdef RELEASE
	CFLAGS += -O2 -flto
	LDFLAGS += -O2 -flto
endif
# Flags end

ifeq ($(SHELL),zsh)
	PRINTF	= printf
else
	PRINTF  = $(shell which printf)
endif

.PHONY: all clean fclean re

all: $(NAME)

$(NAME): $(OBJS) $(LIBS)
	$(CC) $(LDFLAGS) -o $@ $^
	@printf "\e[32m\e[1m[OK]\e[m $@\n" | tr '\\e' '\e'

clean:
	rm -r build/
	rm -f $(OBJS)
	@echo "\e[33m\e[1m[CLEAN]\e[m $$(basename $$(pwd))\n" | tr '\\e' '\e'

fclean: clean
	rm -f $(NAME)
	@echo "\e[33m\e[1m[FCLEAN]\e[m $$(basename $$(pwd))\n" | tr '\\e' '\e'

re: fclean all

build/%.o: src/%.c
	@mkdir -p $(@D)
	$(CC) $(CFLAGS) -c -o $@ $<

