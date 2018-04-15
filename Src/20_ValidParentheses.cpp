/* Given a string containing just the characters '(', ')', '{', '}', '[' and ']',
* determine if the input string is valid.
*
* An input string is valid if:
*
* Open brackets must be closed by the same type of brackets.
* Open brackets must be closed in the correct order.
* Note that an empty string is also considered valid.
*
* Example 1:
*
* Input: "()"
* Output: true
* 
*/

#include <stack>
#include <string>
#include <cassert>
using namespace std;

bool isValid(string s) {

	stack<char> charStack;
	for (auto c : s) {
		if (c == '[' || c == '{' || c == '(')
			charStack.push(c);
		else if (c == ']') {
			if (!charStack.empty() && charStack.top() == '[')
				charStack.pop();
			else
				return false;
		}
		else if (c == '}') {
			if (!charStack.empty() && charStack.top() == '{')
				charStack.pop();
			else
				return false;
		}
		else if (c == ')') {
			if (!charStack.empty() && charStack.top() == '(')
				charStack.pop();
			else
				return false;
		}
	}
	return charStack.empty();

}

int main()
{
	string s = "(([]))";
	bool ans = true;
	bool ret = isValid(s);
	assert(ret == ans);
	return 0;
}
