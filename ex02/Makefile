#milb: mommy, i'd like to bureaucrap
NAME = idtype
HEADER = inc
CXX = g++
# CXXFLAGS = -std=c++98 -I$(HEADER) -Wall -Wextra -Werror
CXXFLAGS = -std=c++98 -Wall -Wextra -Werror
# SOURCE = src
# SRC_PATHS = $(addprefix $(SOURCE)/,$(SRCS))
SRCS = A.cpp  Base.cpp  B.cpp  C.cpp  main.cpp  util.cpp
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
