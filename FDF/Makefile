NAME	= fdf
CC		= gcc
CFLAGS	= -Wall -Werror -Wextra -fsanitize=address
RM		= rm -f

SRCS	= $(wildcard *.c)
GNL		= $(shell find ./get_next_line -name "*.c")

OBJS	=	$(patsubst %.c, %.o, $(SRCS))
OGNL	=	$(patsubst %.c, %.o, $(GNL))


MLX = -Lmlx -lmlx -framework OpenGL -framework AppKit

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

all:		lib printf $(NAME)

lib:
	cd libft && make && make bonus

printf:
	cd ft_printf && make

$(NAME):	$(OBJS) $(OGNL)
			$(CC) $(MLX) $(CFLAGS) -o $(NAME) $(OBJS) $(OGNL) libft/*.o ft_printf/*.o

clean:
			$(RM) $(OBJS) $(OGNL) libft/*.o ft_printf/*.o

fclean:		clean
			$(RM) $(NAME) libft/libft.a ft_printf/printf.a

re:			fclean all

.PHONY:		all clean fclean re lib printf
