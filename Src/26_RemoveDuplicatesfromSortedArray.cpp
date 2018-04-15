/* Given a sorted array nums, remove the duplicates in-place such that each element
* appear only once and return the new length.
*
* Do not allocate extra space for another array, you must do this by modifying the
* input array in-place with O(1) extra memory.
*
* Example 1:
*
* Given nums = [1,1,2],
*
* Your function should return length = 2, with the first two elements of nums
* being 1 and 2 respectively.
*
* It doesn't matter what you leave beyond the returned length.
* Example 2:
*
* Given nums = [0,0,1,1,1,2,2,3,3,4],
*
* Your function should return length = 5, with the first five elements of nums
* being modified to 0, 1, 2, 3, and 4 respectively.
*
* It doesn't matter what values are set beyond the returned length.
*/

#include <vector>
#include <cassert>
using namespace std;

/* Since the array is already sorted, we can keep two pointers i and pos, where
* pos is the slow-runner while i is the fast-runner.
* As long as nums[i] != nums[i-1], we encounter a new number and assign it to the
* place (++pos) where it's supposed to be.
* two pointer, one pass solution run-time O(N), space O(1)
*/

int removeDuplicates(vector<int>& nums) {
	if (nums.size() == 0)
		return 0;
	int pos = 0;
	for (int i = 1; i <nums.size(); i++) {
		if (nums[i] != nums[i - 1])
			nums[++pos] = nums[i];
	}
	return pos + 1;
}

int main()
{
	vector<int> nums = { 0,0,1,1,1,2,2,3,3,4 };
	int ret = removeDuplicates(nums);
	vector<int> ans = { 0,1,2,3,4 };
	assert(ret == ans.size());
	for (int i = 0; i < ans.size(); i++)
		assert(ans[0] == nums[0]);
	return 0;
}
