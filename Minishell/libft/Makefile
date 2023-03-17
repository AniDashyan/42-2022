
# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: sokhacha <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/03/23 13:47:52 by sokhacha          #+#    #+#              #
#    Updated: 2022/03/25 14:52:30 by sokhacha         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #
NAME = libft.a

CC = cc

CFLAGS = -Wall -Wextra -Werror 

RM = rm -f

SRCS = $(wildcard *.c)

OBJS = $(SRCS:.c=.o)

all: ${NAME}

${NAME}:${OBJS}
	ar rcs ${NAME} ${OBJS}

%.o:%.c
	$(CC) $(CFLAGS) -c $^ -o $@


clean:
	${RM} ${OBJS}

fclean:clean
	${RM} ${NAME}

re:fclean all

.PHONY: all clean fclean re
