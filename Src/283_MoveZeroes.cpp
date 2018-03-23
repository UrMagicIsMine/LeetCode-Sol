/* Given an array nums, write a function to move all 0's to the end of it while
* maintaining the relative order of the non-zero elements.
*
* For example, given nums = [0, 1, 0, 3, 12], after calling your function, nums
* should be[1, 3, 12, 0, 0].
*
* Note:
* You must do this in - place without making a copy of the array.
* Minimize the total number of operations.
*/
#include<vector>
#include <cassert>
using namespace std;

void moveZeroes(vector<int>& nums) {
	int pos = 0;
	for (int i = 0; i<nums.size(); i++) {
		if (nums[i] != 0)
			swap(nums[pos++], nums[i]);
	}
	return;
}

int main()
{
	vector<int> nums = { 0, 1, 0, 3, 12 };
	vector<int> ans = { 1, 3, 12, 0, 0 };
	moveZeroes(nums);
	assert(nums == ans);
	return 0;
}
