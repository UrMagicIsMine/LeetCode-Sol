/* Given an array nums of n integers, are there elements a, b, c in nums such
* that a + b + c = 0? Find all unique triplets in the array which gives the sum
* of zero.
*
* Note:
*
* The solution set must not contain duplicate triplets.
*
* Example:
*
* Given array nums = [-1, 0, 1, 2, -1, -4],
*
* A solution set is:
* [  [-1, 0, 1],  [-1, -1, 2]]
*/

#include <vector>
#include <numeric>
#include <algorithm>
#include <cassert>
using namespace std;

/* The key part of this problem compared to 2SUM is, to jump over the number
which has been scanned.
Run-time O(N^2), memory O(1)
*/

vector<vector<int>> threeSum(vector<int>& nums) {
	vector<vector<int>> resl;
	sort(nums.begin(), nums.end());
	int N = nums.size();
	if (N < 3)
		return resl;

	for (int i = 0; i < N - 2; i++) {

		int target = -nums[i], front = N - 1, back = i + 1;
		while (back < front) {
			int sum = nums[front] + nums[back];
			if (sum < target)
				back++;
			else if (sum > target)
				front--;
			else {
				resl.push_back({ nums[i], nums[back++], nums[front--] });
        /* jump over repeated number nums[back] and nums[front] */
				while (back < front && nums[back] == nums[back - 1])
					back++;
				while (back < front && nums[front] == nums[front + 1])
					front--;
			}
		}
    /* jump over repeated number nums[i] */
		while (i < N - 2 && nums[i] == nums[i + 1])
			i++;
	}
	return resl;
}

int main()
{
	vector<int> nums = { -1, 0, 1, 2, -1, -4 };
	vector<vector<int>> ans = { {-1, -1, 2},{ -1, 0, 1 } };
	vector<vector<int>> ret = threeSum(nums);
	assert(ret == ans);
	return 0;
}
