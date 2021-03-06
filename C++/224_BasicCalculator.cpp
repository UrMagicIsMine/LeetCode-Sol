/* Implement a basic calculator to evaluate a simple expression string.
*
* The expression string may contain open ( and closing parentheses ), the plus
* + or minus sign -, non-negative integers and empty spaces .
*
* You may assume that the given expression is always valid.
*
* Some examples:
* "1 + 1" = 2
* " 2-1 + 2 " = 3
* "(1+(4+5+2)-3)+(6+8)" = 23
*/

#include <vector>
#include <string>
#include <stack>
#include <cassert>
using namespace std;

int _calculate_sln1(string s, int & i) {
	//int val = 0;
	stack<int> numstack;
	stack<char> opstack;
	for (; i < s.length(); i++) {

		if (s[i] == ' ')
			continue;

		if (s[i] == '+' || s[i] == '-') {
			opstack.push(s[i]);
		}
		else {

			int num;
			if (isdigit(s[i])) {
				int len = 1;
				while (isdigit(s[i + len])) {
					len++;
				}
				num = stoi(s.substr(i, len));
				i = i + len - 1;
			}
			else if (s[i] == '(') {
				//int pos = s.find_first_of(')', i);
				i++;
				num = calculate(s, i);
			}
			else if (s[i] == ')') {
				//i++;
				return numstack.top();
			}

			if (opstack.empty())
				numstack.push(num);
			else {
				if (opstack.top() == '+')
					numstack.top() += num;
				else if (opstack.top() == '-')
					numstack.top() -= num;
				opstack.pop();
			}
		}
	}
	return numstack.top();
}

int _calculate_sln2(string& s, int& i) {
		int ret = 0;
		char op = '+';
		for(; i < s.length(); i++){

				if(s[i] == ' ')
						continue;
				if(isdigit(s[i])){
						int j = i + 1;
						int num = s[i] - '0';
						while(j < s.length() && isdigit(s[j])){
								num *= 10;
								num += s[j] - '0';
								j++;
						}
						i = j-1;
						if(op == '+')
								ret += num;
						else
								ret -= num;
				}
				else if(s[i] == '+' || s[i] == '-')
						op = s[i];
				else if( s[i] == '(' ){
						i++;
						int num = calculate(s, i);
						//i = j;
						if(op == '+')
								ret += num;
						else
								ret -= num;
				}
				else if( s[i] == ')' )
						return ret;
		}
		return ret;
}

int calculate(string s) {
	int i = 0;
	return _calculate_sln2(s, i);
}

int main()
{
	string s = "(1+(4+5+2)-3)+(6+8)";
	int ans = 20;
	int ret = calculate(s);
	assert(ret == ans);
	return 0;
}
