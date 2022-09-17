NAME	= libftprintf.a

CC		= cc
<<<<<<< HEAD
CFLAGS	= -Wall -Werror -Wextra
=======
CFLAGS	= -Wall -Werror -Wextra 
>>>>>>> 34a63c3f525fa4a5a01f8f36534fb641cfb78f24
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
<<<<<<< HEAD
clean:
=======
clean:		
>>>>>>> 34a63c3f525fa4a5a01f8f36534fb641cfb78f24
			$(RM) $(OBJS) libft/*.o

fclean:		clean
			$(RM) $(NAME) libft/libft.a

re:			fclean all

.PHONY:		all bonus clean fclean re lib
