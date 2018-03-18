/* Follow up for N-Queens problem.
*
* Now, instead outputting board configurations, return the total number of
* distinct solutions.
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

bool _solveBT(int& resl, int N, vector<string>& puzzle, int row) {
	if (row == N) {
		resl++;
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

int totalNQueens(int n) {
	int cnt = 0;
	vector<string> puzzle(n, string(n, '.'));
	_solveBT(cnt, n, puzzle, 0);
	return cnt;
}

int main()
{
	int ret = totalNQueens(4);
	int ans = 2;
	assert(ret == ans);
	return 0;
}
