/* Implement a basic calculator to evaluate a simple expression string.
*
* The expression string contains only non-negative integers, +, -, *, / operators
* and empty spaces . The integer division should truncate toward zero.
*
* You may assume that the given expression is always valid.
*
* Some examples:
* "3+2*2" = 7
* " 3/2 " = 1
* " 3+5 / 2 " = 5
* Note: Do not use the eval built-in library function.
*/

#include <vector>
#include <string>
#include <stack>
#include <cassert>
using namespace std;

int calculate(string s) {

	stack<int> nums;
	char sign = '+';

	int num = 0;

	for (int i = 0; i < s.length(); i++) {

		if (s[i] == ' ') {
			continue;
		}
		if (s[i] >= '0' && s[i] <= '9') {

			int len = 1;
			while (s[i + len] >= '0' && s[i + len] <= '9') {
				len++;
			}
			num = stoi(s.substr(i, len));
			i = i + len-1;

			if (sign == '+')
				nums.push(num);
			else if (sign == '-')
				nums.push(-num);
			else if (sign == '*')
				nums.top() *= num;
			else if (sign == '/')
				nums.top() /= num;
		}
		else
			sign = s[i];
	}

	int ret = 0;
	while (!nums.empty()) {

		ret += nums.top();
		nums.pop();
	}
	return ret;
}

int main()
{
	string s = "3+2*2";
	int ans = 7;
	int ret = calculate(s);
	assert(ret == ans);
	return 0;
}
