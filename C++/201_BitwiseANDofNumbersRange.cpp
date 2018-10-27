/* Given a range [m, n] where 0 <= m <= n <= 2147483647, return the bitwise AND
* of all numbers in this range, inclusive.
*
* For example, given the range [5, 7], you should return 4.
*/

#include <bitset>
#include <cassert>
using namespace std;

/* only if both m's and n's highest 1 bits are all in the same location can we
return a non-zero value*/

int rangeBitwiseAnd(int m, int n) {
	int cnt = 0;
	while (m != n) {
		m >>= 1;
		n >>= 1;
		cnt++;
	}
	return m << cnt;
}

int main()
{
	int ret = rangeBitwiseAnd(5, 7);
	assert(ret == 4);
	return 0;
}
