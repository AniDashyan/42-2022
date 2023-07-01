NAME	= miniRT

INCLDIR	= includes/

SRCDIR	= srcs/

LIB		= lib/

SRCFILES=	main.c					\
			parse.c					\
			check.c					\
			set_objects.c			\
			sphere.c				\
			plane.c					\
			cylinder.c				\
			cylinder_utils.c		\
			vector.c				\
			move_objects.c			\
			hook.c					\
			color.c					\
			color_utils.c			\
			zoom.c					\
			move.c					\
			rotate_xyz.c			\
			rotate_cam_dir.c		\
			light_ratio.c			\
			vector_operations.c		\
			change_parameters.c		\
			vector_utils.c			\
			vector_utils_2.c		\
			utils.c					\
			ray.c					\
			routine.c				\
			make_image.c			\
			rot_camera.c			\
			object_manipulations.c	\
			libft_utils.c			\
			libft_utils_2.c			\
			ft_split_set.c			\
			get_next_line.c			\

INCLFILES=	basics.h				\
			elements.h				\
			minirt.h				\
			mlx.h					\
			parse.h					\
			scene.h					\

SRCS	= $(addprefix $(SRCDIR), $(SRCFILES))
OBJS	= $(SRCS:.c=.o)
INCLS	= $(addprefix $(INCLDIR), $(INCLFILES))
CC		= cc
RM		= rm -rf

CFLAGS	= -I $(INCLDIR) -Wall -Wextra -Werror #-fsanitize=address -g#3#-Ofast
FLAGS = -L $(LIB)libft -lft -L. -lmlx# $(LIB)libmlx

MACOS_MACRO = -DMACOS
LINUX_MACRO = -DLINUX
MACOS_FLAGS	= -framework OpenGL -framework AppKit
LINUX_FLAGS = -lm -lX11 -lXext -lpthread

UNAME := $(shell uname)

ifeq ($(UNAME),Darwin)
	THREADS = $(shell sysctl -n hw.ncpu)
	CFLAGS += $(MACOS_MACRO)
	FLAGS += $(MACOS_FLAGS)
endif
ifeq ($(UNAME),Linux)
	THREADS = $(shell nproc --all)
	CFLAGS += $(LINUX_MACRO)
	FLAGS += $(LINUX_FLAGS)
endif

$(NAME): compilelibft $(OBJS) $(INCLS)
			$(CC) $(CFLAGS) $(OBJS) $(FLAGS) -o $(NAME)

compilelibft:
			make -C $(LIB)libft bonus

%.o: %.c $(INCLS)
			$(CC) $(CFLAGS) -c -I $(INCLDIR) -o $@ $<

all:		$(NAME)

clean:
			make clean -C $(LIB)libft
			$(RM) $(OBJS)

fclean:		clean
			make fclean -C $(LIB)libft
			$(RM) $(NAME)

re:			fclean all

run: $(NAME)
			./$< scenes/test.rt

run_all: $(NAME)
			./$< scenes/90spheres.rt &
			./$< scenes/cylinder.rt &
			./$< scenes/example.rt &
			./$< scenes/gradient.rt &
			./$< scenes/mollecules.rt &
			./$< scenes/peach.rt &
			./$< scenes/test.rt

.PHONY: $(NAME) all clean fclean re run run_all compilelibft
