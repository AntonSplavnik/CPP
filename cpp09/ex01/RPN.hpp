#ifndef RPN_HPP
#define RPN_HPP

#include <stack>
#include <string>

class RPN {

	public:
		RPN();
		RPN(const RPN& other);
		RPN& operator=(const RPN& other);
		~RPN();

		int evaluate(const std::string& expression);

	private:
		std::stack<int> _stack;

		bool _isDigit(char c) const;
		bool _isOperator(char c) const;

};

#endif
