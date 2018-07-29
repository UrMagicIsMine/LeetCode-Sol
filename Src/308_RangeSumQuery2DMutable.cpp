/*
Given a 2D matrix matrix, find the sum of the elements inside the rectangle
defined by its upper left corner (row1, col1) and lower right corner (row2, col2).

The above rectangle (with the red border) is defined by (row1, col1) = (2, 1) and
(row2, col2) = (4, 3), which contains sum = 8.

Example:
Given matrix = [
  [3, 0, 1, 4, 2],
  [5, 6, 3, 2, 1],
  [1, 2, 0, 1, 5],
  [4, 1, 0, 1, 7],
  [1, 0, 3, 0, 5]
]

sumRegion(2, 1, 4, 3) -> 8
update(3, 2, 2)
sumRegion(2, 1, 4, 3) -> 10
Note:
The matrix is only modifiable by the update function.
You may assume the number of calls to update and sumRegion function is distributed
evenly.
You may assume that row1 ≤ row2 and col1 ≤ col2.

*/

#include <vector>

using namespace std;

class FenWickTree2D {

public:
	FenWickTree2D() {
	}

	void init(int m, int n) {
		_matrix.reserve(m + 1);
		for (int i = 0; i < m + 1; i++) {
			_matrix.push_back(vector<int>(n + 1, 0));
		}
		_m = m + 1;
		_n = n + 1;
	}

	void update(int x, int y, int delta) {
		while (x < _m) {
			int tmp_y = y;
			while (tmp_y < _n) {
				_matrix[x][tmp_y] += delta;
				tmp_y += lowbit(tmp_y);
			}
			x += lowbit(x);
		}
		return;
	}

	int query(int x, int y) {
		int sum = 0;
		while (x > 0) {
			int tmp_y = y;
			while (tmp_y > 0) {
				sum += _matrix[x][tmp_y];
				tmp_y -= lowbit(tmp_y);
			}
			x -= lowbit(x);
		}
		return sum;
	}

private:

	static int lowbit(int x) {
		return x & (-x);
	}

	vector<vector<int>> _matrix;
	int _m;
	int _n;
};


class NumMatrix {
public:
	NumMatrix(vector<vector<int>> matrix) : _matrix(move(matrix)) {
		int m = _matrix.size();
		int n = (m == 0) ? 0 : _matrix[0].size();
		_tree2D.init(m, n);
		for (int i = 1; i <= _matrix.size(); i++) {
			for (int j = 1; j <= _matrix[0].size(); j++) {
				_tree2D.update(i, j, _matrix[i - 1][j - 1]);
			}
		}
	}

	void update(int row, int col, int val) {
		_tree2D.update(row + 1, col + 1, val - _matrix[row][col]);
		_matrix[row][col] = val;
	}

	int sumRegion(int row1, int col1, int row2, int col2) {
		return _tree2D.query(row2 + 1, col2 + 1) + _tree2D.query(row1, col1)
			- _tree2D.query(row2 + 1, col1) - _tree2D.query(row1, col2 + 1);
	}

private:
	FenWickTree2D _tree2D;
	vector<vector<int>> _matrix;
};
int main() {

	vector<vector<int>> num = { {3,0,1,4,2},{5,6,3,2,1},{1,2,0,1,5},{4,1,0,1,7},{1,0,3,0,5} };
	NumMatrix numMtrx(num);

	int ret1 = numMtrx.sumRegion(2, 1, 4, 3);
	numMtrx.update(3, 2, 2);
	int ret2 = numMtrx.sumRegion(2, 1, 4, 3);

	return 0;
}
