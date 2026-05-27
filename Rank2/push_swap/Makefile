# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tthwe <tthwe@student.42bangkok.com>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2026/05/28 02:47:56 by tthwe             #+#    #+#              #
#    Updated: 2026/05/28 02:47:56 by tthwe            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	= push_swap
CC		= cc
FLAGS	= -Wall -Wextra -Werror

SRCS	=	parser/parser.c \
			parser/ft_atoi.c \
			operations/swap.c \
			operations/push.c \
			operations/rotate.c \
			operations/reverse_rotate.c \
			algorithm/index.c \
			algorithm/sort_utils.c \
			algorithm/sort_small.c

OBJS	= $(SRCS:.c=.o)

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(FLAGS) $(OBJS) -o $(NAME)

%.o: %.c push_swap.h
	$(CC) $(FLAGS) -c $< -o $@

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
