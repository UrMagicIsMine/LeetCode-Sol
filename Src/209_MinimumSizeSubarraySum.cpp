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

	int N = nums.size();
	int front = 0, back = 0, sum = 0, ret = INT_MAX;
	for (; front < nums.size(); front++) {
		sum += nums[front];
		if (sum < s)
			continue;
		else if (sum >= s) {
			ret = min(ret, front - back + 1);
			while (back <= front && sum - nums[back] >= s) {
				sum -= nums[back];
				back++;
				ret = min(ret, front - back + 1);
			}
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
