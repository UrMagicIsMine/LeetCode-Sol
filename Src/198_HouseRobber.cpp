/* You are a professional robber planning to rob houses along a street. Each
* house has a certain amount of money stashed, the only constraint stopping you
* from robbing each of them is that adjacent houses have security system connected
* and it will automatically contact the police if two adjacent houses were broken
* into on the same night.
*
* Given a list of non-negative integers representing the amount of money of each
* house, determine the maximum amount of money you can rob tonight without alerting
* the police.
*/

#include <vector>
#include <algorithm>
#include <cassert>
using namespace std;

/* Solution : robMoney[i-1] means the most value that can be robbed before the ith store.
*  For each store, we have two choice: rob or not rob:
*   -- if robMoney[i-2] + nums[i] > robMoney[i-1], rob it, and robMoney[i] = robMoney[i-2] + nums[i]
*   -- otherwise, do not robbing, robMoney[i] = robMoney[i-1];
*/

/* Solution 1: run-time O(N), memory O(N) */
int rob_Sln1(vector<int>& nums) {

	int N = nums.size();
	if (N == 0)
		return 0;
	if (N == 1)
		return nums[0];

	vector<int> robMoney(N, 0);
	robMoney[0] = nums[0];
	robMoney[1] = max(nums[0], nums[1]);

	for (int i = 2; i < N; i++) {
		robMoney[i] = max(robMoney[i - 2] + nums[i], robMoney[i - 1]);
	}
	return robMoney[N - 1];
}

/* Solution 2: run-time O(N), memory O(1) */
int rob_Sln2(vector<int>& nums) {

	int N = nums.size();
	int preRob = 0, curRob = 0;

	for (int i = 0; i < N; i++) {
		int tmp = max(nums[i] + preRob, curRob);
		preRob = curRob;
		curRob = tmp;

	}
	return curRob;
}

int main()
{
	vector<int> money = { 1,2,3,1 };
	int ret1 = rob_Sln1(money);
	assert(ret1 == 4);
	int ret2 = rob_Sln2(money);
	assert(ret2 == 4);
	return 0;
}
