NAME = libftprintf.a

LIBFT = ./Libft/libft.a

LIBFT_DIR = ./Libft

CC = cc

FLAG = -Wall -Wextra -Werror

FILES = ft_printf.c ft_printchar.c ft_printstr.c ft_printhex.c ft_printunsigned.c \
		ft_printptr.c ft_printnbr.c

SRCS = ${FILES}

OBJ = ${SRCS:.c=.o}

INCLUDE = ft_printf.h

.c.o:
			${CC} ${FLAG} -I ${INCLUDE} -c $< -o $@
			
all:		${NAME}

${NAME}:		${OBJ}
	make -C $(LIBFT_DIR)
	cp $(LIBFT) $(NAME)
	ar rcs ${NAME} ${OBJ}
	
clean:
	make clean -C $(LIBFT_DIR)
	rm -f ${OBJ} ${BONUSOBJ}
	
fclean: clean
	make fclean -C $(LIBFT_DIR)
	rm -f ${NAME}
	
re:	fclean all
	
.PHONY:		all clear fclean re 