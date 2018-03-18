/* Given n pairs of parentheses, write a function to generate all combinations
* of well-formed parentheses.
*
* For example, given n = 3, a solution set is:
*
* [
*   "((()))",
*   "(()())",
*   "(())()",
*   "()(())",
*   "()()()"
* ]
*/

#include <string>
#include <vector>
#include <cassert>
using namespace std;

void _genParBT(vector<string>&resl, string &cur, int nLeft, int nRight) {

	if (nLeft == 0 && nRight == 0) {
		resl.push_back(cur);
		return;
	}
	else {

		if (nLeft > 0) {
			cur.push_back('(');
			_genParBT(resl, cur, nLeft - 1, nRight);
			cur.pop_back();
		}
		if (nRight > nLeft) {
			cur.push_back(')');
			_genParBT(resl, cur, nLeft, nRight - 1);
			cur.pop_back();
		}

	}
}

vector<string> generateParenthesis(int n) {
	vector<string> resl;
	string cur;
	_genParBT(resl, cur, n, n);
	return resl;
}

int main()
{
	vector<string> ret = generateParenthesis(3);
	vector<string> ans = { "((()))","(()())","(())()","()(())","()()()" };
	assert(ret == ans);
	return 0;
}
