/* Given an array nums and a value val, remove all instances of that value in-place
* and return the new length.
*
* Do not allocate extra space for another array, you must do this by modifying
* the input array in-place with O(1) extra memory.
*
* The order of elements can be changed. It doesn't matter what you leave beyond
* the new length.
*
* Example 1:
*
* Given nums = [0,1,2,2,3,0,4,2], val = 2,
*
* Your function should return length = 5, with the first five elements of nums
* containing 0, 1, 3, 0, and 4.
*
* Note that the order of those five elements can be arbitrary.
*
* It doesn't matter what values are set beyond the returned length.
*/

#include <vector>
#include <cassert>
using namespace std;

/* we can keep two pointers i and pos, where pos is the slow-runner while i is
* the fast-runner. When nums[i] equals to the given value, skip this element by
* incrementing j. As long as nums[i] != val, we copy nums[j] to nums[pos] and
* increment both indexes at the same time. Repeat the process until i reaches the
* end of the array and the new length is pos.
* two pointer, one pass solution run-time O(N), space O(1)
*/

int removeElement(vector<int>& nums, int val) {

	int pos = 0;
	for (int i = 0; i < nums.size(); i++) {
		if (nums[i] != val)
			nums[pos++] = nums[i];
	}
	return pos;

}

int main()
{
	vector<int> nums = { 0,0,1,1,1,2,2,3,3,4 };
	int i = 1;
	int ret = removeElement(nums, i);
	vector<int> ans = { 0,0,2,2,3,3,4 };
	assert(ret == ans.size());
	for (int i = 0; i < ans.size(); i++)
		assert(ans[0] == nums[0]);
	return 0;
}
