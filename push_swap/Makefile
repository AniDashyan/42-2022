NAME	= push_swap

CC		= cc
CFLAGS	= -Wall -Werror -Wextra
RM		= rm -f

SRCS	=	$(wildcard *.c)

OBJS	=	$(patsubst %.c, %.o, $(SRCS))

%.o: %.c
			$(CC) $(CFLAGS) -c  $< -o $@

all:		print_f lib $(NAME)

print_f:
	cd ft_printf && make

lib:
	cd libft && make && make bonus

$(NAME):	$(OBJS)
			$(CC) -o $(NAME) $(OBJS) ft_printf/*.o libft/*.o

clean:
			$(RM) $(OBJS) ft_printf/*.o libft/*.o

fclean:		clean
			$(RM) $(NAME) ft_printf/libftprintf.a libft/libft.a

re:			fclean all

.PHONY:		all clean fclean re print_f lib
