/* Write an efficient algorithm that searches for a value in an m x n matrix.
* This matrix has the following properties:
*
* Integers in each row are sorted in ascending from left to right.
* Integers in each column are sorted in ascending from top to bottom.
* For example,
*
* Consider the following matrix:
*
* [
*   [1,   4,  7, 11, 15],
*   [2,   5,  8, 12, 19],
*   [3,   6,  9, 16, 22],
*   [10, 13, 14, 17, 24],
*   [18, 21, 23, 26, 30]
* ]
* Given target = 5, return true.
*
* Given target = 20, return false.
*/

#include <vector>
#include <unordered_map>
#include <cassert>
using namespace std;

/*
Time complexity : O(nlogn).
Space complexity : O(1).
*/

bool searchMatrix_Sln1(vector<vector<int>>& matrix, int target) {

	int M = matrix.size();
	if (M < 1)
		return false;
	int N = matrix[0].size();
	if (N < 1)
		return false;

	int i = 0;
	while (i < M) {

		int low = 0;
		int high = N - 1;
		int mid;
		while (low <= high) {
			mid = (low + high) / 2;
			if (matrix[i][mid] == target)
				return true;
			else if (matrix[i][mid] < target)
				low = mid + 1;
			else
				high = mid - 1;
		}
		i++;
	}
	return false;
}

/*
Time complexity : O(n+m).
Space complexity : O(1).
*/

bool searchMatrix_Sln2(vector<vector<int>>& matrix, int target) {

	int M = matrix.size();
	if (M < 1)
		return false;
	int N = matrix[0].size();
	if (N < 1)
		return false;

	int i = 0, j = N - 1;

	while (i < M && j >= 0) {

		if (matrix[i][j] == target)
			return true;
		else if (matrix[i][j] < target)
			i++;
		else
			j--;
	}
	return false;
}


int main()
{
	vector<vector<int>> nums = { {1, 4, 7, 11, 15},
								 {2, 5, 8, 12, 19},
								 {3, 6, 9, 16, 22},
								 {10, 13, 14, 17, 24},
								 {18, 21, 23, 26, 30} };
	int target = 5;
	bool ans = true;
	int ret1 = searchMatrix_Sln1(nums, target);
	assert(ret1 == ans);

	int ret2 = searchMatrix_Sln2(nums, target);
	assert(ret2 == ans);

	return 0;
}
