/* Say you have an array for which the ith element is the price of
* a given stock on day i.
*
* If you were only permitted to complete at most one transaction (ie,
* buy one and sell one share of the stock), design an algorithm to find
* the maximum profit.
*
* Example 1:
* Input: [7, 1, 5, 3, 6, 4]
* Output: 5
*
* max. difference = 6-1 = 5 (not 7-1 = 6, as selling price needs to be
* larger than buying price)
*
* Example 2:
* Input: [7, 6, 4, 3, 1]
* Output: 0
*
* In this case, no transaction is done, i.e. max profit = 0.
*/
#include <vector>
#include <algorithm>

using namespace std;

/* Brute-force solution, O(n^2) complexity */

int maxProfit_BF(vector<int>& prices) {

	int N = prices.size();
	if (N == 0)
		return 0;

	for (int i = 0; i < N; i++) {
		int Diff = *max_element(prices.begin() + i, prices.end()) - prices[i];
		prices[i] = Diff>0 ? Diff : 0;
	}

	return *max_element(prices.begin(), prices.end());

}

/* Kadane's algorithm (dynamic programming) , O(n) complexity */

int maxProfit_DP(vector<int>& prices) {

	int N = prices.size();
	if (N == 0)
		return 0;

	int minPrice = prices[0];
	int maxProfit = 0;
	for (int i = 1; i < N; i++) {

		/* if new bottom price, update minPrice */
		if (prices[i] < minPrice)
			minPrice = prices[i];
		/* if new high profit, update maxProfit */
		else if (prices[i] > minPrice && prices[i] - minPrice > maxProfit)
			maxProfit = prices[i] - minPrice;
	}
	return maxProfit;

}


int main()
{
	vector<int> prices = { 7, 1, 5, 3, 6, 4 };
	int ret1 = maxProfit_BF(prices);
	int ret2 = maxProfit_DP(prices);
	return 0;
}
