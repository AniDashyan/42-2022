NAME = pipex.a

CC	= cc

CFLAGS	= -Wall -Werror -Wextra 

AR		= ar rcs

RM		= rm -f

SRCS	=	$(wildcard *.c)

OBJS	=	$(patsubst %.c, %.o, $(SRCS))

%.o: %.c
			$(CC) $(CFLAGS) -c  $< -o $@

all:		ft_printf  $(NAME)

ft_printf:
	cd ft_printf && make

$(NAME):	$(OBJS)
			$(AR) $(NAME) $(OBJS) ft_printf/*.o
clean:		
			$(RM) $(OBJS) ft_printf/*.o

fclean:		clean
			$(RM) $(NAME) ft_printf/libftprintf.a

re:			fclean all

.PHONY:		all bonus clean fclean re ft_printf
