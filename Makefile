NAME = libftprintf.a

CC = gcc

RM = rm -rf

CFLAGS =  -c -Wall -Wextra -Werror

SRCS = src/ft_printf.c\
		src/ft_char_spec.c\
		src/ft_pointer_spec.c\
		src/libft1.c\
		src/libft2.c\
		src/libft3.c\
		src/ft_hexadec.c\
		src/ft_string_spec.c\
		src/ft_unsigned_int.c\
		src/ft_signed_int.c\
		src/ft_parser.c

OBJS = ${SRCS:.c=.o}

INCLUDES = -I./includes

.c.o: ${CC} ${CFLAGS} -c $< -o ${<:.c=.o}



$(NAME): $(OBJS)
		ar rcs $(NAME) $(OBJS)

all:$(NAME)



clean:
			${RM} ${OBJS} 

fclean:		clean
			${RM} ${NAME}

re:			fclean all

.PHONY:		all clean fclean re