/* A robot is located at the top-left corner of a m x n grid (marked 'Start' in
the diagram below).

The robot can only move either down or right at any point in time. The robot is
trying to reach the bottom-right corner of the grid (marked 'Finish' in the
diagram below).

Now consider if some obstacles are added to the grids. How many unique paths
would there be?

An obstacle and empty space is marked as 1 and 0 respectively in the grid.

Note: m and n will be at most 100.

Example 1:

Input:
[
  [0,0,0],
  [0,1,0],
  [0,0,0]
]
Output: 2
Explanation:
There is one obstacle in the middle of the 3x3 grid above.
There are two ways to reach the bottom-right corner:
1. Right -> Right -> Down -> Down
2. Down -> Down -> Right -> Right
*/

#include <string>
#include <vector>
#include <algorithm>
#include <functional>
#include <cassert>
using namespace std;

int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
	int M = obstacleGrid.size();
	if (M == 0)
		return 0;
	int N = obstacleGrid[0].size();
	if (N == 0)
		return 0;
	if (obstacleGrid[M - 1][N - 1] == 1)
		return 0;

	vector<vector<int>> dp(M, vector<int>(N, 0));
	dp[M - 1][N - 1] = 1;

	for (int i = M - 2; i >= 0; i--)
		if (obstacleGrid[i][N - 1] == 0)
			dp[i][N - 1] = dp[i + 1][N - 1];

	for (int j = N - 2; j >= 0; j--)
		if (obstacleGrid[M - 1][j] == 0)
			dp[M - 1][j] = dp[M - 1][j + 1];

	for (int i = M - 2; i >= 0; i--) {
		for (int j = N - 2; j >= 0; j--) {
			if (obstacleGrid[i][j] == 0)
				dp[i][j] = dp[i + 1][j] + dp[i][j + 1];
		}
	}
	return dp[0][0];
}

int main()
{
	vector<vector<int>> obstacleGrid = { {0,0,0},{0,1,0},{0,0,0} };
	int ans = 2;
	int ret = uniquePathsWithObstacles(obstacleGrid);
	assert(ret == ans);
}
