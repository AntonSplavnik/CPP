#include <iostream>
#include <stack>
#include <string>
#include <cctype>

bool is_digit(char c) {
	return (c >= '0' && c <= '9');
}

bool is_operator(char c) {
	return (c == '+' || c == '-' || c == '*' || c == '/');
}

int main(int argc, char** argv) {
	if (argc != 2) {
		std::cerr << "Error" << std::endl;
		return 1;
	}

	std::string expression = std::string(argv[1]);
	std::stack<int> rpn;

	for (size_t i = 0; i < expression.length(); i++) {
		char c = expression[i];

		// Skip whitespace
		if (std::isspace(c))
			continue;

		// If digit, push to stack
		if (is_digit(c)) {
			rpn.push(c - '0');
		}
		// If operator, pop two operands and compute
		else if (is_operator(c)) {
			if (rpn.size() < 2) {
				std::cerr << "Error" << std::endl;
				return 1;
			}

			int b = rpn.top(); rpn.pop();
			int a = rpn.top(); rpn.pop();
			int result;

			switch (c)
			{
				case '+':
					result = a + b;
					break;
				case '-':
					result = a - b;
					break;
				case '*':
					result = a * b;
					break;
				case '/':
					if (b == 0) {
						std::cerr << "Error" << std::endl;
  						return 1;
					}
					result = a / b;
					break;
			}

			rpn.push(result);
		}
		else {
			std::cerr << "Error" << std::endl;
			return 1;
		}
	}

	// Valid expression should have exactly one value left
	if (rpn.size() != 1) {
		std::cerr << "Error" << std::endl;
		return 1;
	}

	std::cout << rpn.top() << std::endl;
	return 0;
}
