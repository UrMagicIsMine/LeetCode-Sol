/* Say you have an array for which the ith element is the price of a given stock on day i.

Design an algorithm to find the maximum profit. You may complete at most two transactions.

Note: You may not engage in multiple transactions at the same time (i.e., you must sell the stock before you buy again).

Example 1:

Input: [3,3,5,0,0,3,1,4]
Output: 6
Explanation: Buy on day 4 (price = 0) and sell on day 6 (price = 3), profit = 3-0 = 3.
             Then buy on day 7 (price = 1) and sell on day 8 (price = 4), profit = 4-1 = 3.
Example 2:

Input: [1,2,3,4,5]
Output: 4
Explanation: Buy on day 1 (price = 1) and sell on day 5 (price = 5), profit = 5-1 = 4.
             Note that you cannot buy on day 1, buy on day 2 and sell them later, as you are
             engaging multiple transactions at the same time. You must sell before buying again.
Example 3:

Input: [7,6,4,3,1]
Output: 0
Explanation: In this case, no transaction is done, i.e. max profit = 0.
*/

#include <vector>
#include <algorithm>
#include <cassert>
using namespace std;

/* Greedy Solution
*/

int maxProfit(vector<int>& prices) {
	int buy1 = INT_MIN, sell1 = 0, buy2 = INT_MIN, sell2 = 0;

	for (auto p : prices) {
		buy1 = max(buy1, -p);
		sell1 = max(sell1, buy1 + p);
		buy2 = max(buy2, sell1 - p);
		sell2 = max(sell2, buy2 + p);
	}
	return sell2;
}

int main()
{
	vector<int> nums = { 3,3,5,0,0,3,1,4 };
	int ans = 6;
	int ret = maxProfit(nums);
	assert(ret == ans);
	return 0;
}
