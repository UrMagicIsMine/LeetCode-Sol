/* Given an integer n, return the number of trailing zeroes in n!.
*
* Note: Your solution should be in logarithmic time complexity.
*/

#include <cassert>
using namespace std;

/* special case of de Polignac's formula */

/* we just count how many 5 factors in all number from 1 to n. with consideration of
5*5, 5*5*5, ... and their multiples.
*/
int trailingZeroes(int n) {

	int ret = 0;
	while (n)
	{
		n = n / 5;
		ret += n;
	}
	return ret;
}

int main()
{
	int ret = trailingZeroes(32);
	assert(ret == 7);
	return 0;
}
