# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: hehuang <hehuang@student.42lehavre.fr>     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/05/05 16:12:51 by hehuang           #+#    #+#              #
#    Updated: 2024/05/29 20:03:33 by hehuang          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = philo

SRCS = src/main.c \
	   src/ph_event.c \
	   src/ph_init.c \
	   src/utils.c \
	   src/monitor.c

OBJS = $(SRCS:.c=.o)

LIBFT = ./libft/libft.a

CC = cc

CFLAGS = -Wall -Wextra -Werror #-g -fsanitize=thread

all: $(NAME)


$(NAME): ${OBJS} $(LIBFT)
	@${CC} ${CFLAGS} -Iincludes ${OBJS} -o ${NAME} $(LIBFT) -lpthread 

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
