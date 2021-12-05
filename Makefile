# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: msousa <mlrcbsousa@gmail.com>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/10/29 15:00:20 by msousa            #+#    #+#              #
#    Updated: 2021/12/05 12:39:39 by msousa           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CFLAGS	= -Wall -Wextra -Werror -g
LINKS		= -Llibft -lft
CC			= gcc
RM			= rm -f
INC			= -Iincludes -Ilibft
UNAME 	:= ${shell uname}
OBJ			= ${SRC:.c=.o}
SRC			= push_swap.c srcs/stack.c srcs/operations_0.c srcs/operations_1.c \
					srcs/operations_2.c

NAME		= push_swap

ifeq (${UNAME}, Linux)
CHECKER	= checker_linux
endif
ifeq (${UNAME}, Darwin)
CHECKER	= checker_Mac
endif

${NAME}:	${OBJ}
					${MAKE} -C libft
					${CC} ${CFLAGS} ${OBJ} ${LINKS} -o $@

%.o:%.c
					${CC} ${CFLAGS} ${INC} -c $< -o $@

all:			${NAME}

bonus:		all

style:
					-norminette $$( find . -type f \( -name "*.c" -or -name "*.h" \) )

leak:
					valgrind --tool=memcheck --leak-check=yes --show-reachable=yes \
					--num-callers=20 --track-fds=yes ./${NAME}

test:			${NAME}
					-./${NAME} 1 2 3 4
					-./${NAME} 1 2 3 hh
					-./${NAME} 1 2 3 2147483648
					-./${NAME} 1 2 3 -2147483649
					-./${NAME} 1 2 3 3
# ARG="4 67 3 87 23"; ./${NAME} $$ARG | wc -l
# ARG="4 67 3 87 23"; ./${NAME} $$ARG | ./${CHECKER} $$ARG

checker:	
					@echo 'Hello World from $@!'

bonus:		checker

clean:
					${MAKE} clean -C libft
					${RM} ${OBJ}

fclean:		clean
					${RM} ${NAME}

re: 			fclean all

.PHONY : 	all clean fclean re bonus
