NAME		= ./class
CPP			= c++
CPPFLAGS	= -Wall -Wextra -Werror -fsanitize=address -std=c++98
RM			= rm -f

SRCS	= $(wildcard *.cpp)
OBJS	= $(patsubst %.cpp, %.o, $(SRCS))

%.o: %.cpp
	$(CPP)  -c $< -o $@

all:	$(NAME)

$(NAME):	$(OBJS) 
			 $(CPP) $(CPPFLAGS) -o $(NAME) $(OBJS)

clean:
			$(RM) $(OBJS)

fclean:		clean
			$(RM) $(NAME)

re:			fclean all

.PHONY:		all clean fclean re
