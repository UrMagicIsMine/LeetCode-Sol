/*
* Given a 2D matrix matrix, find the sum of the elements inside the rectangle
* defined by its upper left corner (row1, col1) and lower right corner (row2, col2).
*
* Range Sum Query 2D
* The above rectangle (with the red border) is defined by (row1, col1) = (2, 1)
* and (row2, col2) = (4, 3), which contains sum = 8.
*
* Example:
* Given matrix = [
*   [3, 0, 1, 4, 2],
*   [5, 6, 3, 2, 1],
*   [1, 2, 0, 1, 5],
*   [4, 1, 0, 1, 7],
*   [1, 0, 3, 0, 5]
* ]
*
* sumRegion(2, 1, 4, 3) -> 8
* sumRegion(1, 1, 2, 2) -> 11
* sumRegion(1, 2, 2, 4) -> 12
* Note:
* You may assume that the matrix does not change.
* There are many calls to sumRegion function.
* You may assume that row1 ≤ row2 and col1 ≤ col2.
*
*/

#include <vector>
#include <cassert>
using namespace std;

class NumMatrix {
public:
	NumMatrix(vector<vector<int>> matrix) {

		int m = matrix.size();
		if (m == 0) return;
		int n = matrix[0].size();

		_sumMtx.resize(m + 1, vector<int>(n + 1, 0));
		for (int i = 1; i <= m; i++) {
			for (int j = 1; j <= n; j++) {
				_sumMtx[i][j] = _sumMtx[i][j - 1] + _sumMtx[i - 1][j]
					+ matrix[i - 1][j - 1] - _sumMtx[i - 1][j - 1];
			}
		}

	}

	int sumRegion(int row1, int col1, int row2, int col2) {
		return _sumMtx[row1][col1] + _sumMtx[row2 + 1][col2 + 1]
			- _sumMtx[row1][col2 + 1] - _sumMtx[row2 + 1][col1];
	}

private:
	vector<vector<int>> _sumMtx;

};

int main()
{
	vector<vector<int>> nums = { {3, 0, 1, 4, 2},
								 {5, 6, 3, 2, 1},
								 {1, 2, 0, 1, 5},
								 {4, 1, 0, 1, 7},
								 {1, 0, 3, 0, 5} };
	NumMatrix nMatrix(nums);

	int ret1 = nMatrix.sumRegion(2, 1, 4, 3);
	assert(ret1 == 8);
	int ret2 = nMatrix.sumRegion(1, 1, 2, 2);
	assert(ret2 == 11);
	int ret3 = nMatrix.sumRegion(1, 2, 2, 4);
	assert(ret3 == 12);
	return 0;

}
