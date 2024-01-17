# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: hehuang <hehuang@student.42lehavre.fr>     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/12/03 19:04:13 by hehuang           #+#    #+#              #
#    Updated: 2024/01/17 23:27:32 by hehuang          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS = src/push_swap.c \
      src/push_swap_init.c \
      src/push_swap_op.c \
      src/push_swap_utils.c \
      src/ft_split.c \
      src/main.c \
      src/push_swap_algo.c \
      src/push_swap_op2.c \
      src/push_swap_utils2.c \
      src/push_swap_cost.c \
      src/push_swap_free.c \

OBJS = ${SRCS:%.c=%.o}

NAME = push_swap

CC = cc

CFLAGS = -Wall -Wextra -Werror

%.o : %.c
	cc ${CFLAGS} -Iincludes -c $< -o $@

$(NAME): ${OBJS}
	@${CC} ${CFLAGS} -Iincludes ${OBJS} -o ${NAME}

all:    ${NAME}

clean:
	rm -rf ${OBJS}

fclean: clean 
	rm -rf ${NAME}

re: 	fclean all                        

.PHONY : all clean fclean re
