/* Given two strings s1, s2, find the lowest ASCII sum of deleted characters to
* make two strings equal.
*
* Example 1:
* Input: s1 = "sea", s2 = "eat"
* Output: 231
* Explanation: Deleting "s" from "sea" adds the ASCII value of "s" (115) to the sum.
*              Deleting "t" from "eat" adds 116 to the sum.
*              At the end, both strings are equal, and 115 + 116 = 231 is the
*              minimum sum possible to achieve this.
* Example 2:
* Input: s1 = "delete", s2 = "leet"
* Output: 403
* Explanation: Deleting "dee" from "delete" to turn the string into "let",
*              adds 100[d]+101[e]+101[e] to the sum.  Deleting "e" from "leet"
*              adds 101[e] to the sum. At the end, both strings are equal to
*              "let", and the answer is 100+101+101+101 = 403.
*              If instead we turned both strings into "lee" or "eet", we would
*              get answers of 433 or 417, which are higher.
* Note:
*     0 < s1.length, s2.length <= 1000.
*     All elements of each string will have an ASCII value in [97, 122].
*/

#include <vector>
#include <algorithm>
#include <cassert>
using namespace std;

/* DP solution, O(n^2) */
/* dp[i][j] is the cost for s1.substr(0, i) and s2.substr(0, j).
* Note s1[i], s2[j] not included in the substring.
*
* Base case: dp[0][0] = 0, target : dp[m][n]
*
* 	if s1[i - 1] = s2[j - 1]   // no deletion
* 		dp[i][j] = dp[i - 1][j - 1];
* 	else   // delete either s1[i-1] or s2[j-1]
* 		dp[i][j] = min(dp[i - 1][j] + s1[i - 1], dp[i][j - 1] + s2[j - 1]);
*/

int minimumDeleteSum(string s1, string s2) {

	int N1 = s1.size();
	int N2 = s2.size();

	vector<vector<int>> delSumMtx(N1 + 1, vector<int>(N2 + 1, 0));

	for (int i = 1; i <= N1; i++)
		delSumMtx[i][0] = delSumMtx[i - 1][0] + s1[i - 1];
	for (int j = 1; j <= N2; j++)
		delSumMtx[0][j] = delSumMtx[0][j - 1] + s2[j - 1];

	for (int i = 1; i <= N1; i++) {
		for (int j = 1; j <= N2; j++) {
			if (s1[i - 1] == s2[j - 1])
				delSumMtx[i][j] = delSumMtx[i - 1][j - 1];
			else
				delSumMtx[i][j] = min((delSumMtx[i][j - 1] + s2[j - 1]), (delSumMtx[i - 1][j] + s1[i - 1]));
		}
	}
	return delSumMtx[N1][N2];

}

int main()
{
	string s1 = "sea", s2 = "eat";
	int ans = 231;
	auto ret1 = minimumDeleteSum(s1, s2);
	assert(ret1 == ans);

	return 0;
}
