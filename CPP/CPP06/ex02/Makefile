# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: hehuang <hehuang@student.42lehavre.fr>     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/01/24 17:45:38 by hehuang           #+#    #+#              #
#    Updated: 2025/01/25 17:38:22 by hehuang          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = Identifier

SRCS = 	main.cpp \
		Base.cpp \
		A.cpp \
		B.cpp \
		C.cpp

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
