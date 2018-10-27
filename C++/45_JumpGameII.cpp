/* Given an array of non-negative integers, you are initially positioned at the
* first index of the array.
*
* Each element in the array represents your maximum jump length at that position.
*
* Your goal is to reach the last index in the minimum number of jumps.
*
* Example:
*
* Input: [2,3,1,1,4]
* Output: 2
* Explanation: The minimum number of jumps to reach the last index is 2.
*     Jump 1 step from index 0 to 1, then 3 steps to the last index.
* Note:
*
* You can assume that you can always reach the last index.
*/

#include <vector>
#include <algorithm>
#include <unordered_set>
#include <cassert>
using namespace std;

/* Greedy algorithm
we keep two pointers start and end that record the current range of the starting
nodes. Each time after we make a move, update start to be end + 1 and end to be
the farthest index that can be reached in 1 move from the current [start, end]
*/


int jump(vector<int>& nums) {
	int N = nums.size();
	if (N == 1)
		return 0;
	int fast = 0, slow = 0, step = 0;
	while (fast < N - 1) {
		step++;
		int nxtfast = fast + 1;
		for (int i = slow; i <= fast; i++) {
			nxtfast = max(nxtfast, nums[i] + i);
			if (nxtfast >= N - 1)
				return step;
		}
		slow = fast + 1;
		fast = nxtfast;
	}
	return INT_MAX;
}

int main()
{
	vector<int> nums = { 2,3,1,1,4 };
	int ans = 2;
	int ret = jump(nums);
	assert(ret == ans);
	return 0;
}
