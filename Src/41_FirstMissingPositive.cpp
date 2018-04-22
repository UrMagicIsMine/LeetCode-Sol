/* Given an unsorted integer array, find the smallest missing positive integer.
*
* Example 1:
*
* Input: [1,2,0]
* Output: 3
* Example 2:
*
* Input: [3,4,-1,1]
* Output: 2
* Example 3:
*
* Input: [7,8,9,11,12]
* Output: 1
* Note:
*
* Your algorithm should run in O(n) time and uses constant extra space.
*/

#include <vector>
#include <algorithm>
#include <unordered_set>
#include <cassert>
using namespace std;

/* hashtable run-time O(1), space O(N) */

int firstMissingPositive_HT(vector<int>& nums) {
	unordered_set<int> hstbl;
	for (auto i : nums)
		hstbl.insert(i);

	int ret = 1;
	while (true) {
		if (hstbl.find(ret) == hstbl.end())
			return ret;
		ret++;
	}
}

/* Put each number in its right place.

For example:
When we find 5, then swap it with A[4].
At last, the first place where its number is not right, return the place + 1.

array run-time O(1), space O(1) */


int firstMissingPositive_AR(vector<int>& nums) {

	for (int i = 0; i < nums.size(); i++) {
		while (nums[i] > 0 && nums[i] < nums.size() && nums[i] != nums[nums[i] - 1])
			swap(nums[i], nums[nums[i] - 1]);
	}

	for (int i = 0; i < nums.size(); i++) {
		if (nums[i] != i + 1)
			return i + 1;
	}
	return nums.size() + 1;
}

int main()
{
	vector<int> nums1 = { 1,2,0 };
	int ans1 = 3;
	int ret1 = firstMissingPositive_HT(nums1);
	assert(ans1 == ret1);
	vector<int> nums2 = { 3,4,-1,1 };
	int ans2 = 2;
	int ret2 = firstMissingPositive_AR(nums2);
	assert(ans2 == ret2);
	return 0;
}
