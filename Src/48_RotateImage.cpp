/* You are given an n x n 2D matrix representing an image.

Rotate the image by 90 degrees (clockwise).

Note:

You have to rotate the image in-place, which means you have to modify the input
2D matrix directly. DO NOT allocate another 2D matrix and do the rotation.

Example 1:

Given input matrix =
[
  [1,2,3],
  [4,5,6],
  [7,8,9]
],

rotate the input matrix in-place such that it becomes:
[
  [7,4,1],
  [8,5,2],
  [9,6,3]
]
*/

#include <vector>
#include <string>
#include <algorithm>
#include <cassert>
using namespace std;
void rotate(vector<vector<int>>& matrix) {

	int N = matrix.size();
	if (N & 1) {
		//odd
		int offset = N / 2;
		for (int x = 1; x <= N / 2; x++) {
			for (int y = 0; y <= N / 2; y++) {
				int tmp = matrix[offset + y][offset + x];
				matrix[offset + y][offset + x] = matrix[offset - x][offset + y];
				matrix[offset - x][offset + y] = matrix[offset - y][offset - x];
				matrix[offset - y][offset - x] = matrix[offset + x][offset - y];
				matrix[offset + x][offset - y] = tmp;
			}
		}

	}
	else {
		//even
		int offset = N / 2;
		for (int x = 1; x <= N / 2; x++) {
			for (int y = 1; y <= N / 2; y++) {
				int tmp = matrix[offset - 1 + y][offset - 1 + x];
				matrix[offset - 1 + y][offset - 1 + x] = matrix[offset - x][offset - 1 + y];
				matrix[offset - x][offset - 1 + y] = matrix[offset - y][offset - x];
				matrix[offset - y][offset - x] = matrix[offset - 1 + x][offset - y];
				matrix[offset - 1 + x][offset - y] = tmp;
			}
		}
	}
	return;
}

int main()
{
	vector<vector<int>> nums_old = { {1, 2, 3},{4, 5, 6},{7, 8, 9} };
	vector<vector<int>> ans1_old = { {7, 4, 1},{8, 5, 2},{9, 6, 3} };
	rotate(nums_old);
	assert(nums_old == ans1_old);

	vector<vector<int>> nums_even = { {1, 2, 3, 4},{5, 6, 7, 8},{9, 10, 11, 12},{13, 14, 15, 16} };
	vector<vector<int>> ans1_even = { {13, 9, 5, 1},{14, 10, 6, 2},{15, 11, 7, 3},{16, 12, 8, 4} };
	rotate(nums_even);
	assert(nums_even == ans1_even);
	return 0;
}
