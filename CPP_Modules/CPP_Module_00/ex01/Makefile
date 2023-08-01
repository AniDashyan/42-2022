NAME		= phonebook
CXX			= c++
CXXFLAGS	= -Wall -Wextra -Werror -fsanitize=address -std=c++98
RM			= rm -f

SRCS	= $(wildcard *.cpp)
OBJS	= $(patsubst %.cpp, %.o, $(SRCS))

HEADERS = $(wildcard *.hpp)

%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

all:	$(NAME)

$(NAME):	$(OBJS) $(HEADERS)
			 $(CXX) $(CXXFLAGS) -o $(NAME) $(OBJS)

clean:
			$(RM) $(OBJS)

fclean:		clean
			$(RM) $(NAME)

re:			fclean all

.PHONY:		all clean fclean re