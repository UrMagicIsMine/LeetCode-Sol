/* Given a positive integer n, break it into the sum of at least two positive
* integers and maximize the product of those integers. Return the maximum product
* you can get.
*
* For example, given n = 2, return 1 (2 = 1 + 1); given n = 10, return 36 (10 = 3 + 3 + 4).
*
* Note: You may assume that n is not less than 2 and not larger than 58.
*/

#include <vector>
#include <algorithm>
#include <cassert>
using namespace std;

/* If an optimal product contains a factor f >= 4, then you can replace it with
* factors 2 and f-2 without losing optimality, as 2*(f-2) = 2f-4 >= f. So you
* never need a factor greater than or equal to 4, meaning you only need factors
* 1, 2 and 3 (and 1 is of course wasteful and you’d only use it for n=2 and n=3,
* where it’s needed).
*
* Because 3*3 is simply better than 2*2*2, so you’d never use 2 more than twice.
*
*/

/* Math solution, O(logN) */
int _pow(int b, int p) {
	int ret = 1;
	while (p--)
		ret *= b;
	return ret;
}

int integerBreak_Math(int n) {

	if (n<2)
		return 0;

	if (n == 2)
		return 1;
	else if (n == 3)
		return 2;
	else if (n == 4)
		return 4;
	else {
		int mod = n % 3;
		int div = n / 3;

		if (mod == 0)
			return _pow(3, div);
		if (mod == 1)
			return _pow(3, div - 1) * 4;
		else
			return _pow(3, div) * 2;
	}
}

/* DP solution, O(N) */

int integerBreak_DP(int n) {

	vector<int> mult = { 0,0,1,2,4,6,9 };

	if (n <= 6)
		return mult[n];
	else {
		vector<int> multDP(n + 1, 0);
		copy(mult.begin(), mult.end(), multDP.begin());

		for (int i = 7; i <= n; i++)
			multDP[i] = 3 * multDP[i - 3];
		return multDP[n];
	}

}

int main()
{
	int n = 46;
	int ans = 19131876;
	auto ret1 = integerBreak_Math(n);
	assert(ret1 == ans);

	auto ret2 = integerBreak_DP(n);
	assert(ret2 == ans);
	return 0;
}
