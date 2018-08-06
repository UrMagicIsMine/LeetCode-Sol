/* Given a 2D binary matrix filled with 0's and 1's, find the largest square
* containing only 1's and return its area.
*
* For example, given the following matrix:
*
* 1 0 1 0 0
* 1 0 1 1 1
* 1 1 1 1 1
* 1 0 0 1 0
* Return 4.
*/

#include <vector>
#include <algorithm>
#include <cassert>
using namespace std;

int maximalSquare(vector<vector<char>>& matrix) {

	int M = matrix.size();
	if (M == 0)
		return 0;
	int N = matrix[0].size();
	if (N == 0)
		return 0;

	using vec1D = vector<int>;
	using vec2D = vector<vec1D>;

	vec2D dp(M + 1, vec1D(N + 1, 0));
	int ret = 0;
	for (int i = 1; i <= M; i++) {
		for (int j = 1; j <= N; j++) {
			if (matrix[i - 1][j - 1] == '1') {
				dp[i][j] = min(dp[i - 1][j - 1], min(dp[i - 1][j], dp[i][j - 1])) + 1;
				ret = max(ret, dp[i][j]);
			}
		}
	}
	return ret * ret;
}

int main()
{
	vector<vector<char>> matrix = { { '1', '0', '1', '0', '0' },
																  { '1', '0', '1', '1', '1' },
																	{ '1', '1', '1' ,'1', '1' },
																	{ '1', '0', '0', '1', '0' } };
	int ans = 4;
	int ret = maximalSquare(matrix);
	assert(ret == ans);
	return 0;
}
