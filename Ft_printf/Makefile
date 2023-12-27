# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: hehuang <hehuang@student.42lehavre.fr>     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/10/30 15:46:59 by hehuang           #+#    #+#              #
#    Updated: 2023/11/02 16:34:20 by hehuang          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS = ${wildcard *.c}

OBJS = ${SRCS:.c=.o}

NAME = libftprintf.a

CFLAGS = -Wall -Wextra -Werror

.c.o:
	cc ${CFLAGS} -I includes -c $< -o ${<:.c=.o}

$(NAME): ${OBJS}
	ar rcs ${NAME} ${OBJS}

all:    ${NAME}

clean:
	rm -f ${OBJS}

fclean: clean
	rm -f ${NAME}

re:		fclean all
