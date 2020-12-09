NAME = libftprintf.a
CC = gcc

RM = rm -f

CFLAGS = -Wall -Wextra -Werror

SRCS = src/ft_printf.c\
		src/integer.c\
		src/pointer.c\
		src/libft1.c\
		src/Character.c\
		src/string.c\
		src/un_int_hexa.c\
		src/unsigned_int.c

OBJS = ${SRCS:.c=.o}

INCLUDES = src/ft_printf.h

.c.o: ${CC} ${CFLAGS} -c -I${INCLUDES} $< -o ${<:.c=.o}



$(NAME): $(OBJS)
		ar rcs $(NAME) $(OBJS)

all:${NAME}



clean:
			${RM} ${OBJS} 

fclean:		clean
			${RM} ${NAME}

re:			fclean all

.PHONY:		all clean fclean re