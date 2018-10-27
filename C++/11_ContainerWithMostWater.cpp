/* Given n non-negative integers a1, a2, ..., an, where each represents a point
* at coordinate (i, ai). n vertical lines are drawn such that the two endpoints
* of line i is at (i, ai) and (i, 0). Find two lines, which together with x-axis
* forms a container, such that the container contains the most water.
*
* Note: You may not slant the container and n is at least 2.
*/

#include <vector>
#include <numeric>
#include <algorithm>
#include <cassert>
using namespace std;

/* The intuition behind this approach is that the area formed between the lines
will always be limited by the height of the shorter line. Further, the farther
the lines, the more will be the area obtained.

We take two pointers, one at the beginning and one at the end of the array
constituting the length of the lines. Futher, we maintain a variable max_area to
store the maximum area obtained till now. At every step, we find out the area
formed between them, update max_area and move the pointer pointing to the shorter
line towards the other end by one step.

If we try to move the pointer at the longer line inwards, we won't gain any
increase in area, since it is limited by the shorter line. But moving the shorter
line's pointer could turn out to be beneficial, as per the same argument, despite
the reduction in the width.

Run-time O(N), memory O(1)
*/

int maxArea(vector<int>& height) {

	int maxA = 0, low = 0, high = height.size() - 1;
	while (low < high) {
		int area = min(height[low], height[high]) * (high - low);
		maxA = max(maxA, area);
		if (height[low] < height[high])
			low++;
		else
			high--;
	}
	return maxA;
}

int main()
{
	vector<int> nums = { 1,3,7,4,5,3,2,1 };
	int ans = 12;
	int ret = maxArea(nums);
	assert(ret == ans);
	return 0;
}
