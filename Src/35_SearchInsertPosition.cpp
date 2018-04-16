/* Given a sorted array and a target value, return the index if the target is
* found. If not, return the index where it would be if it were inserted in order.
*
* You may assume no duplicates in the array.
*
* Example 1:
*
* Input: [1,3,5,6], 5
* Output: 2
* Example 2:
*
* Input: [1,3,5,6], 2
* Output: 1
* Example 3:
*
* Input: [1,3,5,6], 7
* Output: 4
* Example 4:
*
* Input: [1,3,5,6], 0
* Output: 0
*/

#include <vector>
#include <cassert>
using namespace std;

/* Binary Search, analysis all the base cases with 2 left and 1 left
* run-time O(logN), space O(1)
*/

int searchInsert(vector<int>& nums, int target) {

	if (nums.size() == 0)
		return 0;

	int l = 0, r = nums.size() - 1, mid;
	while (l <= r) {
		mid = (l + r) / 2;
		if (nums[mid] < target)
			l = mid + 1;
		else if (nums[mid] > target)
			r = mid - 1;
		else
			return mid;
	}
	return l;
}

int main()
{
	vector<int> nums = { 1,3,5,6 };
	int target = 5;
	int ans = 2;
	int ret = searchInsert(nums, target);
	assert(ret == ans);
	return 0;
}
