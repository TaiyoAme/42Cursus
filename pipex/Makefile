# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: hehuang <hehuang@student.42lehavre.fr>     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/06/24 18:56:43 by hehuang           #+#    #+#              #
#    Updated: 2024/06/24 19:02:00 by hehuang          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = pipex

SRCS = pipex.c

OBJS = $(SRCS:.c=.o)

LIBFT = ./libft/libft.a

CC = cc

CFLAGS = -Wall -Wextra -Werror -g

all: $(NAME)


$(NAME): ${OBJS} $(LIBFT)
	@${CC} ${CFLAGS} -Iincludes ${OBJS} -o ${NAME} $(LIBFT)

$(LIBFT):
	make -C ./libft

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	$(RM) $(OBJS)
	make clean -C ./libft

fclean: clean
	$(RM) $(NAME) $(LIBFT)

re: fclean all

.PHONY: all clean fclean re
