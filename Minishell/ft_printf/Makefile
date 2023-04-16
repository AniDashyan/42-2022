CC := gcc
CFLAGS := -Wall -Wextra -Werror

NAME := libftprintf.a

SRCS	= ft_c.c ft_d.c\
		  ft_p.c ft_s.c\
		  ft_u.c ft_xl.c\
		  ft_xu.c ft_printf.c\
		  ft_nbr_count.c\
		  ft_strlen_ft.c

OBJS := $(SRCS:.c=.o)

all: $(NAME)

$(NAME): $(OBJS)
	ar ru $(NAME) $(OBJS)

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
