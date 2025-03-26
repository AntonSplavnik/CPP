CXX     = c++
CXXFLAGS= -std=c++98 -Wall -Wextra -Werror

SRCS    = tests.cpp Account.cpp
OBJS    = $(SRCS:.cpp=.o)
TARGET  = my_test

all: $(TARGET)

$(TARGET): $(OBJS)
	$(CXX) $(CXXFLAGS) $(OBJS) -o $(TARGET)

%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(TARGET)

re: fclean all

.PHONY: all clean fclean re
