NAME = ex02

SRCS = main.cpp Base.cpp A.cpp B.cpp C.cpp

OBJS = $(SRCS:%.cpp=%.o)

all: $(NAME)

$(NAME): $(OBJS)
	c++ -o $(NAME) $(OBJS)

%.o: %.cpp
	c++ -c -Wall -Wextra -Werror -std=c++11 $< -o $@

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re