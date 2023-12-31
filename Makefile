# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: yushsato <yushsato@student.42tokyo.jp>     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/10/07 10:00:38 by yushsato          #+#    #+#              #
#    Updated: 2023/12/01 18:58:08 by yushsato         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	= push_swap
CC		= cc
CFLAGS	= -Wall -Wextra -Werror
SRCS	= main.c \
		  push_swap.c \
		  ./ps_lib/ps_argo_all.c \
		  ./ps_lib/ps_argo_adjust_a_3.c \
		  ./ps_lib/ps_argo_adjust_a_5.c \
		  ./ps_lib/ps_atoi.c \
		  ./ps_lib/ps_node_first.c \
		  ./ps_lib/ps_node_free.c \
		  ./ps_lib/ps_node_issorted.c \
		  ./ps_lib/ps_node_last.c \
		  ./ps_lib/ps_node_len.c \
		  ./ps_lib/ps_node_max.c \
		  ./ps_lib/ps_node_min.c \
		  ./ps_lib/ps_node_serializer.c \
		  ./ps_lib/ps_put_op.c \
		  ./ps_lib/ps_stack_free.c \
		  ./ps_lib/ps_stack_op_push.c \
		  ./ps_lib/ps_stack_op_rev_rotate.c \
		  ./ps_lib/ps_stack_op_rotate.c \
		  ./ps_lib/ps_stack_op_swap.c \
		  ./ps_lib/ps_stack_op.c
OBJS	= $(SRCS:.c=.o)
INCLUDE	= -I./ps_lib
LIBFT	= libft.a
PRINTF	= ftprintf.a

%.o: %.c
	$(CC) $(CFLAGS) $(INCLUDE) -c $< -o $@

$(NAME): $(OBJS) $(LIBFT) $(PRINTF)
	$(CC) $(CFLAGS) $^ $(INCLUDE) -o $@

$(LIBFT):
	cd lib && cd libft \
		&& make all && cp $@ ../../ && make fclean;

$(PRINTF):
	cd lib && cd ft_printf \
		&& make all && cp $@ ../../ && make fclean;

all: $(NAME)

clean:
	rm -f $(OBJS) $(LIBFT) $(PRINTF)

fclean: clean
	rm -f $(NAME)

re: fclean all

build: all clean

__debug_configure__:
	$(eval CC := gcc)
	$(eval CFLAGS := -g -fsanitize=address -Wall -Wextra -Werror)

debug: __debug_configure__ all

norminette: $(SRCS)
	norminette ./ps_lib/push_swap.h $^ ./lib/libft ./lib/ft_printf

norm: norminette

.PHONY: all clean fclean re build __debug_configure__ debug norminette norm
