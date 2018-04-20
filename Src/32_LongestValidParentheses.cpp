/* Given a string containing just the characters '(' and ')', find the length of
* the longest valid (well-formed) parentheses substring.
*
* Example 1:
*
* Input: "(()"
* Output: 2
* Explanation: The longest valid parentheses substring is "()"
* Example 2:
*
* Input: ")()())"
* Output: 4
* Explanation: The longest valid parentheses substring is "()()"
*/

#include <vector>
#include <algorithm>
#include <cassert>
using namespace std;

/*
The main idea is as follows: construct a array dp[], for any dp[i], it stores the
longest length of valid parentheses which is end at i.

And the DP idea is :
  If s[i] is ‘(’, set longest[i] to 0,because any string end with ‘(’ cannot be
  a valid one.
Else if s[i] is ‘)’
  If s[i-1] is ‘(’, longest[i] = longest[i-2] + 2
  Else if s[i-1] is ‘)’ and s[i-longest[i-1]-1] == ‘(’, longest[i] = longest[i-1] + 2 + longest[i-longest[i-1]-2]

For example, input “()(())”, at i = 5, longest array is [0,2,0,0,2,0],
  longest[5] = longest[4] + 2 + longest[1] = 6.
*/
/* DP solution, run-time and space are both O(N) */

int longestValidParentheses(string s) {

	if (s.length() == 0)
		return 0;
	vector<int> dp(s.length(), 0);
	int maxLen = 0;

	for (int i = 1; i < s.length(); i++) {

		if (s[i] == ')') {
			if (s[i - 1] == '(') {
				dp[i] = 2 + (i >= 2 ? dp[i - 2] : 0);
				maxLen = max(maxLen, dp[i]);
			}
			else {
				//s[i-1] == ')'
				if (dp[i - 1] > 0 && i - 1 - dp[i - 1] >= 0 && s[i - 1 - dp[i - 1]] == '(') {

					if (i - 2 - dp[i - 1] >= 0 && dp[i - 2 - dp[i - 1]] > 0)
						dp[i] = dp[i - 1] + 2 + dp[i - 2 - dp[i - 1]];
					else
						dp[i] = dp[i - 1] + 2;
					maxLen = max(maxLen, dp[i]);
				}
			}
		}
	}
	return maxLen;
}

int main()
{
	string s = ")()())";
	int ans = 4;
	int ret = longestValidParentheses(s);
	assert(ret == ans);
	return 0;
}
