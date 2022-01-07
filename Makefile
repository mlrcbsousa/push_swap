# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: msousa <msousa@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/10/29 15:00:20 by msousa            #+#    #+#              #
#    Updated: 2022/01/07 15:03:41 by msousa           ###   ########.fr        #
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
					srcs/operations_2.c srcs/sort.c

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

test_0:		${NAME}
					-./${NAME} 1 2 3 4
					-./${NAME} 1 2 3 hh
					-./${NAME} 1 2 3 2147483648
					-./${NAME} 1 2 3 -2147483649
					-./${NAME} 1 2 3 3

test_1:		${NAME}
					-ARG="1 2 3 2147483648"; ./${NAME} $$ARG | wc -l
					-ARG="1 2 3 2147483648"; ./${NAME} $$ARG | ./${CHECKER} $$ARG
					-ARG="1 2 3 hh"; ./${NAME} $$ARG | wc -l
					-ARG="1 2 3 hh"; ./${NAME} $$ARG | ./${CHECKER} $$ARG

test_2:		${NAME}
					-./${NAME} 1 2 3
					-./${NAME} 1 2
					-./${NAME} 2 1
					-./${NAME} 1 3 2
					-./${NAME} 2 1 3
					-./${NAME} 2 3 1
					-./${NAME} 3 2 1
					-./${NAME} 3 1 2

test_3:		${NAME}
					-ARG="1 2 3"; ./${NAME} $$ARG | wc -l
					-ARG="1 2 3"; ./${NAME} $$ARG | ./${CHECKER} $$ARG
					-ARG="2 1 3"; ./${NAME} $$ARG | wc -l
					-ARG="2 1 3"; ./${NAME} $$ARG | ./${CHECKER} $$ARG

test:			test_0 test_1 test_2 test_3

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
