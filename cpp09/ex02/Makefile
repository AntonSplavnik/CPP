# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                         :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: antonsplavnik <antonsplavnik@student.42    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/02/11 20:30:00 by antonsplavn       #+#    #+#              #
#    Updated: 2025/02/11 20:30:00 by antonsplavn      ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = PmergeMe

CXX = c++
CXXFLAGS = -Wall -Wextra -Werror -std=c++98

SRCDIR = .
OBJDIR = obj

SOURCES = main.cpp

OBJECTS = $(addprefix $(OBJDIR)/, $(SOURCES:.cpp=.o))

debug: CXXFLAGS += -DDEBUG
debug: re

all: $(NAME)

$(NAME): $(OBJECTS)
	$(CXX) $(CXXFLAGS) $(OBJECTS) -o $(NAME)

$(OBJDIR)/%.o: $(SRCDIR)/%.cpp
	@mkdir -p $(OBJDIR)
	$(CXX) $(CXXFLAGS) -c $< -o $@

clean:
	rm -rf $(OBJDIR)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
