/* Given a 2D binary matrix filled with 0's and 1's, find the largest rectangle
* containing only 1's and return its area.
*
* Example:
*
* Input:
* [
*   ["1","0","1","0","0"],
*   ["1","0","1","1","1"],
*   ["1","1","1","1","1"],
*   ["1","0","0","1","0"]
* ]
* Output: 6
*/

#include <vector>
#include <algorithm>
#include <unordered_map>
#include <cassert>
using namespace std;

/*
The DP solution proceeds row by row, starting from the first row.
Let the maximal rectangle area at row i and column j be computed by [right(i,j) - left(i,j)]*height(i,j).
three vectors
1) height counts the number of successive '1’s above (plus the current one).
2) left[i] & right[i] means the boundaries of the rectangle

Run-time O(N^2), Space O(N)
*/

int maximalRectangle(vector<vector<char>>& matrix) {

	int M = matrix.size();
	if (M == 0)
		return 0;
	int N = matrix[0].size(), maxA = 0;
	vector<int> height(N, 0), left(N, 0), right(N, N);
	for (int i = 0; i < M; i++) {
		int curLeft = 0, curRght = N;
		for (int j = 0; j < N; j++) {
			if (matrix[i][j] == '1')
				height[j]++;
			else
				height[j] = 0;
		}

		for (int j = 0; j < N; j++) {
			if (matrix[i][j] == '1') {
				left[j] = max(left[j], curLeft);
			}
			else {
				left[j] = 0;
				curLeft = j + 1;
			}
		}

		for (int j = N - 1; j >= 0; j--) {
			if (matrix[i][j] == '1') {
				right[j] = min(right[j], curRght);
			}
			else {
				right[j] = N;
				curRght = j;
			}
		}

		for (int j = 0; j < N; j++) {
			maxA = max(maxA, (right[j] - left[j])*height[j]);
		}

	}
	return maxA;
}

// solution 2: connect to prob 84

int largestRectangleArea(vector<int>& heights) {
	stack<int> stIndex;
	int N = heights.size();
	heights.push_back(0);

	int maxArea = 0;
	for (int i = 0; i <= N; i++) {
		if (stIndex.empty() || heights[i] >= heights[stIndex.top()]) {
			stIndex.push(i);
		}
		else {
			int curIdx = stIndex.top();
			stIndex.pop();
			while (!stIndex.empty() && heights[stIndex.top()] == heights[curIdx]) {
				stIndex.pop();
			}

			int right = i;
			int left = stIndex.empty() ? -1 : stIndex.top();
			maxArea = max(maxArea, heights[curIdx] * (right - left - 1));
			i--;
		}
	}
	heights.pop_back();
	return maxArea;
}

int maximalRectangle(vector<vector<char>>& matrix) {

	int m = matrix.size();
	if (m == 0) return 0;
	int n = matrix[0].size();
	if (n == 0) return 0;
	int maxA = 0;
	vector<int> heights(n, 0);
	for (int i = 0; i < m; i++) {
		for (int j = 0; j < n; j++) {
			if (matrix[i][j] == '0') {
				heights[j] = 0;
			}
			else {
				heights[j]++;
			}
		}

		maxA = max(maxA, largestRectangleArea(heights));
	}
	return maxA;
}


int main()
{
	vector<vector<char>> matrix = { { '1','0','1','0','0' },
								    							{ '1','0','1','1','1' },
								    							{ '1','1','1','1','1' },
								    							{ '1','0','0','1','0' } };
	int ans = 6;
	int ret = maximalRectangle(matrix);
	assert(ret == ans);
	return 0;
}
