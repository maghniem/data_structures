#include <string>
#include <iostream>
#include <stack>

//check a string of brackets for balance
// "{[()]}" is balanced
// "{[(])}" is unbalanced


//return "NO" when the brackets and unbalanced, "YES otherweise
//assume ascii values for the brackets
const std::string checkBalance(const std::string& bracket_string) {
	std::stack<char> bracket_stack;
	for (const auto& bracket : bracket_string) {
		if (bracket == '{' || bracket == '[' || bracket == '(')
			bracket_stack.push(bracket);
		else {
			if (bracket_stack.empty() || bracket - bracket_stack.top() != 1 && bracket - bracket_stack.top() != 2)
				return "NO";
			else
				bracket_stack.pop();
		}
	}
	return bracket_stack.empty() ? "YES" : "NO";
}

int main() {
  //first input is how many strings to check 
	int total_checks;
	std::cin >> total_checks;
 
  //input each string and get a "NO" or a "YES" for balance 
	std::string bracket_string;
	for (int i = 0; i < total_checks; i++) {
		std::cin >> bracket_string;
		std::cout << checkBalance(bracket_string) << std::endl;
	}

	return 0;
}
