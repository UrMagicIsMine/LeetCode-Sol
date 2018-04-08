/* Given an integer, write a function to determine if it is a power of two.
*/

#include <cassert>
using namespace std;

/* Bit manipulation */
bool isPowerOfTwo(int n) {
	return !(n & (n - 1)) && (n >0);
}

int main()
{
	int num = 32;
	bool ans = true;
	bool ret = isPowerOfTwo(num);
	assert(ret == ans);
	return 0;

}
