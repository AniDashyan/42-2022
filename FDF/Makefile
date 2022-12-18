NAME	= fdf
CC		= gcc
CFLAGS	= -Wall -Werror -Wextra -fsanitize=address
RM		= rm -f

SRCS	= $(wildcard *.c)

OBJS	=	$(patsubst %.c, %.o, $(SRCS))


MLX = -Lmlx -lmlx -framework OpenGL -framework AppKit

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

all:		lib printf $(NAME)

lib:
	cd libft && make && make bonus

printf:
	cd ft_printf && make

$(NAME):	$(OBJS) 
			 $(CC) $(MLX) $(CFLAGS) -o $(NAME) $(OBJS) libft/*.o ft_printf/*.o

clean:
			$(RM) $(OBJS) libft/*.o ft_printf/*.o

fclean:		clean
			$(RM) $(NAME) libft/libft.a ft_printf/printf.a

re:			fclean all

.PHONY:		all clean fclean re lib printf
