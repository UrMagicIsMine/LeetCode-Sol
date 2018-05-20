/* Given a string S and a string T, count the number of distinct subsequences of
* S which equals T.
*
* A subsequence of a string is a new string which is formed from the original
* string by deleting some (can be none) of the characters without disturbing the
* relative positions of the remaining characters. (ie, "ACE" is a subsequence of
* "ABCDE" while "AEC" is not).
*
* Example 1:
*
* Input: S = "rabbbit", T = "rabbit"
* Output: 3
* Explanation:
*
* As shown below, there are 3 ways you can generate "rabbit" from S.
* (The caret symbol ^ means the chosen letters)
*
* rabbbit
* ^^^^ ^^
* rabbbit
* ^^ ^^^^
* rabbbit
* ^^^ ^^^
* Example 2:
*
* Input: S = "babgbag", T = "bag"
* Output: 5
* Explanation:
*
* As shown below, there are 5 ways you can generate "bag" from S.
* (The caret symbol ^ means the chosen letters)
*
* babgbag
* ^^ ^
* babgbag
* ^^    ^
* babgbag
* ^    ^^
* babgbag
*   ^  ^^
* babgbag
*     ^^^
*/

#include <vector>
#include <string>
#include <cassert>
using namespace std;

/* Well, a dynamic programming problem. Let's first define its state dp[i][j]
to be the number of distinct subsequences of t[0..i - 1] in s[0..j - 1]. Then
we have the following state equations:

1) If t[i - 1] != s[j - 1], the distinct subsequences will not include s[j - 1]
and thus all the number of distinct subsequences will simply be those in
s[0..j - 2], which corresponds to dp[i][j - 1];
2) If t[i - 1] == s[j - 1], the number of distinct subsequences include two parts:
those with s[j - 1] and those without;
3) An empty string will have exactly one subsequence in any string :
4) Non-empty string will have no subsequences in an empty string.
*/

/* Solution 1: run-time O(MN), memeory O(MN)*/

int numDistinct_Sln1(string s, string t) {
	int N1 = s.length(), N2 = t.length();

	vector<vector<int>> dp(N1 + 1, vector<int>(N2 + 1, 0));

	for (int i = 0; i <= N1; i++)
		dp[i][0] = 1;

	for (int i = 1; i <= N1; i++) {
		for (int j = 1; j <= N2; j++) {
			if (s[i - 1] == t[j - 1])
				dp[i][j] = dp[i - 1][j - 1] + dp[i - 1][j];
			else
				dp[i][j] = dp[i - 1][j];
		}
	}
	return dp[N1][N2];
}

/* Solution 2: run-time O(MN), memeory O(N)*/

int numDistinct_Sln2(string s, string t) {
	int N1 = s.length(), N2 = t.length();

	vector<int> dp(N2 + 1, 0);
	dp[0] = 1;

	for (int i = 1; i <= N1; i++) {
		for (int j = N2; j > 0; j--) {
			if (s[i - 1] == t[j - 1])
				dp[j] = dp[j] + dp[j - 1];
		}
	}
	return dp[N2];
}

int main()
{
	string S = "rabbbit", T = "rabbit";
	int ans = 3;
	int ret1 = numDistinct_Sln1(S, T);
	assert(ret1 == ans);
	int ret2 = numDistinct_Sln2(S, T);
	assert(ret2 == ans);
	return 0;
}
