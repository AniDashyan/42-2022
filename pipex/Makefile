NAME	= pipex.a

CC		= cc
CFLAGS	= -Wall -Werror -Wextra
AR		= ar rcs
RM		= rm -f

SRCS	=	$(wildcard *.c)

OBJS	=	$(patsubst %.c, %.o, $(SRCS))

%.o: %.c
			$(CC) $(CFLAGS) -c  $< -o $@

all:		ft_printf $(NAME)

ft_printf:
	cd ft_printf && make

$(NAME):	$(OBJS)
			$(AR) $(NAME) $(OBJS) ft_printf/*.o ft_printf/libft/*.o
clean:
			$(RM) $(OBJS) ft_printf/*.o ft_printf/libft/*.o

fclean:		clean
			$(RM) $(NAME) ft_printf/libftprintf.a ft_printf/libft/libft.a

re:			fclean all

.PHONY:		all clean fclean re ft_printf
