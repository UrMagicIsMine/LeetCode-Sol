/* Say you have an array for which the ith element is the price of
* a given stock on day i.
*
* Design an algorithm to find the maximum profit. You may complete
* as many transactions as you like (ie, buy one and sell one share
* of the stock multiple times). However, you may not engage in multiple
* transactions at the same time (ie, you must sell the stock before you
* buy again).
*
*/
#include <vector>
#include <algorithm>

using namespace std;

int maxProfit(vector<int>& prices) {

	int maxProfit = 0;

	for (int i = 1; i < prices.size(); i++) {
		if (prices[i] - prices[i - 1] > 0)
			maxProfit += prices[i] - prices[i - 1];
	}
	return maxProfit;
}

int main()
{
	vector<int> prices = { 7, 1, 5, 3, 6, 4 };
	int ret = maxProfit(prices);
	return 0;
}
