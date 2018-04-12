/* Write a program to find the n-th ugly number.
*
* Ugly numbers are positive numbers whose prime factors only include 2, 3, 5.
* For example, 1, 2, 3, 4, 5, 6, 8, 9, 10, 12 is the sequence of the first 10
* ugly numbers.
*
* Note that 1 is typically treated as an ugly number, and n does not exceed 1690.
*/

#include <vector>
#include <algorithm>
#include <cassert>
using namespace std;

int nthUglyNumber(int n) {

	if (n <= 0)
		return 0;
	if (n == 1)
		return 1;

	vector<int> u(n);
	u[0] = 1;
	int p1 = 0, p2 = 0, p3 = 0;
	for (int i = 1; i < n; i++) {
		u[i] = min(u[p1] * 2, min(u[p2] * 3, u[p3] * 5));
		if (u[i] == u[p1] * 2)
			p1++;
		if (u[i] == u[p2] * 3)
			p2++;
		if (u[i] == u[p3] * 5)
			p3++;
	}
	return u[n - 1];
}

int main()
{
	int n = 50;
	int ans = 243;
	int ret = nthUglyNumber(n);
	assert(ret == ans);
	return 0;
}
