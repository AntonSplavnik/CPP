#include "RPN.hpp"
#include <stdexcept>
#include <cctype>

RPN::RPN() {}

RPN::RPN(const RPN& other) : _stack(other._stack) {}

RPN& RPN::operator=(const RPN& other) {
	if (this != &other)
		_stack = other._stack;
	return *this;
}

RPN::~RPN() {}

bool RPN::_isDigit(char c) const {
	return (c >= '0' && c <= '9');
}

bool RPN::_isOperator(char c) const {
	return (c == '+' || c == '-' || c == '*' || c == '/');
}

int RPN::evaluate(const std::string& expression) {
	while (!_stack.empty())
		_stack.pop();

	for (size_t i = 0; i < expression.length(); i++) {
		char c = expression[i];

		if (std::isspace(c))
			continue;

		if (_isDigit(c)) {
			_stack.push(c - '0');
		} else if (_isOperator(c)) {
			if (_stack.size() < 2)
				throw std::runtime_error("Error");

			int b = _stack.top(); _stack.pop();
			int a = _stack.top(); _stack.pop();
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
					if (b == 0)
						throw std::runtime_error("Error");
					result = a / b;
					break;
				default:
					throw std::runtime_error("Error");
			}

			_stack.push(result);
		} else {
			throw std::runtime_error("Error");
		}
	}

	if (_stack.size() != 1)
		throw std::runtime_error("Error");

	return _stack.top();
}
