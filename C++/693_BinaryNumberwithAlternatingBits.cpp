/* Given a positive integer, output its complement number. The complement strategy
* is to flip the bits of its binary representation.
*
* Note:
* The given integer is guaranteed to fit within the range of a 32-bit signed integer.
* You could assume no leading zero bit in the integer’s binary representation.
* Example 1:
* Input: 5
* Output: 2
* Explanation: The binary representation of 5 is 101 (no leading zero bits), and
* its complement is 010. So you need to output 2.
* Example 2:
* Input: 1
* Output: 0
* Explanation: The binary representation of 1 is 1 (no leading zero bits), and
* its complement is 0. So you need to output 0.
*
*/

#include <string>
#include <bitset>
#include <cassert>
using namespace std;

bool hasAlternatingBits_BS(int n) {

	bitset<32> bits(n);
	bool LeadZero = true;
	bool flag = false;
	for (int i = 31; i >= 0; i--) {

		if (LeadZero) {
			if (bits.test(i) == true) {
				LeadZero = false;
			}
		}
		else {
			if (bits.test(i) != flag)
				return false;
			else
				flag = !flag;
		}

	}
	return true;
}

bool hasAlternatingBits_BM(int n) {
	n ^= n >> 1;
	return !(n & (n + 1));
}

int main()
{
	int num = 5;
	bool ans = true;
	bool ret1 = hasAlternatingBits_BS(num);
	assert(ret1 == ans);
	int ret2 = hasAlternatingBits_BM(num);
	assert(ret2 == ans);
	return 0;
}
