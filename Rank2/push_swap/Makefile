# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tthwe <tthwe@student.42bangkok.com>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2026/05/28 02:47:56 by tthwe             #+#    #+#              #
#    Updated: 2026/06/03 02:47:56 by tthwe            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	= push_swap
CC		= cc
FLAGS	= -Wall -Wextra -Werror
LIBFT	= Libft/libft.a

SRCS	=	main.c \
			parser/parser.c \
			parser/stack_utils.c \
			operations/swap.c \
			operations/push.c \
			operations/rotate.c \
			operations/reverse_rotate.c \
			algorithm/index.c \
			algorithm/sort_three.c \
			algorithm/algo.c \
			algorithm/cost.c

OBJS	= $(SRCS:.c=.o)

all: $(LIBFT) $(NAME)

$(LIBFT):
	$(MAKE) -C Libft

$(NAME): $(OBJS) $(LIBFT)
	$(CC) $(FLAGS) $(OBJS) $(LIBFT) -o $(NAME)

%.o: %.c push_swap.h
	$(CC) $(FLAGS) -c $< -o $@

clean:
	rm -f $(OBJS)
	$(MAKE) -C Libft clean

fclean: clean
	rm -f $(NAME)
	$(MAKE) -C Libft fclean

re: fclean all

.PHONY: all clean fclean re
