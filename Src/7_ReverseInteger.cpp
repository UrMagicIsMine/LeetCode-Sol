/* Given a 32-bit signed integer, reverse digits of an integer.

Example 1:

Input: 123
Output: 321
Example 2:

Input: -123
Output: -321
Example 3:

Input: 120
Output: 21
Note:
Assume we are dealing with an environment which could only
store integers within the 32-bit signed integer range: [-2^31,  2^31 - 1].
For the purpose of this problem, assume that your function returns 0 when the
reversed integer overflows.
*/
#include <vector>
#include <map>
#include <cassert>
using namespace std;

int reverse(int x) {

	bool isPos = x > 0 ? true : false;
	long long absX = abs((long long)x);
	long long ret = 0;

	while (absX) {
		int re = absX % 10;
		absX /= 10;
		ret = ret * 10 + re;
	}

	if (ret > INT_MAX)
		return 0;
	return isPos ? ret : -ret;
}

int main()
{
	int x = -123405;
	int ans = -504321;
	int ret = reverse(ans);
	assert(ret == ans);
	return 0;
}
