/* Given an array of n positive integers and a positive integer s, find the
* minimal length of a contiguous subarray of which the sum >= s. If there isn't
* one, return 0 instead.
*
* For example, given the array [2,3,1,2,4,3] and s = 7,
* the subarray [4,3] has the minimal length under the problem constraint.
*/

#include <vector>
#include <algorithm>
#include <cassert>
using namespace std;

/* two pointer solution, run-time O(N) */

int minSubArrayLen(int s, vector<int>& nums) {
	int n = nums.size(), ret = INT_MAX;
	int ft = 0, bk = 0, sum = 0;
	for (; ft < nums.size(); ft++) {
		sum += nums[ft];
		if (sum < s) continue;
		while (bk <= ft && sum >= s) {
			ret = min(ret, ft - bk + 1);
			sum -= nums[bk];
			bk++;
		}
	}
	return ret == INT_MAX ? 0 : ret;
}

int main()
{
	vector<int> nums = { 2,3,1,2,4,3 };
	int s = 7;
	int ans = 2;
	int ret = minSubArrayLen(s, nums);
	assert(ret == ans);
	return 0;
}
