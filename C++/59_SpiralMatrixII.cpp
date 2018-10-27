/* Given a positive integer n, generate a square matrix filled with elements from
1 to n^2 in spiral order.

Example:

Input: 3
Output:
[
 [ 1, 2, 3 ],
 [ 8, 9, 4 ],
 [ 7, 6, 5 ]
]
*/

#include <string>
#include <vector>
#include <cassert>
using namespace std;

/*When traversing the matrix in the spiral order, at any time we follow one out
of the following four directions: RIGHT DOWN LEFT UP.*/

vector<vector<int>> generateMatrix(int n) {
	vector<vector<int>> resl(n, vector<int>(n, 0));
	vector<vector<int>> dirs = { { 0,1 },{ 1,0 },{ 0,-1 },{ -1,0 } };

	int row = 0, col = -1, idir = 0, num = 1;
	vector<int> steps = { n, n - 1 };
	while (steps[idir % 2]) {
		int s = 0;
		while (s < steps[idir % 2]) {
			row += dirs[idir][0];
			col += dirs[idir][1];
			resl[row][col] = num++;
			s++;
		}
		steps[idir % 2]--;
		idir = (idir + 1) % 4;
	}
	return resl;
}

int main()
{
	int n = 3;
	vector<vector<int>> ans = { {1, 2, 3}, {8, 9, 4}, {7, 6, 5} };
	vector<vector<int>> ret = generateMatrix(n);
	assert(ret == ans);
	return 0;
}
