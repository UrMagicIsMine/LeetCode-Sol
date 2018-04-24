/* Given n non-negative integers representing an elevation map where the width
* of each bar is 1, compute how much water it is able to trap after raining.
*
* The above elevation map is represented by array [0,1,0,2,1,0,1,3,2,1,2,1]. In
* this case, 6 units of rain water (blue section) are being trapped.
*
* Example:
*
* Input: [0,1,0,2,1,0,1,3,2,1,2,1]
* Output: 6
*/

#include <vector>
#include <string>
#include <algorithm>
#include <cassert>
using namespace std;

int trap(vector<int>& height) {

	int N = height.size();
	vector<int> left(N, 0), right(N, 0);
	int lmax = 0, rmax = 0;

	// find the maximum height looking to the left;
	for (int i = 0; i < N; i++) {
		left[i] = lmax;
		lmax = max(lmax, height[i]);
	}
	int ret = 0;
	// find the maximum height looking to the right;
	for (int i = N - 1; i >= 0; i--) {
		right[i] = rmax;
		rmax = max(rmax, height[i]);
		// accumulate the rain
		if (left[i] > height[i] && right[i] > height[i])
			ret += min(left[i], right[i]) - height[i];
	}
	return ret;
}

int main()
{
	vector<int> height = { 0,1,0,2,1,0,1,3,2,1,2,1 };
	int ans = 6;
	int ret = trap(height);
	assert(ret == ans);
	return 0;
}
