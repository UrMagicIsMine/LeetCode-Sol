/* Reverse bits of a given 32 bits unsigned integer.
*
* For example, given input 43261596 (represented in binary as
* 00000010100101000001111010011100), return 964176192 (represented
* in binary as 00111001011110000010100101000000).
*/

#include <bitset>
#include <cassert>
using namespace std;

/* Solution 1: in-place use bitset, flip if not equal */

uint32_t reverseBits_Sln1(uint32_t n) {

	bitset<32> bits(n);

	for (int i = 0; i <32 / 2; i++) {

		if (bits[i] != bits[32 - 1 - i]) {
			bits[i].flip();
			bits[32 - 1 - i].flip();
		}
	}

	return bits.to_ulong();

}

/* Solution 2: use a copy of bitset, do reverse and convert */

uint32_t reverseBits_Sln2(uint32_t n) {

	bitset<32> x(n);
	bitset<32> y;

	int j = 31;
	for (int i = 0; i < 32; i++) {
		y[i] = x[j--];
	}

	return y.to_ulong();

}

/* Solution 3: Bit manipulation */

uint32_t reverseBits_Sln3(uint32_t n) {

		uint32_t mask = 1 << 31, ret = 0;
		while(n){
				if(n&1)
						ret |= mask;
				n >>= 1;
				mask >>= 1;
		}
		return ret;
}

int main()
{
	uint32_t ret1 = reverseBits_Sln1(43261596);
	assert(ret1 == 964176192);
	uint32_t ret2 = reverseBits_Sln2(43261596);
	assert(ret2 == 964176192);
	uint32_t ret3 = reverseBits_Sln3(43261596);
	assert(ret3 == 964176192);
	return 0;
}
