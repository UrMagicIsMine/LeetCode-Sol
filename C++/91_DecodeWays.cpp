/* A message containing letters from A-Z is being encoded to numbers using the following mapping:

'A' -> 1
'B' -> 2
...
'Z' -> 26
Given a non-empty string containing only digits, determine the total number of ways to decode it.

Example 1:

Input: "12"
Output: 2
Explanation: It could be decoded as "AB" (1 2) or "L" (12).
Example 2:

Input: "226"
Output: 3
Explanation: It could be decoded as "BZ" (2 26), "VF" (22 6), or "BBF" (2 2 6).
*/
#include <vector>
#include <string>
#include <algorithm>
#include <cassert>
using namespace std;

/* dp = 's[i] decode'? dp[i-1] : 0 + 's[i-1, i] decode'? dp[i-2] : 0
 Run-time O(N); memory O(N), can be optimized to O(1)
 */

int numDecodings(string s) {

	int N = s.size();

	if (s[0] == '0')
		return 0;
	vector<int> dp(N + 1, 1);

	for (int i = 2; i <= N; i++) {

		string str = s.substr(i - 2, 2);
		int num = stoi(str);

		if (s[i - 1] == '0') {
			if (num == 20 || num == 10)
				dp[i] = dp[i - 2];
			else
				return 0;
		}
		else {
			if (num > 9 && num <= 26)
				dp[i] = dp[i - 1] + dp[i - 2];
			else
				dp[i] = dp[i - 1];
		}
	}
	return dp[N];
}

int main()
{
	string s = "12220";
	int ans = 3;
	int ret = numDecodings(s);
	assert(ret == ans);
	return 0;
}
