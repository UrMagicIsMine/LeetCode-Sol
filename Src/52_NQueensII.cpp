/* Follow up for N-Queens problem.
*
* Now, instead outputting board configurations, return the total number of
* distinct solutions.
*/

#include <string>
#include <vector>
#include <cassert>
using namespace std;

bool _isValid(int row, int col, int n, vector<string>& Queens){

		int sum = row + col, diff = row - col;
		for(int i = 0; i < n; i++){
				if(Queens[row][i] == 'Q' || Queens[i][col] == 'Q')
						return false;

				int j = sum - i;
				if( j >= 0 && j < n && Queens[i][j] == 'Q')
						return false;

				j = i - diff;
				if( j >= 0 && j < n && Queens[i][j] == 'Q')
						return false;
		}
		return true;
}

bool _solveBT(int& resl, int N, vector<string>& puzzle, int row) {
	if (row == N) {
		resl++;
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
