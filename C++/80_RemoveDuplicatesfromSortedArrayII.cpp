/* Given a sorted array nums, remove the duplicates in-place such that duplicates
appeared at most twice and return the new length.

Do not allocate extra space for another array, you must do this by modifying the
input array in-place with O(1) extra memory.

Example 1:

Given nums = [1,1,1,2,2,3],

Your function should return length = 5, with the first five elements of nums
being 1, 1, 2, 2 and 3 respectively.

It doesn't matter what you leave beyond the returned length.
*/
#include <vector>
#include <cassert>
using namespace std;

int removeDuplicates(vector<int>& nums) {
	if (nums.size() <= 2)
		return nums.size();
	int pos = 1, cnt = 1;
	for (int i = 1; i < nums.size(); i++) {
		if (nums[i] == nums[i - 1])
			cnt++;
		else
			cnt = 1;

		if (cnt <= 2)
			nums[pos++] = nums[i];
	}
	return pos;
}

int main()
{
	vector<int> nums = { 0,0,1,1,1,1,2,3,3 };
	vector<int> ans = { 0,0,1,1,2,3,3,3,3 };
	int len = 7;
	int ret = removeDuplicates(nums);
	assert(ret == len);
	assert(nums == ans);
	return 0;
}
