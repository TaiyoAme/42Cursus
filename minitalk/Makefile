# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: hehuang <hehuang@student.42lehavre.fr>     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/02/26 19:19:51 by hehuang           #+#    #+#              #
#    Updated: 2024/02/26 19:58:11 by hehuang          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = minitalk

SERVER = server
CLIENT = client

SRC_CLIENT = client.c
SRC_SERVER = server.c

OBJ_CLIENT = $(SRC_CLIENT:.c=.o)
OBJ_SERVER = ${SRC_SERVER:.c=.o}

LIBFT = ./libft/libft.a

CC = cc
CFLAGS = -Wall -Wextra -Werror -g

all: $(SERVER) $(CLIENT)


$(SERVER): ${OBJ_SERVER} $(LIBFT)
	@${CC} ${CFLAGS} -Iincludes ${OBJ_SERVER} -o ${SERVER} $(LIBFT)

$(CLIENT) : ${OBJ_CLIENT} $(LIBFT)
	@${CC} ${CFLAGS} -Iincludes ${OBJ_CLIENT} -o ${CLIENT} $(LIBFT)

all:    ${SERVER} ${CLIENT}

$(LIBFT):
	make -C ./libft

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	$(RM) $(OBJ_SERVER) $(OBJ_CLIENT)
	make clean -C ./libft

fclean: clean
	$(RM) $(SERVER) $(CLIENT) $(LIBFT)

re: fclean all

.PHONY: all clean fclean re
