/* You are given a list of non-negative integers, a1, a2, ..., an, and a target, S.
* Now you have 2 symbols + and -. For each integer, you should choose one from
* + and - as its new symbol.
*
* Find out how many ways to assign symbols to make sum of integers equal to target S.
*
* Example 1:
* Input: nums is [1, 1, 1, 1, 1], S is 3.
* Output: 5
* Explanation:
*
* -1+1+1+1+1 = 3
* +1-1+1+1+1 = 3
* +1+1-1+1+1 = 3
* +1+1+1-1+1 = 3
* +1+1+1+1-1 = 3
*
* There are 5 ways to assign symbols to make the sum of nums be target 3.
* Note:
* The length of the given array is positive and will not exceed 20.
* The sum of elements in the given array will not exceed 1000.
* Your output answer is guaranteed to be fitted in a 32-bit integer.
*
*/

#include <vector>
#include <algorithm>
#include <cassert>
using namespace std;

/* Solution 1: The brute force approach
This solution is based on recursion. We need to try to put both
the + and - symbols at every location in the given numsnums array
and find out the assignments which lead to the required result S.
*/

/* n refers to the size of nums array.
Time complexity : O(2^n). Size of recursion tree will be 2^n
Space complexity : O(n). The depth of the recursion tree can go upto n.
*/

void _calcDFS(vector<int>& nums, int idx, int sum, int target, int &resl) {

	if (idx == nums.size()) {
		if (sum == target)
			resl++;
	}
	else {
		_calcDFS(nums, idx + 1, sum + nums[idx], target, resl);
		_calcDFS(nums, idx + 1, sum - nums[idx], target, resl);
	}
	return;

}

int findTargetSumWays_BF(vector<int>& nums, int S) {

	int resl = 0;
	_calcDFS(nums, 0, 0, S, resl);
	return resl;

}

/* Solution: brute force with memoization
in Solution 1, a lot of redundant function calls could be made with the same value
of ii as the current index and the same value of sumsum as the current sum, since
the same values could be obtained through multiple paths in the recursion tree. In
order to remove this redundancy, we make use of memoization as well to store the
results which have been calculated earlier.

we store the result obtained in memo[i][sum + 1000]memo[i][sum+1000]. The factor of
1000 has been added as an offset to the sumsum value to map all the sumsums possible
to positive integer range.

Time complexity : O(l*n). l refers to the range of sum
Space complexity : O(l*n). 2D memo space have dimension of n X l.
*/

using vec2D = vector<vector<int>>;

int _calcDFS_memo(vector<int>& nums, int idx, int sum, int target, vec2D& memo) {

	if (idx == nums.size()) {
		if (sum == target)
			return 1;
		else
			return 0;
	}
	else {

		if (memo[idx][sum + 1000] != INT_MIN)
			return memo[idx][sum + 1000];
		int add = _calcDFS_memo(nums, idx + 1, sum + nums[idx], target, memo);
		int sub = _calcDFS_memo(nums, idx + 1, sum - nums[idx], target, memo);
		memo[idx][sum + 1000] = add + sub;
		return memo[idx][sum + 1000];
	}
}

int findTargetSumWays_BM(vector<int>& nums, int S) {

	vec2D memo(nums.size(), vector<int>(2001, INT_MIN));
	return _calcDFS_memo(nums, 0, 0, S, memo);

}

/* Solution 3: Dynamic Programming Solutions
dp[i][j] refers to the number of assignments which can lead to a sum of j upto
the i-th index, then we have the following relationship:
   1) dp[i][sum + nums[i] + offset] += dp[i - 1][sum + offset]
   2) dp[i][sum - nums[i] + offset] += dp[i - 1][sum + offset]
The results whill be stored in dp[n-1][target+offset]

Time complexity : O(l*n). l refers to the range of sum
Space complexity : O(l*n). Array dp have dimension of n X l.
*/

int findTargetSumWays_DP1(vector<int>& nums, int S) {

	if (nums.size() == 0)
		return 0;

	int offset = 1000;
	vec2D dp(nums.size(), vector<int>(2 * offset + 1, 0));

	dp[0][nums[0] + offset] = 1;
	dp[0][-nums[0] + offset] += 1;

	for (int i = 1; i < nums.size(); i++) {

		for (int sum = -offset; sum <= offset; sum++) {
			if (dp[i - 1][sum + offset] > 0) {
				dp[i][sum + nums[i] + offset] += dp[i - 1][sum + offset];
				dp[i][sum - nums[i] + offset] += dp[i - 1][sum + offset];
			}
		}

	}

	return abs(S) > 1000 ? 0 : dp[nums.size() - 1][S + offset];
}

/* Solution 3: Dynamic Programming Solutions with memory optimized
dp[j] refers to the number of assignments which can lead to a sum of j
1) next[sum + nums[i] + offset] += dp[sum + offset];
2) next[sum - nums[i] + offset] += dp[sum + offset];
After every update, next should be copy to dp and next will be fill to all 0;
The results whill be stored in dp[target+offset]

Time complexity : O(l*n). l refers to the range of sum
Space complexity : O(l). optimized array dp use O(l) memory.
*/

int findTargetSumWays_DP2(vector<int>& nums, int S) {

	if (nums.size() == 0)
		return 0;

	int offset = 1000;
	vector<int> dp(2 * offset + 1, 0);
	vector<int> next(2 * offset + 1, 0);

	dp[nums[0] + offset] = 1;
	dp[-nums[0] + offset] += 1;

	for (int i = 1; i < nums.size(); i++) {
		std::fill(next.begin(), next.end(), 0);
		for (int sum = -offset; sum <= offset; sum++) {
			if (dp[sum + offset] > 0) {
				next[sum + nums[i] + offset] += dp[sum + offset];
				next[sum - nums[i] + offset] += dp[sum + offset];
			}
		}
		dp = next;
	}

	return abs(S) > 1000 ? 0 : dp[S + offset];
}

int main()
{
	vector<int> nums = { 1,1,1,1,1 };
	int target = 3;
	int ans = 5;
	int ret1 = findTargetSumWays_BF(nums, target);
	assert(ret1 == ans);

	int ret2 = findTargetSumWays_BM(nums, target);
	assert(ret2 == ans);

	int ret3 = findTargetSumWays_DP1(nums, target);
	assert(ret3 == ans);

	int ret4 = findTargetSumWays_DP2(nums, target);
	assert(ret4 == ans);
	return 0;
}
