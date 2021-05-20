# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: thgillai <thgillai@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/04/30 12:39:59 by thgillai          #+#    #+#              #
#    Updated: 2021/05/20 16:38:46 by thgillai         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCNAME =	src/main.c src/swap.c src/rotate.c\
			
			

SRCS	= ${SRCNAME}

OBJS	= ${SRCS:.c=.o}

NAME	= push_swap

CC		= gcc -g -fsanitize=address
RM		= rm -f
CFLAGS	= -Wall -Wextra -Werror -I. -I./libft

.c.o:
			${CC} ${CFLAGS} -c $< -o ${<:.c=.o}

${NAME}:	${OBJS}
		make -C libft
		${CC} -o ${NAME} ${OBJS} -L./libft -lft

all: 		${NAME}

clean:
			make -C libft clean
			${RM} ${OBJS}

fclean:		clean
			make -C libft fclean
			${RM} ${NAME}

re:		fclean all

c:		all clean

.PHONY:		clean fclean re all
