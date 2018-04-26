/* Given a matrix of m x n elements (m rows, n columns), return all elements of
the matrix in spiral order.

Example 1:

Input:
[
 [ 1, 2, 3 ],
 [ 4, 5, 6 ],
 [ 7, 8, 9 ]
]
Output: [1,2,3,6,9,8,7,4,5]
Example 2:

Input:
[
  [1, 2, 3, 4],
  [5, 6, 7, 8],
  [9,10,11,12]
]
Output: [1,2,3,4,8,12,11,10,9,5,6,7]
*/

#include <string>
#include <vector>
#include <cassert>
using namespace std;

/*When traversing the matrix in the spiral order, at any time we follow one out
of the following four directions: RIGHT DOWN LEFT UP.*/

vector<int> spiralOrder(vector<vector<int>>& matrix) {
	vector<int> resl;
	int M = matrix.size();
	if (M == 0)
		return resl;
	int N = matrix[0].size();
	if (N == 0)
		return resl;

	vector<vector<int>> dirs = { { 0,1 },{ 1,0 },{ 0,-1 },{ -1,0 } };
	vector<int> steps = { N, M - 1 };

	int iDir = 0, row = 0, col = -1;
	while (steps[iDir % 2]) {
		int s = 0;
		while (s < steps[iDir % 2]) {
			row += dirs[iDir][0];
			col += dirs[iDir][1];
			resl.push_back(matrix[row][col]);
			s++;
		}
		steps[iDir % 2]--;
		iDir = (iDir + 1) % 4;
	}
	return resl;
}

int main()
{
	vector<vector<int>> matrix = { {1, 2, 3}, {4, 5, 6}, {7, 8, 9} };
	vector<int> ans = { 1,2,3,6,9,8,7,4,5 };
	vector<int> ret = spiralOrder(matrix);
	assert(ret == ans);
	return 0;
}
