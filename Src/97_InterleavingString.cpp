/* Given s1, s2, s3, find whether s3 is formed by the interleaving of s1 and s2.

Example 1:

Input: s1 = "aabcc", s2 = "dbbca", s3 = "aadbbcbcac"
Output: true
Example 2:

Input: s1 = "aabcc", s2 = "dbbca", s3 = "aadbbbaccc"
Output: false

*/
#include <vector>
#include <string>
#include <algorithm>
#include <cassert>
using namespace std;

bool isInterleave(string s1, string s2, string s3) {

	int N1 = s1.length(), N2 = s2.length(), N3 = s3.length();
	if (N1 + N2 != N3)
		return false;
	vector<vector<bool>> dp(N1 + 1, vector<bool>(N2 + 1, false));
	dp[0][0] = true;
	for (int i = 1; i <= N1; i++)
		dp[i][0] = dp[i - 1][0] && (s3[i - 1] == s1[i - 1]);

	for (int j = 1; j <= N2; j++)
		dp[0][j] = dp[0][j - 1] && (s3[j - 1] == s2[j - 1]);

	for (int i = 1; i <= N1; i++) {
		for (int j = 1; j <= N2; j++) {
			if (s3[i + j - 1] == s1[i - 1] && dp[i - 1][j])
				dp[i][j] = true;
			if (s3[i + j - 1] == s2[j - 1] && dp[i][j - 1])
				dp[i][j] = true;
		}
	}
	return dp[N1][N2];
}
int main()
{
	string s1 = "aabcc", s2 = "dbbca", s3 = "aadbbcbcac";
	bool ans = true;
	bool ret = isInterleave(s1, s2, s3);
	assert(ret == ans);
	return 0;
}
