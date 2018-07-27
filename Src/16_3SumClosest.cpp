/* Given an array nums of n integers and an integer target, find three integers
* in nums such that the sum is closest to target. Return the sum of the three
* integers. You may assume that each input would have exactly one solution.
*
* Example:
*
* Given array nums = [-1, 2, 1, -4], and target = 1.
*
* The sum that is closest to the target is 2. (-1 + 2 + 1 = 2).
*/

#include <vector>
#include <numeric>
#include <algorithm>
#include <cassert>
using namespace std;

/* similar to 3SUM, use an variable to update the closest sum
* Run-time O(N^2), memory O(1)
*/

int threeSumClosest(vector<int>& nums, int target) {
	int N = nums.size();
	sort(nums.begin(), nums.end());
	int minSum = INT_MAX, ret = 0;
	for (int i = 0; i < N; i++) {
		int front = N - 1, back = i + 1;
		while (back < front) {

			int sum = nums[i] + nums[front] + nums[back];
      /* update the closest sum */
			if (minSum > abs(sum - target)) {
				minSum = abs(sum - target);
				ret = sum;
			}
			if (sum < target)
				back++;
			else if (sum > target)
				front--;
			else
        /* sum == target, return */
				return ret;
		}
		while(i+1 < N && nums[i] == nums[i+1])
			i++;
	}
	return ret;
}

int main()
{
	vector<int> nums = { -1, 2, 1, -4 };
	int target = 1;
	int ans = 2;
	int ret = threeSumClosest(nums, target);
	assert(ret == ans);
	return 0;
}
