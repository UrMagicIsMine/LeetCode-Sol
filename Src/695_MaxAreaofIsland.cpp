/* Given a non-empty 2D array grid of 0's and 1's, an island is a group of 1's
* (representing land) connected 4-directionally (horizontal or vertical.) You
* may assume all four edges of the grid are surrounded by water.
*
* Find the maximum area of an island in the given 2D array. (If there is no
* island, the maximum area is 0.)
*
* Example 1:
* [[0,0,1,0,0,0,0,1,0,0,0,0,0],
*  [0,0,0,0,0,0,0,1,1,1,0,0,0],
*  [0,1,1,0,1,0,0,0,0,0,0,0,0],
*  [0,1,0,0,1,1,0,0,1,0,1,0,0],
*  [0,1,0,0,1,1,0,0,1,1,1,0,0],
*  [0,0,0,0,0,0,0,0,0,0,1,0,0],
*  [0,0,0,0,0,0,0,1,1,1,0,0,0],
*  [0,0,0,0,0,0,0,1,1,0,0,0,0]]
* Given the above grid, return 6. Note the answer is not 11, because the island
* must be connected 4-directionally.
* Example 2:
* [[0,0,0,0,0,0,0,0]]
* Given the above grid, return 0.
* Note: The length of each dimension in the given grid does not exceed 50.
*/

#include <unordered_map>
#include <vector>
#include <cassert>
using namespace std;
void _DFS(vector<vector<int>>& grid, int M, int N, int& iCnt, int i, int j) {
	if (grid[i][j] == 0)
		return;
	iCnt++;
	grid[i][j] = 0;
	if (i > 0)
		_DFS(grid, M, N, iCnt, i - 1, j);
	if (j > 0)
		_DFS(grid, M, N, iCnt, i, j - 1);
	if (i < M - 1)
		_DFS(grid, M, N, iCnt, i + 1, j);
	if (j < N - 1)
		_DFS(grid, M, N, iCnt, i, j + 1);
	return;
}

int maxAreaOfIsland(vector<vector<int>>& grid) {
	int ret = 0;
	int M = grid.size();
	if (M == 0)
		return ret;
	int N = grid[0].size();
	if (N == 0)
		return ret;

	for (int i = 0; i<M; i++)
		for (int j = 0; j <N; j++) {
			if (grid[i][j] == 1) {
				int iCnt = 0;
				_DFS(grid, M, N, iCnt, i, j);
				if (iCnt > ret)
					ret = iCnt;
			}
		}
	return ret;
}

int main()
{
	vector<vector<int>> grid = { {0,1}, {1,1} };
	int ret = maxAreaOfIsland(grid);
	int ans = 3;
	assert(ret == ans);
	return 0;
}
