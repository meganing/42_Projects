# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tthwe <tthwe@student.42bangkok.com>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2026/06/03 00:09:00 by tthwe             #+#    #+#              #
#    Updated: 2026/06/06 05:07:29 by tthwe            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = so_long
CC = cc
FLAGS = -Wall -Wextra -Werror -Imlx
LIBFT	= Libft/libft.a
MLX_LIB = mlx/libmlx.a
SRCS = main.c parsing.c validate.c flood_fill.c render.c movement.c events.c utils.c
OBJS = $(SRCS:.c=.o)

UNAME_S := $(shell uname)
ifeq ($(UNAME_S),Darwin)
	MLX_FLAGS = -framework OpenGL -framework AppKit
else
	MLX_FLAGS = -lXext -lX11 -lm
endif

all: $(NAME)

$(NAME): $(OBJS) $(LIBFT) $(MLX_LIB)
	$(CC) $(FLAGS) $(OBJS) $(LIBFT) $(MLX_LIB) $(MLX_FLAGS) -o $(NAME)

$(LIBFT):
	$(MAKE) -C Libft

$(MLX_LIB):
	$(MAKE) -C mlx

%.o: %.c so_long.h
	$(CC) $(FLAGS) -c $< -o $@

clean:
	rm -f $(OBJS)
	$(MAKE) -C Libft clean

fclean: clean
	rm -f $(NAME)
	$(MAKE) -C Libft fclean

re: fclean all

.PHONY: all clean fclean re
