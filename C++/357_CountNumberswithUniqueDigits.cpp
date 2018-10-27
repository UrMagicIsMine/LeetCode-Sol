/* Given a positive integer n, break it into the sum of at least two positive
* integers and maximize the product of those integers. Return the maximum product
* you can get.
*
* For example, given n = 2, return 1 (2 = 1 + 1); given n = 10, return 36
* (10 = 3 + 3 + 4).
*
* Note: You may assume that n is not less than 2 and not larger than 58.
*/

#include <vector>
#include <algorithm>
#include <cassert>
using namespace std;

/* DP solution, O(1)
* for Numbers with exactly i digits, it have 9 * 9 * 8 ... total unique number;
*/
int countNumbersWithUniqueDigits(int n) {

	vector<int> cntDi(11, 1);
	int sum = 1;
	int minN = min(10, n);

	for (int i = 1; i <= minN; i++) {
		cntDi[i] = cntDi[i - 1] * min(9, (10 - i + 1));
		sum += cntDi[i];
	}
	return sum;
}

int main()
{
	int n = 11;
	int ans = 8877691;
	auto ret1 = countNumbersWithUniqueDigits(n);
	assert(ret1 == ans);
	return 0;
}
