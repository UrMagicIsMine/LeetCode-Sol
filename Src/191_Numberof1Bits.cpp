/* Write a function that takes an unsigned integer and returns the number of '1'
* bits it has (also known as the Hamming weight).
*
* For example, the 32-bit integer ’11' has binary representation
* 00000000000000000000000000001011, so the function should return 3.
*/

#include <bitset>
#include <cassert>
using namespace std;

/* Solution : bitset, test operation */

int hammingWeight_Sln1(uint32_t n) {

	int weight = 0;
	bitset<32> bits(n);

	for (int i = 0; i < 32; i++) {
		if (bits.test(i))
			weight++;
	}
	return weight;
}

/* Solution : direct bit manipulation use bit operator */

int hammingWeight_Sln2(uint32_t n) {

	int weight = 0;
	while (n)
	{
		if (n & 1) {
			weight++;
		}
		n >>= 1;
	}
	return weight;
}

int main()
{
	int ret1 = hammingWeight_Sln1(11);
	assert(ret1 == 3);
	int ret2 = hammingWeight_Sln2(11);
	assert(ret2 == 3);
	return 0;
}
