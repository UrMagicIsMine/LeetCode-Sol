/* Given two words word1 and word2, find the minimum number of operations required
to convert word1 to word2.

You have the following 3 operations permitted on a word:

Insert a character
Delete a character
Replace a character
Example 1:

Input: word1 = "horse", word2 = "ros"
Output: 3
Explanation:
horse -> rorse (replace 'h' with 'r')
rorse -> rose (remove 'r')
rose -> ros (remove 'e')
Example 2:

Input: word1 = "intention", word2 = "execution"
Output: 5
Explanation:
intention -> inention (remove 't')
inention -> enention (replace 'i' with 'e')
enention -> exention (replace 'n' with 'x')
exention -> exection (replace 'n' with 'c')
exection -> execution (insert 'u')
*/
#include <vector>
#include <string>
#include <algorithm>
#include <cassert>
using namespace std;

/*
This is a classic problem of Dynamic Programming. We define the state dp[i][j] to
be the minimum number of operations to convert word1[0..i - 1] to word2[0..j - 1].
The state equations have two cases: the boundary case and the general case. Note
that in the above notations, both i and j take values starting from 1.

For the boundary case, that is, to convert a string to an empty string, it is easy
to see that the mininum number of operations to convert word1[0..i - 1] to ""
requires at least i operations (deletions). In fact, the boundary case is simply:

dp[i][0] = i;
dp[0][j] = j.
Now let's move on to the general case, that is, convert a non-empty word1[0..i - 1]
to another non-empty word2[0..j - 1]. Well, let's try to break this problem down
into smaller problems (sub-problems). Suppose we have already known how to convert
word1[0..i - 2] to word2[0..j - 2], which is dp[i - 1][j - 1]. Now let's consider
word[i - 1] and word2[j - 1]. If they are euqal, then no more operation is needed
and dp[i][j] = dp[i - 1][j - 1]. Well, what if they are not equal?

If they are not equal, we need to consider three cases:

Replace word1[i - 1] by word2[j - 1] (dp[i][j] = dp[i - 1][j - 1] + 1 (for replacement));
Delete word1[i - 1] and word1[0..i - 2] = word2[0..j - 1] (dp[i][j] = dp[i - 1][j] + 1 (for deletion));
Insert word2[j - 1] to word1[0..i - 1] and word1[0..i - 1] + word2[j - 1] = word2[0..j - 1]
       (dp[i][j] = dp[i][j - 1] + 1 (for insertion)).
Make sure you understand the subtle differences between the equations for deletion and insertion.
For deletion, we are actually converting word1[0..i - 2] to word2[0..j - 1],
which costs dp[i - 1][j], and then deleting the word1[i - 1], which costs 1.
The case is similar for insertion.

Putting these together, we now have:

dp[i][0] = i;
dp[0][j] = j;
dp[i][j] = dp[i - 1][j - 1], if word1[i - 1] = word2[j - 1];
dp[i][j] = min(dp[i - 1][j - 1] + 1, dp[i - 1][j] + 1, dp[i][j - 1] + 1), otherwise.
The above state equations can be turned into the following code directly.
*/

int minDistance(string word1, string word2) {

	int M = word1.size(), N = word2.size();
	vector<vector<int>> dp(M + 1, vector<int>(N + 1, 0));
	for (int i = 0; i <= M; i++)
		dp[i][0] = i;
	for (int j = 0; j <= N; j++)
		dp[0][j] = j;

	for (int i = 1; i <= M; i++) {
		for (int j = 1; j <= N; j++) {
			if (word1[i - 1] == word2[j - 1])
				dp[i][j] = dp[i - 1][j - 1];
			else
				dp[i][j] = min(dp[i - 1][j - 1], min(dp[i - 1][j], dp[i][j - 1])) + 1;
		}
	}
	return dp[M][N];
}

int main()
{
	string word1 = "horse", word2 = "ros";
	int ans = 3;
	int ret = minDistance(word1, word2);
	assert(ret == ans);
	return 0;
}
