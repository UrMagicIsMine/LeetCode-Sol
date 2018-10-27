/* Given two integers dividend and divisor, divide two integers without using
* multiplication, division and mod operator.
*
* Return the quotient after dividing dividend by divisor.
*
* Example 1:
*
* Input: dividend = 10, divisor = 3
* Output: 3
* Example 2:
*
* Input: dividend = 7, divisor = -3
* Output: -2
* Note:
*
* Both dividend and divisor will be 32-bit signed integers.
* The divisor will never be 0.
* Assume we are dealing with an environment which could only store integers within
* the 32-bit signed integer range: [−2^31,  2^31 − 1]. For the purpose of this
* problem, assume that your function returns 2^31 − 1 when the division result overflows.
*/

#include <vector>
#include <cassert>
using namespace std;

/* shift operator, be careful about the corner case */

int divide(int dividend, int divisor) {

	if (divisor == 0 || (dividend == INT_MIN && divisor == -1))
		return INT_MAX;

	bool isNeg = (dividend > 0 && divisor < 0) || (dividend < 0 && divisor > 0);
	long long dvd = abs((long long)dividend), dvs = abs((long long)divisor);
	int ret = 0;
	while (dvd >= dvs) {
		int i = 0;
		long long tmp = dvs;
		while (dvd >= tmp << 1) {
			tmp <<= 1;
			i++;
		}
		ret += 1 << i;
		dvd -= tmp;
	}
	return isNeg ? -ret : ret;
}

int main()
{
	int dividend = 214748368;
	int divisor = -1;
	int ans = -214748368;
	int ret = divide(dividend, divisor);
	assert(ret == ans);
	return 0;
}
