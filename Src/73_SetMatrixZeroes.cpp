/* Given a m x n matrix, if an element is 0, set its entire row and column to 0.
Do it in-place.

Example 1:

Input:
[
  [1,1,1],
  [1,0,1],
  [1,1,1]
]
Output:
[
  [1,0,1],
  [0,0,0],
  [1,0,1]
]
*/
#include <vector>
#include <cassert>
using namespace std;

void setZeroes(vector<vector<int>>& matrix) {
	int M = matrix.size();
	if (M == 0)
		return;
	int N = matrix[0].size();
	if (N == 0)
		return;
	bool firstCol = false, firstRow = false;
	for (int i = 0; i < M; i++)
		if (matrix[i][0] == 0)
			firstCol = true;
	for (int j = 0; j < N; j++)
		if (matrix[0][j] == 0)
			firstRow = true;

	for (int i = 1; i < M; i++) {
		for (int j = 1; j < N; j++) {
			if (matrix[i][j] == 0) {
				matrix[i][0] = 0;
				matrix[0][j] = 0;
			}
		}
	}

	for (int i = 1; i < M; i++) {
		for (int j = 1; j < N; j++) {
			if (matrix[i][0] == 0 || matrix[0][j] == 0) {
				matrix[i][j] = 0;
			}
		}
	}

	for (int i = 0; i < M; i++)
		if (firstCol)
			matrix[i][0] = 0;
	for (int j = 0; j < N; j++)
		if (firstRow)
			matrix[0][j] = 0;

	return;
}

int main()
{
	vector<vector<int>> matrix = { { 0,1,2,0 }, { 3,4,5,2 }, { 1,3,1,5 } };
	vector<vector<int>> ans = { { 0,0,0,0 },{ 0,4,5,0 },{ 0,3,1,0 } };
	setZeroes(matrix);
	assert(matrix == ans);
	return 0;
}
