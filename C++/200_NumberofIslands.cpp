/* Given a 2d grid map of '1's (land) and '0's (water), count the number of islands.
* An island is surrounded by water and is formed by connecting adjacent lands
* horizontally or vertically. You may assume all four edges of the grid are all
* surrounded by water.
*
* Example 1:
*
* 11110
* 11010
* 11000
* 00000
* Answer: 1
*
* Example 2:
*
* 11000
* 11000
* 00100
* 00011
* Answer: 3
*/

#include <vector>
#include <queue>
#include <cassert>
using namespace std;

/******************************************************************************/
/* Solution 1: Breadth-first search */

void _fillIsland_BFS(vector<vector<char>>& grid, const pair<int, int>& dim,
	const pair<int, int> &loc, queue<pair<int, int>>& qIsland) {

	if (loc.first >= 0 && loc.first < dim.first
		&& loc.second >= 0 && loc.second < dim.second
		&& grid[loc.first][loc.second] == '1') {
		grid[loc.first][loc.second] = '0';
		qIsland.push(loc);
	}
	return;

}

int numIslands_BFS(vector<vector<char>>& grid) {
	int ret = 0;

	int M = grid.size();
	if (M == 0)
		return ret;
	int N = grid[0].size();
	if (N == 0)
		return ret;

	pair<int, int> dim = { M,N };
	for (int i = 0; i < dim.first; i++) {
		for (int j = 0; j < dim.second; j++) {
			if (grid[i][j] == '1') {
				ret++;
				queue<pair<int, int>> qisland;
				grid[i][j] = '0';
				qisland.push(make_pair(i, j));
				while (!qisland.empty()) {
					pair<int, int> loc = qisland.front();
					qisland.pop();
					_fillIsland_BFS(grid, dim, make_pair(loc.first - 1, loc.second), qisland);
					_fillIsland_BFS(grid, dim, make_pair(loc.first + 1, loc.second), qisland);
					_fillIsland_BFS(grid, dim, make_pair(loc.first, loc.second - 1), qisland);
					_fillIsland_BFS(grid, dim, make_pair(loc.first, loc.second + 1), qisland);
				}
			}
		}
	}
	return ret;
}

/******************************************************************************/
/* Solution 1: Depth-first search */

void _fillIsland_DFS(vector<vector<char>>& grid, const pair<int, int>& dim, const pair<int, int> &loc) {

	if (loc.first >= 0 && loc.first < dim.first
		&& loc.second >= 0 && loc.second < dim.second
		&& grid[loc.first][loc.second] == '1') {
		grid[loc.first][loc.second] = '0';

		_fillIsland_DFS(grid, dim, make_pair(loc.first - 1, loc.second));
		_fillIsland_DFS(grid, dim, make_pair(loc.first + 1, loc.second));
		_fillIsland_DFS(grid, dim, make_pair(loc.first, loc.second - 1));
		_fillIsland_DFS(grid, dim, make_pair(loc.first, loc.second + 1));

	}
	return;

}

int numIslands_DFS(vector<vector<char>>& grid) {
	int ret = 0;

	int M = grid.size();
	if (M == 0)
		return ret;
	int N = grid[0].size();
	if (N == 0)
		return ret;

	pair<int, int> dim = { M,N };
	for (int i = 0; i < dim.first; i++) {
		for (int j = 0; j < dim.second; j++) {
			if (grid[i][j] == '1') {
				ret++;
				_fillIsland_DFS(grid, dim, make_pair(i, j));
			}
		}
	}
	return ret;
}

int main()
{

	vector<vector<char>> grid = { {'1','1','0','0','0'},
								  {'1','1','0','0','0'},
								  {'0','0','1','0','0'},
								  {'0','0','0','1','1'} };

	int ans = 3;
	vector<vector<char>> grid1(grid);
	int ret1 = numIslands_DFS(grid1);
	assert(ret1 == ans);
	vector<vector<char>> grid2(grid);
	int ret2 = numIslands_BFS(grid2);
	assert(ret2 == ans);
	return 0;
}
