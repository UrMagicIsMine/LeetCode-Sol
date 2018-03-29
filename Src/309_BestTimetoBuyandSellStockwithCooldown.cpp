/* Say you have an array for which the ith element is the price of a given stock
* on day i.
*
* Design an algorithm to find the maximum profit. You may complete as many
* transactions as you like (ie, buy one and sell one share of the stock multiple
* times) with the following restrictions:
*
* You may not engage in multiple transactions at the same time (ie, you must
* sell the stock before you buy again).
* After you sell your stock, you cannot buy stock on next day. (ie, cooldown 1
* day)
* Example:
*
* prices = [1, 2, 3, 0, 2]
* maxProfit = 3
* transactions = [buy, sell, cooldown, buy, sell]
*/

#include <string>
#include <vector>
#include <algorithm>
#include <cassert>
using namespace std;

/*
1. Define States

To represent the decision at index i:

buy[i] : Max profit till index i.The series of transaction is ending with a buy.
sell[i] : Max profit till index i.The series of transaction is ending with a sell.
To clarify :

Till index i, the buy / sell action must happen and must be the last action.It
may not happen at index i.It may happen at i - 1, i - 2, ... 0.
In the end n - 1, return sell[n - 1].Apparently we cannot finally end up with a buy.

2. Define Recursion

buy[i]: To make a decision whether to buy at i, we either take a rest, by just
using the old decision at i - 1, or sell at / before i - 2, then buy at i, We
cannot sell at i - 1, then buy at i, because of cooldown.
sell[i] : To make a decision whether to sell at i, we either take a rest, by
just using the old decision at i - 1, or buy at / before i - 1, then sell at i.
So we get the following formula :

buy[i] = Math.max(buy[i - 1], sell[i - 2] - prices[i]);
sell[i] = Math.max(sell[i - 1], buy[i - 1] + prices[i]);

*/

int maxProfit_DP1(vector<int>& prices) {

	/*
	buy[i] = Math.max(buy[i - 1], sell[i - 2] - prices[i]);
	sell[i] = Math.max(sell[i - 1], buy[i - 1] + prices[i]);
	*/

	int ret = 0;
	int N = prices.size();
	if (N<2)
		return 0;

	vector<int> buy(N + 1, 0);
	buy[0] = -prices[0];
	vector<int> sell(N + 2, 0);
	for (int i = 0; i < N; i++)
	{
		buy[i + 1] = max(buy[i], sell[i] - prices[i]);
		sell[i + 2] = max(sell[i + 1], buy[i] + prices[i]);
	}
	return sell[N + 1];
}

int maxProfit_DP2(vector<int>& prices) {

	/*
	buy[i] = Math.max(buy[i - 1], sell[i - 2] - prices[i]);
	sell[i] = Math.max(sell[i - 1], buy[i - 1] + prices[i]);
	*/

	int ret = 0;
	int N = prices.size();
	if (N<2)
		return 0;

	int buy_pre = -prices[0], buy = 0;
	int sell_p2 = 0, sell_p1 = 0, sell = 0;

	for (int i = 0; i < N; i++)
	{
		buy = max(buy_pre, sell_p2 - prices[i]);
		sell = max(sell_p1, buy_pre + prices[i]);

		buy_pre = buy;
		sell_p2 = sell_p1;
		sell_p1 = sell;
	}
	return sell;
}

int main()
{
	vector<int> prices = { 1, 2, 3, 0, 2 };
	int ans = 3;
	int ret1 = maxProfit_DP1(prices);
	assert(ret1 == ans);

	int ret2 = maxProfit_DP2(prices);
	assert(ret2 == ans);
	return 0;
}
