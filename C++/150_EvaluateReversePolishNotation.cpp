/* Evaluate the value of an arithmetic expression in Reverse Polish Notation.
*
* Valid operators are +, -, *, /. Each operand may be an integer or another expression.
*
* Some examples:
*   ["2", "1", "+", "3", "*"] -> ((2 + 1) * 3) -> 9
*   ["4", "13", "5", "/", "+"] -> (4 + (13 / 5)) -> 6
*
*/
#include <cctype>
#include <cassert>
#include <string>
#include <vector>
#include <stack>
using namespace std;

int evalRPN(vector<string>& tokens) {

	if (tokens.size() == 0)
		return 0;

	stack<int> iStack;

	for (int i = 0; i < tokens.size(); i++)
	{
		if (isdigit(tokens[i].back())) {
			iStack.push(stoi(tokens[i]));
		}
		else {
			int rhs = iStack.top();
			iStack.pop();
			int lhs = iStack.top();
			iStack.pop();
			if (tokens[i] == "+")
				iStack.push(lhs + rhs);
			else if (tokens[i] == "-")
				iStack.push(lhs - rhs);
			else if (tokens[i] == "*")
				iStack.push(lhs*rhs);
			else if (tokens[i] == "/")
				iStack.push(lhs / rhs);
		}
	}
	return iStack.top();
}

int main()
{
	vector<string> tokens = { "2", "1", "+", "3", "*" };

	int ret = evalRPN(tokens);
	assert(ret == 9);
	return 0;
}
