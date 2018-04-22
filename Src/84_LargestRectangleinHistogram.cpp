/* Given n non-negative integers representing the histogram's bar height where
* the width of each bar is 1, find the area of largest rectangle in the histogram.
* Above is a histogram where width of each bar is 1, given height = [2,1,5,6,2,3].
* The largest rectangle is shown in the shaded area, which has area = 10 unit.
*
* Example:
*
* Input: [2,1,5,6,2,3]
* Output: 10
*/

#include <vector>
#include <algorithm>
#include <stack>
#include <cassert>
using namespace std;

/*  */
int largestRectangleArea_AR(vector<int>& heights) {
	int maxA = 0;
	int N = heights.size();
	if (N == 0)
		return 0;

	for (int cur = 0; cur < N; cur++) {
		if (cur == N - 1 || heights[cur] > heights[cur + 1]) {
			int minH = heights[cur];
			for (int idx = cur; idx >= 0; idx--) {
				minH = min(minH, heights[idx]);
				maxA = max(maxA, minH* (cur - idx + 1));
			}
		}
	}
	return maxA;
}

int largestRectangleArea_ST(vector<int>& heights) {
	int maxA = 0;
	int N = heights.size();
	if (N == 0)
		return 0;

	stack<int> stackIdx;

	for (int cur = 0; cur < N; cur++) {

		if (stackIdx.empty() || heights[cur] >= heights[stackIdx.top()]) {
			stackIdx.push(cur);
		}
		else {
			int right = cur;
			int idx = stackIdx.top();
			stackIdx.pop();
			while (!stackIdx.empty() && heights[stackIdx.top()] == heights[idx])
				stackIdx.pop();

			int left = stackIdx.empty() ? -1 : stackIdx.top();
			maxA = max(maxA, heights[idx] * (right - left - 1));
			cur--;
		}
	}

	int right = stackIdx.top() + 1;
	while (!stackIdx.empty()) {
		int idx = stackIdx.top();
		stackIdx.pop();
		int left = stackIdx.empty() ? -1 : stackIdx.top();
		maxA = max(maxA, heights[idx] * (right - left - 1));
	}
	return maxA;
}

int main()
{
	vector<int> heights = { 2,1,5,6,2,3 };
	int ans = 10;
	int ret1 = largestRectangleArea_AR(heights);
	assert(ret1 == ans);

	int ret2 = largestRectangleArea_ST(heights);
	assert(ret2 == ans);
	return 0;
}
