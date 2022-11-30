NAME	= push_swap
CC		= gcc
CFLAGS	= -Wall -Werror -Wextra
RM		= rm -f

SRCS	=	$(wildcard *.c)

OBJS	=	$(patsubst %.c, %.o, $(SRCS))

%.o: %.c
			$(CC) $(CFLAGS) -c  $< -o $@

all:		lib $(NAME)

lib:
	cd libft && make && make bonus

$(NAME):	$(OBJS)
			$(CC) $(CFLAGS) -o $(NAME) $(OBJS) libft/*.o

clean:
			$(RM) $(OBJS) libft/*.o

fclean:		clean
			$(RM) $(NAME) libft/libft.a

re:			fclean all

.PHONY:		all clean fclean re lib
