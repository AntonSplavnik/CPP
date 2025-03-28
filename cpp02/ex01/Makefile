CXX      = c++
CXXFLAGS = -std=c++98 -Wall -Wextra -Werror

SRCS     = main.cpp fixed_point.cpp
OBJDIR   = build
OBJS     = $(patsubst %.cpp,$(OBJDIR)/%.o,$(SRCS))
TARGET   = usefull_fixed_point

all: $(TARGET)

$(TARGET): $(OBJS)
	$(CXX) $(CXXFLAGS) $(OBJS) -o $(TARGET)

$(OBJDIR)/%.o: %.cpp | $(OBJDIR)
	$(CXX) $(CXXFLAGS) -c $< -o $@

$(OBJDIR):
	mkdir -p $(OBJDIR)

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(TARGET)
	rm -rf $(OBJDIR)

re: fclean all

.PHONY: all clean fclean re
