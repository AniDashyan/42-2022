<<<<<<< HEAD
NAME = pipex.a

CC	= cc

CFLAGS	= -Wall -Werror -Wextra

AR		= ar rcs

=======
NAME	= pipex.a

CC		= cc
CFLAGS	= -Wall -Werror -Wextra
AR		= ar rcs
>>>>>>> 34a63c3f525fa4a5a01f8f36534fb641cfb78f24
RM		= rm -f

SRCS	=	$(wildcard *.c)

OBJS	=	$(patsubst %.c, %.o, $(SRCS))

%.o: %.c
			$(CC) $(CFLAGS) -c  $< -o $@

<<<<<<< HEAD
all:		ft_printf  lib $(NAME)

ft_printf:
	cd ft_printf && make

lib:
	cd ft_printf/libft && make && make bonus

=======
all:		printf $(NAME)

printf:
	cd ft_printf && make

>>>>>>> 34a63c3f525fa4a5a01f8f36534fb641cfb78f24
$(NAME):	$(OBJS)
			$(AR) $(NAME) $(OBJS) ft_printf/*.o
clean:
			$(RM) $(OBJS) ft_printf/*.o

fclean:		clean
<<<<<<< HEAD
			$(RM) $(NAME) ft_printf/libftprintf.a ft_printf/libft/libft.a

re:			fclean all

.PHONY:		all bonus clean fclean re ft_printf
=======
			$(RM) $(NAME) ft_printf/libftprintf.a

re:			fclean all

.PHONY:		all clean fclean re printf
>>>>>>> 34a63c3f525fa4a5a01f8f36534fb641cfb78f24
