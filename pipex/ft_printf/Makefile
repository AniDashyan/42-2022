NAME	= libftprintf.a

CC		= cc
CFLAGS	= -Wall -Werror -Wextra
AR		= ar rcs
RM		= rm -f

SRCS	=	$(wildcard *.c)

OBJS	=	$(patsubst %.c, %.o, $(SRCS))

%.o: %.c
			$(CC) $(CFLAGS) -c  $< -o $@

all:		lib $(NAME)

lib:
	cd libft && make && make bonus

$(NAME):	$(OBJS)
			$(AR) $(NAME) $(OBJS) libft/*.o
clean:
			$(RM) $(OBJS) libft/*.o

fclean:		clean
			$(RM) $(NAME) libft/libft.a

re:			fclean all

.PHONY:		all bonus clean fclean re lib
