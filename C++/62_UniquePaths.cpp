/* A robot is located at the top-left corner of a m x n grid (marked 'Start' in
* the diagram below).
*
* The robot can only move either down or right at any point in time. The robot
* is trying to reach the bottom-right corner of the grid (marked 'Finish' in the
* diagram below).
*
* How many possible unique paths are there?
*/

#include <vector>
#include <string>
#include <unordered_map>
#include <algorithm>
#include <cassert>
using namespace std;

int uniquePaths(int m, int n) {

	vector<vector<int>> dp(m, vector<int>(n, 1));

	for (int i = m - 2; i >= 0; i--) {
		for (int j = n - 2; j >= 0; j--) {
			dp[i][j] = dp[i + 1][j] + dp[i][j + 1];
		}
	}
	return dp[0][0];
}

int main()
{
	int m = 7, n = 3;
	int ans = 28;
	int ret = uniquePaths(m, n);
	assert(ret == ans);
	return 0;
}
