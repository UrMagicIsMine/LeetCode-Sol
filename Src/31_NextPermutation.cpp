/* Implement next permutation, which rearranges numbers into the lexicographically
* next greater permutation of numbers.
*
* If such arrangement is not possible, it must rearrange it as the lowest possible
* order (ie, sorted in ascending order).
*
* The replacement must be in-place and use only constant extra memory.
*
* Here are some examples. Inputs are in the left-hand column and its corresponding
* outputs are in the right-hand column.
*
* 1,2,3 -> 1,3,2
* 3,2,1 -> 1,2,3
* 1,1,5 -> 1,5,1
*/

#include <vector>
#include <numeric>
#include <algorithm>
#include <cassert>
using namespace std;

/*
1) from right to left, find the first element i that violate the increasing trend;
2) find right to left, find the first element k that is larger than element i;
3) swap element i and k, reverse vectors in range [i+1, end)
*/
void nextPermutation(vector<int>& nums) {
	int N = nums.size();
	if (N <= 1)
		return;

	int i = N - 2;
	for (; i >= 0; i--)
		if (nums[i] < nums[i + 1]) break;

	// descending order
	if (i == -1) {
		reverse(nums.begin(), nums.end());
		return;
	}

	// find the place to swap;
	int k = N - 1;
	for (; k >= 0; k--) {
		if (nums[k] > nums[i])
			break;
	}

	swap(nums[i], nums[k]);
	reverse(nums.begin() + i + 1, nums.end());
	return;
}

int main()
{
	vector<int> nums = { 1,5,4,3,2,1 };
	vector<int> ret = { 2,1,1,3,4,5 };
	nextPermutation(nums);
	assert(ret == nums);
	return 0;
}
