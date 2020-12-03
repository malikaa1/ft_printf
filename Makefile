NAME = libftprintf.a
SRCS = src/ft_printf.c src/integer.c src/pointer.c src/lifbt1.c src/Characters.c src/string.c src/un_int_hexa.c
INCLUDES = includes/ft_printf.h
OBJS = §{SRCS:.c=.o}

OBJS = ${SRCS:.c=.o}

OBJS_BONUS =${SRCS_BONUS:.c=.o}

CC = gcc

RM = rm -f

CFLAGS = -Wall -Wextra -Werror

.c.o: ${CC} ${CFLAGS} -c -I${INCLUDES} $< -o ${<:.c=.o}

$(NAME): $(OBJS)
		ar rcs $(NAME) $(OBJS)

all:${NAME}

bonus:$(OBJS_BONUS)
		ar rcs $(NAME) $(OBJS_BONUS)

clean:
		${RM} ${OBJS} ${OBJS_BONUS}

fclean:clean
		${RM} ${NAME}

re:fclean all

.PHONY:all clean fclean re