#milb: mommy, i'd like to bureaucrap
NAME = convert
HEADER = inc
CXX = c++
# CXXFLAGS = -std=c++98 -I$(HEADER) -Wall -Wextra -Werror
CXXFLAGS = -std=c++98 -Wall -Wextra -Werror
# SOURCE = src
# SRC_PATHS = $(addprefix $(SOURCE)/,$(SRCS))
SRCS = ScalarConverter.cpp main.cpp
OBJS = $(SRCS:.cpp=.o)

all: $(NAME)

$(NAME): $(OBJS)
	$(CXX) $(CXXFLAGS) -o $@ $^

%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

clean:
	rm -rf $(OBJS)

fclean: clean
	rm -rf $(NAME)

re: fclean all

.PHONY: all clean fclean re
