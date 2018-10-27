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

bool _isValid(int row, int col, int n, vector<string>& Queens) {

	int sum = row + col, diff = row - col;

	for (int i = 0; i < n; i++) {
		if (Queens[i][col] == 'Q' || Queens[row][i] == 'Q')
			return false;

		int j = sum - i;
		if (j >= 0 && j < n && Queens[i][j] == 'Q')
			return false;

		j = i - diff;
		if (j >= 0 && j < n && Queens[i][j] == 'Q')
			return false;
	}
	return true;
}

bool _solveBT(vector<vector<string>>& resl, int N, vector<string>& puzzle, int row) {
	if (row == N) {
		resl.push_back(puzzle);
		return true;
	}
	else {

		for (int col = 0; col < N; col++) {
			if (_isValid(row, col, N, puzzle)) {
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
