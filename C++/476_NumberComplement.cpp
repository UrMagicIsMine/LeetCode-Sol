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

int findComplement_BS(int num) {

	bitset<32> bits(num);

	bool LeadZero = true;
	for (int i = 31; i>=0; i--)
	{
		if (LeadZero) {
			if (bits.test(i) == true) {
				LeadZero = false;
				bits.flip(i);
			}
		}
		else
			bits.flip(i);
	}
	return bits.to_ulong();
}

int findComplement_BM(int num) {
	unsigned mask = ~0;
	while (mask & num)
		mask <<= 1;
	return ~mask & ~num;
}

int main()
{
	int num = 5;
	int ans = 2;
	int ret1 = findComplement_BS(num);
	assert(ret1 == ans);
	int ret2 = findComplement_BM(num);
	assert(ret2 == ans);
	return 0;
}
