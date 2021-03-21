# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mrahmani <mrahmani@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/01/06 21:25:13 by mrahmani          #+#    #+#              #
#    Updated: 2021/01/06 21:25:57 by mrahmani         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a

CC = gcc

RM = rm -rf

CFLAGS =  -c -Wall -Wextra -Werror

SRCS = src/ft_printf.c\
		src/ft_c_specifier.c\
		src/ft_p_specifier.c\
		src/ft_libft1.c\
		src/ft_libft2.c\
		src/ft_libft3.c\
		src/ft_x_specifier.c\
		src/ft_s_specifier.c\
		src/ft_u_specifier.c\
		src/ft_i_specifier.c\
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
