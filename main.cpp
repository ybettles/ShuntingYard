#include "main.h"

void shunt(std::string infix) {
	// operands that are accepted in this algorithm bc i really can't check for all of them
	char operands[5] = { '+', '-', '/', '*', '^' };
	// operator stack
	std::stack<char> operatorStack;
	// output queue
	std::queue<char> outputQueue;

	for (int i{ 0 }; i <= infix.length(); ++i) {
		// this is the character that were are trying to check whether its an operand or not
		char currentChar = infix[i];
		// check if the char ur looking at is an operand or not
		bool isOperand = std::end(operands) != std::find(std::begin(operands), std::end(operands), currentChar);
		if (isOperand) {
			// precedence check: is current one lower than top of stack?
			if (!operatorStack.empty() && isLowerPrecedence(currentChar, operatorStack.top())) {
				// pop everything off
				while (!operatorStack.empty()) {
					outputQueue.push(operatorStack.top());
					operatorStack.pop();
				}
			}
			// check if equal precedence to top of stack
			else if (!operatorStack.empty() && isEqualPrecedence(currentChar, operatorStack.top())) {
				// pop until you reach an operator of differing precedence
				while (!operatorStack.empty() && isEqualPrecedence(currentChar, operatorStack.top())) {
					outputQueue.push(operatorStack.top());
					operatorStack.pop();
				}
			}
			// once things are popped off if needed, or not if not, then the current operator needs pushing on
			operatorStack.push(currentChar);
		} else {
			// this code is reached only if the char was not an operator. therefore gets pushed to output queue instead
			outputQueue.push(currentChar);
		}
	}
	// once the whole expressino has been gone through, any operators left over need to be pushed to output queue
	while (!operatorStack.empty()) {
		outputQueue.push(operatorStack.top());
		operatorStack.pop();
	}
	// then we can print out the queue first to last
	while (!outputQueue.empty()) {
		std::cout << outputQueue.front() << " ";
		outputQueue.pop();
	}
}

int precedence(char operand) {
	// + and - are joint lowest precedence
	if (operand == '+' || operand == '-')
		return 1;
	// * and / are joint middle precedence
	else if (operand == '*' || operand == '/')
		return 2;
	// ^ (exponentiation) has highest precedence
	else if (operand == '^')
		return 3;
	// theres no error case here but we will leave that for future yas xoxo
}

bool isLowerPrecedence(char op1, char op2) {

	return precedence(op1) < precedence(op2);
}

bool isEqualPrecedence(char op1, char op2) {

	return precedence(op1) == precedence(op2);
}

int main() {
	shunt("1+2*3/4+5");
	return 0;
}
