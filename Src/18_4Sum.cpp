/* Given an array nums of n integers and an integer target, are there elements
* a, b, c, and d in nums such that a + b + c + d = target? Find all unique
* quadruplets in the array which gives the sum of target.
*
* Note:
*
* The solution set must not contain duplicate quadruplets.
*
* Example:
*
* Given array nums = [1, 0, -1, 0, -2, 2], and target = 0.
*
* A solution set is:
* [
*   [-1,  0, 0, 1],
*   [-2, -1, 1, 2],
*   [-2,  0, 0, 2]
* ]
* 
*/

#include <vector>
#include <numeric>
#include <algorithm>
#include <cassert>
using namespace std;

/* Similar to 3SUM, run-time O(N^3), memory O(1) */

vector<vector<int>> fourSum(vector<int>& nums, int target) {
	int N = nums.size();
	sort(nums.begin(), nums.end());
	vector<vector<int>> resl;
	for (int i = 0; i < N - 3; i++) {

		for (int j = i + 1; j < N - 2; j++) {
			int front = N - 1, back = j + 1;

			while (back < front) {
				int sum = nums[i] + nums[j] + nums[back] + nums[front];
				if (sum < target)
					back++;
				else if (sum > target)
					front--;
				else {
					resl.push_back({ nums[i], nums[j], nums[back++], nums[front--] });
					while (back < front && nums[back] == nums[back - 1])
						back++;
					while (back < front && nums[front] == nums[front + 1])
						front--;
				}
			}
			while (j < N - 2 && nums[j] == nums[j + 1])
				j++;
		}
		while (i < N - 3 && nums[i] == nums[i + 1])
			i++;
	}
	return resl;
}

int main()
{
	vector<int> nums = { 1,0,-1,0,-2,2 };
	int target = 0;
	vector<vector<int>> ret = fourSum(nums, target);
	vector<vector<int>> ans = { {-2, -1, 1, 2},{-2, 0, 0, 2},{-1, 0, 0, 1} };
	assert(ret == ans);
	return 0;
}
