CC = cc

FLAG = -Wall -Wextra -Werror

PART1 = ft_atoi.c ft_bzero.c ft_calloc.c ft_isalnum.c ft_isalpha.c ft_isascii.c \
		ft_isdigit.c ft_isprint.c ft_memchr.c ft_memcmp.c ft_memcpy.c \
		ft_memmove.c ft_memset.c ft_strchr.c ft_strdup.c ft_strlcat.c \
		ft_strlcpy.c ft_strlen.c ft_strncmp.c ft_strnstr.c ft_strrchr.c \
		ft_tolower.c ft_toupper.c 

PART2 = ft_substr.c ft_strjoin.c ft_strtrim.c ft_split.c ft_itoa.c \
		ft_strmapi.c ft_striteri.c ft_putchar_fd.c ft_putstr_fd.c \
		ft_putendl_fd.c ft_putnbr_fd.c

SRCS = ${PART1} ${PART2}

NAMELIB = libft.a

OBJ = ${SRCS:.c=.o}

INCLUDE = libft.h

# bonus part

BONUS = ft_lstnew_bonus.c ft_lstadd_front_bonus.c ft_lstsize_bonus.c ft_lstlast_bonus.c \
		ft_lstadd_back_bonus.c ft_lstdelone_bonus.c ft_lstclear_bonus.c ft_lstiter_bonus.c \
		ft_lstmap_bonus.c

BONUSOBJ = ${BONUS:.c=.o}


.c.o:
			${CC} ${FLAG} -I ${INCLUDE} -c $< -o $@
			
all:		${NAMELIB}

${NAMELIB}:		${OBJ}
	ar rcs ${NAMELIB} ${OBJ}
	
bonus:		${OBJ} ${BONUSOBJ}
	ar rcs ${NAMELIB} ${OBJ} ${BONUSOBJ}
	
clean:
	rm -f ${OBJ} ${BONUSOBJ}
	
fclean: clean
	rm -f ${NAMELIB}
	
re:	fclean all
	
.PHONY:		all clear fclean re bonus 