# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: hehuang <hehuang@student.42lehavre.fr>     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/01/22 17:18:11 by hehuang           #+#    #+#              #
#    Updated: 2024/03/26 18:51:36 by hehuang          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = so_long

SOURCES = gnl/get_next_line.c \
            gnl/get_next_line_utils.c \
            src/main.c \
            src/so_long_utils.c \
			src/so_long_init.c \
			src/player.c \
			src/villain.c \
			src/map_checker.c \
			src/error_handler.c \
			src/free_data.c \
			src/animation.c \
			src/steps.c \
			src/utils2.c \
			src/item_list.c 

OBJECTS = $(SOURCES:.c=.o)
MLX = ./mlx_linux/libmlx.a
LIBFT = ./Libft/libft.a

CC = cc
CMLX = -Lmlx_linux -lmlx_Linux -L/usr/lib -Imlx_linux -lXext -lX11 -lm -lz
CFLAGS = -Wall -Wextra -Werror -g
CLINKS  = -ldl -lglfw -pthread -lm

all: $(NAME)

$(NAME): $(OBJECTS) $(MLX) $(LIBFT)
	$(CC) -o $(NAME) $(OBJECTS) $(MLX) $(LIBFT) $(CMLX) $(CLINKS)

$(MLX):
	make -C ./mlx_linux
	
$(LIBFT):
	make -C ./Libft

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	$(RM) $(OBJECTS)
	make clean -C ./mlx_linux
	make clean -C ./Libft

fclean: clean
	$(RM) $(NAME) $(PRINTF) $(LIBFT) $(PRINTF)

re: fclean all

.PHONY: all clean fclean re
