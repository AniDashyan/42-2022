NAME = PmergeMe

TMP = objs

CXX = c++

CXXFLAGS = -std=c++98 -Wall -Wextra -Werror

SRCS = $(wildcard *.cpp)

OBJS = $(patsubst %.cpp, ./$(TMP)/%.o, $(SRCS))

RM = rm -rf

HEADER = $(wildcard *.hpp)

./$(TMP)/%.o: %.cpp $(HEADER) Makefile
	$(CXX) $(CXXFLAGS) -o $@ -c $<

all: $(NAME)

$(NAME): $(TMP) $(OBJS)
	$(CXX) $(CXXFLAGS) $(OBJS) -o $(NAME)

$(TMP):
	@mkdir -p $(TMP)

clean:
	$(RM) $(OBJS_DIR)
	$(RM) $(TMP)

fclean: clean
	$(RM) $(NAME)

re:	fclean all

.PHONY: all clean fclean re