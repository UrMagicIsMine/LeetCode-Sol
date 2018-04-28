/* Write an efficient algorithm that searches for a value in an m x n matrix.
This matrix has the following properties:

Integers in each row are sorted from left to right.
The first integer of each row is greater than the last integer of the previous
row.
Example 1:

Input:
matrix = [
  [1,   3,  5,  7],
  [10, 11, 16, 20],
  [23, 30, 34, 50]
]
target = 3
Output: true
Example 2:

Input:
matrix = [
  [1,   3,  5,  7],
  [10, 11, 16, 20],
  [23, 30, 34, 50]
]
target = 13
Output: false
*/
#include <vector>
#include <cassert>
using namespace std;

bool searchMatrix(vector<vector<int>>& matrix, int target) {
	int M = matrix.size();
	if (M == 0)
		return false;
	int N = matrix[0].size();
	if (N == 0)
		return false;

	int low = 1, high = M * N, mid;
	while (low <= high) {
		mid = (low + high) / 2;
		int m_mid = matrix[(mid - 1) / N][(mid - 1) % N];
		if (m_mid == target)
			return true;
		else if (m_mid < target)
			low = mid + 1;
		else
			high = mid - 1;
	}
	return false;
}

int main()
{
	vector<vector<int>> matrix = { {1, 3, 5, 7}, {10, 11, 16, 20}, {23, 30, 34, 50} };
	int target = 3;
	bool ans = true;
	bool ret = searchMatrix(matrix, target);
	assert(ret == ans);
	return 0;
}
