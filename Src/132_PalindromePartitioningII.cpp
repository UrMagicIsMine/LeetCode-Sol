/*
Given a string s, partition s such that every substring of the partition is a palindrome.

Return the minimum cuts needed for a palindrome partitioning of s.

Example:

Input: "aab"
Output: 1
Explanation: The palindrome partitioning ["aa","b"] could be produced using 1 cut.
*/

#include <vector>
#include <string>
#include <algorithm>
#include <cassert>
using namespace std;

int minCut(string s) {
	int N = s.length();
	if (N == 0)
		return 0;
	vector<vector<bool>> isPal(N, vector<bool>(N, false));
	vector<int> dp(N + 1);
	for (int i = 0; i <= N; i++)
		dp[i] = i - 1;

	for (int j = 1; j < N; j++) {
		for (int i = j; i >= 0; i--) {
			if (s[i] == s[j] && ((j - i) < 2 || isPal[i + 1][j - 1])) {
				isPal[i][j] = true;
				dp[j + 1] = min(dp[j + 1], dp[i] + 1);
			}
		}
	}
	return dp[N];
}

int main()
{
	string s = "aab";
	int ans = 1;
	int ret = minCut(s);
	assert(ret == ans);
	return 0;
}
