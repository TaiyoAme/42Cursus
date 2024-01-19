# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: hehuang <hehuang@student.42lehavre.fr>     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/12/03 19:04:13 by hehuang           #+#    #+#              #
#    Updated: 2024/01/18 19:11:35 by hehuang          ###   ########.fr        #
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

SRCS_CHECKER = src/checker/ft_checker.c \
	       src/push_swap_free.c \
	       src/push_swap_init.c \
	       src/push_swap_op.c \
	       src/push_swap_op2.c \
	       src/push_swap_utils.c \
	       src/push_swap_utils2.c \
	       src/ft_split.c

OBJS = ${SRCS:%.c=%.o}

OBJS_CHECKER = ${SRCS_CHECKER:%.c=%.o}

NAME = push_swap

NAME_CHECKER = checker

CC = cc

CFLAGS = -Wall -Wextra -Werror

%.o : %.c
	cc ${CFLAGS} -Iincludes -c $< -o $@

$(NAME): ${OBJS}
	@${CC} ${CFLAGS} -Iincludes ${OBJS} -o ${NAME}

$(NAME_CHECKER) : ${OBJS_CHECKER}
	@${CC} ${CFLAGS} -Iincludes ${OBJS_CHECKER} -o ${NAME_CHECKER}

all:    ${NAME} ${NAME_CHECKER}

bonus:	

clean:
	rm -rf ${OBJS}
	rm -rf ${OBJS_CHECKER}

fclean: clean 
	rm -rf ${NAME}
	rm -rf ${NAME_CHECKER}

re: 	fclean all                        

.PHONY : all clean fclean re
