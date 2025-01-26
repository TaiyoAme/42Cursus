# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: hehuang <hehuang@student.42lehavre.fr>     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/12/12 17:13:12 by hehuang           #+#    #+#              #
#    Updated: 2024/12/13 16:48:28 by hehuang          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = zombie

SRCS = Zombie.cpp \
	   newZombie.cpp \
	   randomChump.cpp \
	   main.cpp

OBJS = ${SRCS:.cpp=.o}

FLAGS = -Wall -Wextra -Werror -std=c++98 -g

CC = c++

all : ${NAME}

${NAME} : ${OBJS}
	${CC} ${FLAGS} ${OBJS} -o ${NAME}

clean :
	${RM} ${OBJS}

fclean : clean
	${RM} ${NAME}

re : fclean all
