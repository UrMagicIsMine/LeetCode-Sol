/* Implement int sqrt(int x).

Compute and return the square root of x, where x is guaranteed to be a non-negative
integer.

Since the return type is an integer, the decimal digits are truncated and only the
integer part of the result is returned.

Example 1:

Input: 4
Output: 2
Example 2:

Input: 8
Output: 2
Explanation: The square root of 8 is 2.82842..., and since
             the decimal part is truncated, 2 is returned.
*/

#include <cassert>
using namespace std;

int mySqrt(int x) {
	long long low = 0, high = x;
	long long mid;
	while (low <= high) {
		mid = (low + high) / 2;
		long long ms = mid * mid;
		long long ns = (mid + 1)*(mid + 1);
		if (ms <= x && ns > x)
			return mid;
		else if (ms > x)
			high = mid;
		else
			low = mid + 1;
	}
	return low;
}

int main()
{
	int x = 2147395599;
	int ans = 46339;
	int ret = mySqrt(x);
	assert(ret == ans);
	return 0;
}
