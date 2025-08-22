# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: antonsplavnik <antonsplavnik@student.42    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/08/07 12:51:00 by antonsplavn       #+#    #+#              #
#    Updated: 2025/08/21 22:30:14 by antonsplavn      ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# Program name
NAME		= bureaucrat

# Compiler and flags
CXX			= c++
CXXFLAGS	= -Wall -Wextra -Werror -std=c++98

# Source files
SRCS		= main.cpp \
			  Bureaucrat.cpp \
			  AForm.cpp \
			  PresidentialPardonForm.cpp \
			  RobotomyRequestForm.cpp \
			  ShrubberyCreationForm.cpp \
			  Intern.cpp

# Object directory
OBJDIR		= obj

# Object files
OBJS		= $(SRCS:%.cpp=$(OBJDIR)/%.o)

# Header files
HEADERS		= Bureaucrat.hpp

# Colors for output
RED			= \033[0;31m
GREEN		= \033[0;32m
YELLOW		= \033[0;33m
BLUE		= \033[0;34m
MAGENTA		= \033[0;35m
CYAN		= \033[0;36m
WHITE		= \033[0;37m
RESET		= \033[0m

# Default target
all: $(NAME)

# Build the executable
$(NAME): $(OBJS)
	@echo "$(CYAN)Linking $(NAME)...$(RESET)"
	@$(CXX) $(CXXFLAGS) $(OBJS) -o $(NAME)
	@echo "$(GREEN)✓ $(NAME) compiled successfully!$(RESET)"

# Create object directory
$(OBJDIR):
	@mkdir -p $(OBJDIR)

# Compile source files to object files
$(OBJDIR)/%.o: %.cpp $(HEADERS) | $(OBJDIR)
	@echo "$(YELLOW)Compiling $<...$(RESET)"
	@$(CXX) $(CXXFLAGS) -c $< -o $@

# Clean object files
clean:
	@echo "$(RED)Cleaning object files...$(RESET)"
	@rm -rf $(OBJDIR)
	@echo "$(GREEN)✓ Object files cleaned!$(RESET)"

# Clean everything
fclean: clean
	@echo "$(RED)Cleaning executable...$(RESET)"
	@rm -f $(NAME)
	@echo "$(GREEN)✓ Everything cleaned!$(RESET)"

# Rebuild everything
re: fclean all

# Run the program
run: $(NAME)
	@echo "$(MAGENTA)Running $(NAME)...$(RESET)"
	@./$(NAME)

# Debug build with additional flags
debug: CXXFLAGS += -g -DDEBUG
debug: fclean $(NAME)
	@echo "$(BLUE)✓ Debug build completed!$(RESET)"

# Check for leaks (macOS)
leaks: $(NAME)
	@echo "$(CYAN)Checking for memory leaks...$(RESET)"
	@leaks --atExit -- ./$(NAME)

# Display help
help:
	@echo "$(CYAN)Available targets:$(RESET)"
	@echo "  $(GREEN)all$(RESET)     - Build the program"
	@echo "  $(GREEN)clean$(RESET)   - Remove object files"
	@echo "  $(GREEN)fclean$(RESET)  - Remove object files and executable"
	@echo "  $(GREEN)re$(RESET)      - Rebuild everything"
	@echo "  $(GREEN)run$(RESET)     - Build and run the program"
	@echo "  $(GREEN)debug$(RESET)   - Build with debug flags"
	@echo "  $(GREEN)leaks$(RESET)   - Check for memory leaks (macOS)"
	@echo "  $(GREEN)help$(RESET)    - Display this help message"

# Phony targets
.PHONY: all clean fclean re run debug leaks help
