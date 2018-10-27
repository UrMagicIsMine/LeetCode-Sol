/* You are given coins of different denominations and a total amount of money amount.
* Write a function to compute the fewest number of coins that you need to make up
* that amount. If that amount of money cannot be made up by any combination of the
* coins, return -1.
*
* Example 1:
* coins = [1, 2, 5], amount = 11
* return 3 (11 = 5 + 5 + 1)
*
* Example 2:
* coins = [2], amount = 3
* return -1.
*
* Note:
* You may assume that you have an infinite number of each kind of coin.
*/

#include <cassert>
#include <vector>
#include <algorithm>
#include <functional>
using namespace std;

/* Depth-First Search Solution */

int _coinChange(const vector<int>& coins, int amount, int idx, int cur, int &cand) {

	if (!amount)return cand = cur;
	if (idx<0)return -1;
	int flag = 0, n = amount / coins[idx];
	if (n + cur >= cand)return -1;
	for (int i = n;i >= 0;i--) {
		if (_coinChange(coins, amount - i * coins[idx], idx - 1, cur + i, cand) != -1) flag = 1;
	}
	if (flag) return cand;
	return -1;
}

int coinChange_DFS(vector<int>& coins, int amount) {

	/*return false for equal value, weak */
	//sort(coins.begin(), coins.end(), [](int i, int j) {return j < i;});
	//sort(coins.begin(), coins.end(), greater<int>());

	sort(coins.begin(), coins.end(), less<int>());
	int N = coins.size();
	int csize = INT_MAX;
	return _coinChange(coins, amount, coins.size() - 1, 0, csize);

}

/* Dynamic Programming Solution */

int coinChange_DP(vector<int>& coins, int amount) {

	vector<int> ccDPVec(amount + 1, INT_MAX);
	ccDPVec[0] = 0;
	for (int i = 1; i <= amount; i++) {

		for (int c = 0; c < coins.size(); c++) {
			if (i >= coins[c] && ccDPVec[i - coins[c]] != INT_MAX)
				ccDPVec[i] = min(ccDPVec[i], ccDPVec[i - coins[c]] + 1);
		}
	}
	return ccDPVec[amount] == INT_MAX ? -1 : ccDPVec[amount];
}

int main()
{
	int amount = 6249;
	vector<int> coins = { 186, 419, 83, 408 };
	int ans = 20;

	int ret1 = coinChange_DFS(coins, amount);
	assert(ret1 == ans);

	int ret2 = coinChange_DP(coins, amount);
	assert(ret2 == ans);
	return 0;

}
