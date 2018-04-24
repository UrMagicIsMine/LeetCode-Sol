/* Given an integer array nums, find the contiguous subarray (containing at least
* one number) which has the largest sum and return its sum.
*
* Example:
*
* Input: [-2,1,-3,4,-1,2,1,-5,4],
* Output: 6
* Explanation: [4,-1,2,1] has the largest sum = 6.
* Follow up:
*
* If you have figured out the O(n) solution, try coding another solution using
* the divide and conquer approach, which is more subtle.
*/

#include <vector>
#include <string>
#include <algorithm>
#include <cassert>
using namespace std;

int maxSubArray(vector<int>& nums) {

	int maxsum = INT_MIN, accum = 0;
	for (int i = 0; i < nums.size(); i++) {
		accum += nums[i];
		maxsum = max(maxsum, accum);
		accum = max(0, accum);
	}
	return maxsum;
}

int main()
{
	vector<int> nums = { -2,1,-3,4,-1,2,1,-5,4 };
	int ans = 6;
	int ret = maxSubArray(nums);
	assert(ret == ans);
	return 0;
}
