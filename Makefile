# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: yushsato <yushsato@student.42tokyo.jp>     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/10/07 10:00:38 by yushsato          #+#    #+#              #
#    Updated: 2023/11/07 17:21:50 by yushsato         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	= push_swap
CC		= gcc
CFLAGS	= -Wall -Wextra -Werror -g -fsanitize=address
SRCS	= main.c
OBJS	= $(SRCS:.c=.o)
INCLUDE	= -I. -I./lib/libft
LIBFT	= libft.a
PRINTF	= ftprintf.a

all: $(NAME)

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

clean:
	rm -f $(OBJS) $(LIBFT) $(PRINTF)

fclean: clean
	rm -f $(NAME)

re: fclean all

build: all clean

norminette: $(SRCS)
	norminette $< ./lib/ft_printf ./lib/libft

norm: norminette

.PHONY: all clean fclean re
