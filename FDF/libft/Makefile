NAME	= libft.a

CC		= cc
CFLAGS	= -Wall -Werror -Wextra
AR		= ar rcs
RM		= rm -f

SRCS_A	=	$(wildcard ft_*.c)
SRCS_B	=	$(wildcard ft_lst*.c)
SRCS	=	$(filter-out $(SRCS_B), $(SRCS_A))

OBJS	=	$(patsubst %.c, %.o, $(SRCS))
OBJS_B	=	$(patsubst %.c, %.o, $(SRCS_B))

%.o: %.c
			$(CC) $(CFLAGS) -c $< -o $@

all:		$(NAME)

$(NAME):	$(OBJS)
			$(AR) $(NAME) $(OBJS)

bonus:		$(NAME) $(OBJS_B)
			$(AR) $(NAME) $(OBJS_B)

clean:
			$(RM) $(OBJS) $(OBJS_B)

fclean:		clean
			$(RM) $(NAME)

re:			fclean all

.PHONY:		all bonus clean fclean re
