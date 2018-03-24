/* Given an array of n integers where n > 1, nums, return an array output such
* that output[i] is equal to the product of all the elements of nums except nums[i].
*
* Solve it without division and in O(n).
*
* For example, given [1,2,3,4], return [24,12,8,6].
*
* Follow up:
* Could you solve it with constant space complexity? (Note: The output array does
* not count as extra space for the purpose of space complexity analysis.)
*/
#include<vector>
#include<algorithm>
#include <cassert>
using namespace std;

/* Solution: 1) multply the left product
 *           2) multiply the right product
 */

vector<int> productExceptSelf(vector<int>& nums) {
	int N = nums.size();
	vector<int> resl(N, 1);

	int left = 1;
	for (int i = 0; i < N; i++) {
		resl[i] *= left;
		left *= nums[i];
	}


	int right = 1;
	for (int i = N - 1; i >= 0; i--) {
		resl[i] *= right;
		right *= nums[i];
	}
	return resl;
}

int main()
{
	vector<int> nums = { 1,2,3,4 };
	vector<int> ret = productExceptSelf(nums);
	vector<int> ans = { 24, 12, 8, 6 };
	assert(ret == ans);
	return 0;
}
