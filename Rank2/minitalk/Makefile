# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tthwe <tthwe@student.42bangkok.com>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2026/05/11 03:59:52 by tthwe             #+#    #+#              #
#    Updated: 2026/05/11 05:35:29 by tthwe            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

LIBFT = libft/libft.a
NAME_SERVER = server
NAME_CLIENT = client
CC = cc
FLAGS = -Wall -Wextra -Werror

all: $(LIBFT) $(NAME_SERVER) $(NAME_CLIENT)

$(LIBFT):
	make -C libft

$(NAME_SERVER): server.c
	$(CC) $(FLAGS) server.c $(LIBFT) -o $(NAME_SERVER)

$(NAME_CLIENT): client.c
	$(CC) $(FLAGS) client.c $(LIBFT) -o $(NAME_CLIENT)

clean:
	rm -f *.o

fclean:
	rm -f $(NAME_SERVER) $(NAME_CLIENT)
	make -C libft fclean

re: fclean all

.PHONY: all clean fclean re