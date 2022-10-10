NAME	= pipex

CC		= cc
CFLAGS	= -Wall -Werror -Wextra
RM		= rm -f

SRCS	=	$(wildcard *.c)

OBJS	=	$(patsubst %.c, %.o, $(SRCS))

%.o: %.c
			$(CC) $(CFLAGS) -c  $< -o $@

all:		print_f $(NAME)

print_f:
	cd ft_printf && make

$(NAME):	$(OBJS)
			$(CC) -o $(NAME) $(OBJS) ft_printf/*.o

clean:
			$(RM) $(OBJS) ft_printf/*.o

fclean:		clean
			$(RM) $(NAME) ft_printf/printf.a

re:			fclean all

.PHONY:		all clean fclean re print_f
