/* Given an m x n matrix of non-negative integers representing the height of each
* unit cell in a continent, the "Pacific ocean" touches the left and top edges of
* the matrix and the "Atlantic ocean" touches the right and bottom edges.
*
* Water can only flow in four directions (up, down, left, or right) from a cell
* to another one with height equal or lower.
*
* Find the list of grid coordinates where water can flow to both the Pacific and
* Atlantic ocean.
*
* Note:
* The order of returned grid coordinates does not matter.
* Both m and n are less than 150.
* Example:
*
* Given the following 5x5 matrix:
*
*   Pacific ~   ~   ~   ~   ~
*        ~  1   2   2   3  (5) *
*        ~  3   2   3  (4) (4) *
*        ~  2   4  (5)  3   1  *
*        ~ (6) (7)  1   4   5  *
*        ~ (5)  1   1   2   4  *
*           *   *   *   *   * Atlantic
*
* Return:
*
* [[0, 4], [1, 3], [1, 4], [2, 2], [3, 0], [3, 1], [4, 0]] (positions with
* parentheses in above matrix).
*/

#include <vector>
#include <algorithm>
#include <numeric>
#include <functional>
#include <cassert>
using namespace std;

vector<pair<int, int>> pacificAtlantic(vector<vector<int>>& matrix) {
	vector<pair<int, int>> resl;
	int M = matrix.size();
	if (M == 0)
		return resl;
	int N = matrix[0].size();
	if (N == 0)
		return resl;

	pair<int, int> dim(M, N);
	vector<vector<int>> visited(M, vector<int>(N, 0));
	for (int i = 0; i < M; i++) {
		_DFS(resl, matrix, dim, visited, INT_MIN, 1, i, 0);
		_DFS(resl, matrix, dim, visited, INT_MIN, 2, i, N - 1);
	}
	for (int j = 0; j < N; j++) {
		_DFS(resl, matrix, dim, visited, INT_MIN, 1, 0, j);
		_DFS(resl, matrix, dim, visited, INT_MIN, 2, M - 1, j);
	}
	return resl;
}

void _DFS(vector<pair<int, int>>& resl, const vector<vector<int>>& matrix,
          const pair<int, int>& dim, vector<vector<int>>& visited,
          int preVal, int preST, int x, int y) {

	if (x < 0 || x == dim.first || y < 0 || y == dim.second
    || preVal > matrix[x][y] || visited[x][y] == 3 || visited[x][y] == preST)
		return;

	visited[x][y] |= preST;

	if (visited[x][y] == 3)
		resl.push_back(make_pair(x, y));

	_DFS(resl, matrix, dim, visited, matrix[x][y], visited[x][y], x + 1, y);
	_DFS(resl, matrix, dim, visited, matrix[x][y], visited[x][y], x, y + 1);
	_DFS(resl, matrix, dim, visited, matrix[x][y], visited[x][y], x - 1, y);
	_DFS(resl, matrix, dim, visited, matrix[x][y], visited[x][y], x, y - 1);

	return;
}

int main()
{
	vector<vector<int>> matrix = { {1,2,2,3,5},{3,2,3,4,4},{2,4,5,3,1},{6,7,1,4,5},{5,1,1,2,4 }};
	vector<pair<int, int>> ret = pacificAtlantic(matrix);
	vector<pair<int, int>> ans = { {0, 4},{1, 4},{1, 3},{2, 2},{4, 0},{3, 0},{3, 1} };
	assert(ret == ans);
	return 0;
}
