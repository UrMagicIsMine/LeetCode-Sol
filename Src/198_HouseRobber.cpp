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

int rob(vector<int>& nums) {

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

int main()
{
	vector<int> money = { 1,2,3,1 };
	int ret = rob(money);
	assert(ret == 4);
	return 0;
}
