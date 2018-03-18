/* The n-queens puzzle is the problem of placing n queens on an n×n chessboard
* such that no two queens attack each other.
*
* Given an integer n, return all distinct solutions to the n-queens puzzle.
* Each solution contains a distinct board configuration of the n-queens' placement,
* where 'Q' and '.' both indicate a queen and an empty space respectively.
*
* For example,
* There exist two distinct solutions to the 4-queens puzzle:
*
* [
*  [".Q..",  // Solution 1
*   "...Q",
*   "Q...",
*   "..Q."],
*
*  ["..Q.",  // Solution 2
*   "Q...",
*   "...Q",
*   ".Q.."]
* ]
*/

#include <string>
#include <vector>
#include <cassert>
using namespace std;

bool _checkSafe(int i, int j, int n, vector<string>& puzzle) {

	/* check row */
	for (int row = 0; row < n; row++)
		if (puzzle[row][j] == 'Q')
			return false;
	/* check col */
	for (int col = 0; col < n; col++)
		if (puzzle[i][col] == 'Q')
			return false;

	for (int row = 0; row<n; row++)
		for (int col = 0; col<n; col++)
			if (((i - j == row - col) || (i + j == row + col)) && puzzle[row][col] == 'Q')
				return false;

	return true;
}

bool _solveBT(vector<vector<string>>& resl, int N, vector<string>& puzzle, int row) {
	if (row == N) {
		resl.push_back(puzzle);
		return true;
	}
	else {

		for (int col = 0; col < N; col++) {
			if (_checkSafe(row, col, N, puzzle)) {
				puzzle[row][col] = 'Q';
				_solveBT(resl, N, puzzle, row + 1);
				puzzle[row][col] = '.';
			}
		}
		return false;
	}
}

vector<vector<string>> solveNQueens(int n) {
	vector<vector<string>> resl;
	vector<string> puzzle(n, string(n, '.'));
	_solveBT(resl, n, puzzle, 0);
	return resl;
}

int main()
{
	vector<vector<string>> ret = solveNQueens(4);
	vector<vector<string>> ans = { {".Q..","...Q","Q...","..Q."},{"..Q.","Q...","...Q",".Q.."} };
	assert(ret == ans);
	return 0;
}
