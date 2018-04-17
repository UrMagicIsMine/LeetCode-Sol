/* Given an input string (s) and a pattern (p), implement regular expression
* matching with support for '.' and '*'.
*
* '.' Matches any single character.
* '*' Matches zero or more of the preceding element.
* The matching should cover the entire input string (not partial).
*
* Note:
*
* s could be empty and contains only lowercase letters a-z.
* p could be empty and contains only lowercase letters a-z, and characters like . or *.
* Example 1:
*
* Input:
* s = "aa"
* p = "a"
* Output: false
* Explanation: "a" does not match the entire string "aa".
* Example 2:
*
* Input:
* s = "aa"
* p = "a*"
* Output: true
* Explanation: '*' means zero or more of the precedeng element, 'a'. Therefore,
* by repeating 'a' once, it becomes "aa".
* Example 3:
*
* Input:
* s = "ab"
* p = ".*"
* Output: true
* Explanation: ".*" means "zero or more (*) of any character (.)".
* Example 4:
*
* Input:
* s = "aab"
* p = "c*a*b"
* Output: true
* Explanation: c can be repeated 0 times, a can be repeated 1 time. Therefore it
* matches "aab".
* Example 5:
*
* Input:
* s = "mississippi"
* p = "mis*is*p*."
* Output: false
*/

#include <vector>
#include <cassert>
using namespace std;

bool isMatch(string s, string p) {

	int M = p.length(), N = s.length();
	vector<vector<bool>> dp(M + 1, vector<bool>(N + 1, false));
	dp[0][0] = true;
	for (int i = 1; i <= M; i++) {
		if (p[i] == '*') {
			dp[i + 1][0] = dp[i - 1][0];
		}
	}

	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= M; j++) {

			if (p[j - 1] == s[i - 1] || p[j - 1] == '.')
				dp[j][i] = dp[j - 1][i - 1];
			else if (p[j - 1] == '*') {
				if (p[j - 2] == s[i - 1] || p[j - 2] == '.')
					dp[j][i] = dp[j][i - 1] || dp[j - 2][i];
				else
					dp[j][i] = dp[j - 2][i];
			}

		}
	}

	return dp[M][N];
}

int main()
{
	string s1 = "mississippi", p1 = "mis*is*p*.";
	bool ans1 = false;
	bool ret1 = isMatch(s1, p1);
	assert(ret1 == ans1);

	string s2 = "aab", p2 = "c*a*b";
	bool ans2 = true;
	bool ret2 = isMatch(s2, p2);
	assert(ret2 == ans2);
	return 0;
}
