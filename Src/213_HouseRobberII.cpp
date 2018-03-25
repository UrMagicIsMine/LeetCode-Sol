/* Note: This is an extension of House Robber.
*
* After robbing those houses on that street, the thief has found himself a new
* place for his thievery so that he will not get too much attention. This time,
* all houses at this place are arranged in a circle. That means the first house
* is the neighbor of the last one. Meanwhile, the security system for these houses
* remain the same as for those in the previous street.
*
* Given a list of non-negative integers representing the amount of money of each
* house, determine the maximum amount of money you can rob tonight without alerting
* the police.
*/

#include <vector>
#include <algorithm>
#include <cassert>
using namespace std;

/* DP algorithm, O(N)
* Since House[1] and House[n] are adjacent, they cannot be robbed together.
* Therefore, the problem becomes to rob either House[1]-House[n-1]
* or House[2]-House[n], depending on which choice offers more money. Now the
* problem has degenerated to the House Robber, which is already been solved.
*/

int rob(vector<int>& nums, int bg, int ed) {

	int preRobbed = 0, curRobbed = 0;
	for (int i = bg; i< ed; i++) {
		int tmp = max(preRobbed + nums[i], curRobbed);
		preRobbed = curRobbed;
		curRobbed = tmp;
	}
	return curRobbed;
}

int rob(vector<int>& nums) {

	int N = nums.size();
	if (N == 0)
		return 0;
	if (N == 1)
		return nums[0];
	return max(rob(nums, 0, N - 1), rob(nums, 1, N));

}

int main()
{
	vector<int> nums = { 2,3,1,2,4,5 };
	int ans = 10;
	int ret = rob(nums);
	assert(ret == ans);
	return 0;
}
