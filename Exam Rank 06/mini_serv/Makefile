NAME = mini_serv
CC = gcc
CFLAGS = -Wall -Wextra -Werror
SRCS = $(wildcard *.c)
RM = rm -rf

all:
		$(CC) $(CFLAGS) $(SRCS) -o $(NAME)

fclean: 
	$(RM) $(NAME)

re: fclean all

.PHONY: all fclean re
