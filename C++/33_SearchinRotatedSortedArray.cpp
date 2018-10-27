/* Suppose an array sorted in ascending order is rotated at some pivot unknown
* to you beforehand.
*
* (i.e., [0,1,2,4,5,6,7] might become [4,5,6,7,0,1,2]).
*
* You are given a target value to search. If found in the array return its index,
* otherwise return -1.
*
* You may assume no duplicate exists in the array.
*
* Your algorithm's runtime complexity must be in the order of O(log n).
*
* Example 1:
*
* Input: nums = [4,5,6,7,0,1,2], target = 0
* Output: 4
* Example 2:
*
* Input: nums = [4,5,6,7,0,1,2], target = 3
* Output: -1
*/

#include <vector>
#include <numeric>
#include <algorithm>
#include <cassert>
using namespace std;

int search(vector<int>& nums, int target) {
	int N = nums.size();
	if (N == 0)
		return -1;

	int low = 0, high = N - 1, mid;
	while (low < high) {
		mid = (low + high) / 2;
		if (nums[mid] == target)
			return mid;
		if (nums[mid] < nums[high]) {
			if (target > nums[mid] && target <= nums[high])
				low = mid + 1;
			else
				high = mid - 1;
		}
		else {
			if (target >= nums[low] && target < nums[mid])
				high = mid - 1;
			else
				low = mid + 1;
		}
	}
	return nums[low] == target ? low : -1;
}

int main()
{
	vector<int> nums = { 4,5,6,7,0,1,2 };
	int target = 0;
	int ans = 4;
	int ret = search(nums, target);
	assert(ret == ans);
	return 0;
}
