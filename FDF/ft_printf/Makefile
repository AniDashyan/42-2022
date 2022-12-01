NAME	= printf.a

CC		= cc
CFLAGS	= -Wall -Werror -Wextra
AR		= ar rcs
RM		= rm -f

SRCS	=	$(wildcard *.c)

OBJS	=	$(patsubst %.c, %.o, $(SRCS))

%.o: %.c
			$(CC) $(CFLAGS) -c  $< -o $@

all:		$(NAME)

$(NAME):	$(OBJS)
			$(AR) $(NAME) $(OBJS)
clean:
			$(RM) $(OBJS)

fclean:		clean
			$(RM) $(NAME)

re:			fclean all

.PHONY:		all clean fclean re
