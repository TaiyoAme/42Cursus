# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: hehuang <hehuang@student.42lehavre.fr>     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/12/03 19:04:13 by hehuang           #+#    #+#              #
#    Updated: 2023/12/20 17:54:24 by hehuang          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRC = src/push_swap.c src/push_swap_init.c src/push_swap_op.c \
	  src/push_swap_utils.c src/ft_split.c src/main.c \
	  src/push_swap_algo.c src/push_swap_op.c src/push_swap_utils2.c

OBJS = ${SRCS:.c=.o}

NAME = push_swap.a

CFLAGS = -Wall -Wextra -Werror

.c.o:
	cc ${CFLAGS} -I includes -c $< -o ${<:.c=.o}

$(NAME): ${OBJS}
	ar rs ${NAME} ${OBJS}

all:    ${NAME}

clean:
	rm -f ${OBJS}

fclean: clean
	rm -f ${NAME}

re: 
	fclean all~                           

.PHONY : all clean fclean re
