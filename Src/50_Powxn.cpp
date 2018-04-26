/* Implement pow(x, n), which calculates x raised to the power n (xn).

Example 1:

Input: 2.00000, 10
Output: 1024.00000
Example 2:

Input: 2.10000, 3
Output: 9.26100
*/

#include <vector>
#include <string>
#include <unordered_map>
#include <algorithm>
#include <cassert>
using namespace std;

double myPow(double x, int n) {

	if (n == 0)
		return 1.0;

	bool isPos = n > 0 ? true : false;
	long long absN = abs((long long)n);

	double ret = 1.0, tmp = x;
	int i = 0;
	while (i < 32) {
		if (absN & 1 << i) {
			ret *= tmp;
		}
		tmp *= tmp;
		i++;
	}
	return isPos ? ret : 1.0 / ret;
}

int main()
{
	double x = 0.44894;
	int n = -5;
	double ans = 54.83508;
	double ret = myPow(x, n);
	assert(abs(ret - ans) < 1E-6);
	return 0;
}
