/* Given a m x n grid filled with non-negative numbers, find a path from top left
to bottom right which minimizes the sum of all numbers along its path.

Note: You can only move either down or right at any point in time.

Example:

Input:
[
  [1,3,1],
  [1,5,1],
  [4,2,1]
]
Output: 7
Explanation: Because the path 1->3->1->1->1 minimizes the sum.
*/

#include <string>
#include <vector>
#include <algorithm>
#include <functional>
#include <cassert>
using namespace std;

int minPathSum(vector<vector<int>>& grid) {
	int M = grid.size();
	if (M == 0)
		return 0;
	int N = grid[0].size();
	if (N == 0)
		return 0;

	vector<vector<int>> dp(M, vector<int>(N, 0));
	dp[M - 1][N - 1] = grid[M - 1][N - 1];
	for (int i = M - 2; i >= 0; i--)
		dp[i][N - 1] = grid[i][N - 1] + dp[i + 1][N - 1];
	for (int j = N - 2; j >= 0; j--)
		dp[M - 1][j] = grid[M - 1][j] + dp[M - 1][j + 1];


	for (int i = M - 2; i >= 0; i--)
		for (int j = N - 2; j >= 0; j--)
			dp[i][j] = grid[i][j] + min(dp[i + 1][j], dp[i][j + 1]);

	return dp[0][0];
}

int main()
{
	vector<vector<int>> Grid = { { 1,3,1 },{ 1,5,1 },{ 4,2,1 } };
	int ans = 7;
	int ret = minPathSum(Grid);
	assert(ret == ans);
}
