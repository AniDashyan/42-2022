NAME = miniRT

HEADER = $(wildcard ./includes/*)

TMP = objs

LIBFT_DIR = libft
LIBFT = $(LIBFT_DIR)/libft.a

SRCS = $(wildcard ./srcs/*.c)

OBJS = $(patsubst ./srcs/%.c, $(TMP)/%.o, $(SRCS))

CC = cc
RM = rm -rf

CFLAGS = -Imlx -I./includes -Wall -Wextra -Werror #-fsanitize=address -g#3#-Ofast
LDFLAGS = -L$(LIBFT_DIR) -lft -lmlx -framework OpenGL -framework AppKit

all: $(NAME)

$(NAME): $(OBJS) | $(LIBFT)
	$(CC) $(CFLAGS) $(OBJS) $(LDFLAGS) -o $(NAME)

$(TMP)/%.o: ./srcs/%.c $(HEADER) | $(TMP)
	$(CC) $(CFLAGS) -c $< -o $@

$(TMP):
	mkdir -p $(TMP)

$(LIBFT):
	@make --no-print-directory -C $(LIBFT_DIR)

clean:
	@make --no-print-directory clean -C $(LIBFT_DIR)
	$(RM) $(TMP)

fclean: clean
	@make --no-print-directory fclean -C $(LIBFT_DIR)
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re