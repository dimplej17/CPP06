NAME = ex00

SRCS = main.cpp scalarconverter.cpp

OBJS = $(SRCS:%.cpp=%.o)

all: $(NAME)

$(NAME): $(OBJS)
	c++ -o $(NAME) $(OBJS)

%.o: %.cpp
	c++ -c -Wall -Wextra -Werror -std=c++98 $< -o $@

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re