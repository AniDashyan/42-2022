NAME = philo

CC = cc

CFLAGS = -Wall -Werror -Wextra -fsanitize=address 

RM = rm -f

SRCS = $(wildcard *.c)

OBJS = $(SRCS:.c=.o)

all: ${NAME} 


${NAME}: ${OBJS}
	${CC} ${CFLAGS} -o ${NAME} ${OBJS} 

clean:
	${RM} ${OBJS} 

fclean:clean
	${RM} ${NAME}

re: fclean all

.PHONY: all clean fclean re

