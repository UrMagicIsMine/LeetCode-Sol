/* Calculate the sum of two integers a and b, but you are not allowed to use the
* operator + and -.
*
* Example:
* Given a = 1 and b = 2, return 3.
*/

#include <vector>
#include <bitset>
#include <algorithm>
#include <cassert>
using namespace std;

int getSum(int a, int b) {

	bitset<32> bits_a(a);
	bitset<32> bits_b(b);

	bool carry = false;
	for (int i = 0; i < 32; i++) {
		int tmp = 0;
		if (bits_a.test(i))
			tmp++;
		if (bits_b.test(i))
			tmp++;
		if (carry)
			tmp++;
		bits_a[i] = bits_a[i] ^ bits_b[i] ^ carry;
		if (tmp >= 2)
			carry = true;
		else
			carry = false;
	}
	return bits_a.to_ulong();

}

int main()
{
	int a = 1, b = 2;
	int ans = 3;
	int ret = getSum(a, b);
	assert(ret == ans);
	return 0;
}
