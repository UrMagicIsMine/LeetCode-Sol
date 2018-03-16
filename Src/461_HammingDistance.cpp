/* The Hamming distance between two integers is the number of positions at which
* the corresponding bits are different.
*
* Given two integers x and y, calculate the Hamming distance.
*
* Note:
* 0 <= x, y < 231.
*
* Example:
*
* Input: x = 1, y = 4
*
* Output: 2
*
* Explanation:
* 1   (0 0 0 1)
* 4   (0 1 0 0)
*        ^   ^
*
* The above arrows point to positions where the corresponding bits are different.
*/

#include <cassert>
using namespace std;

int hammingDistance(int x, int y) {

	int x_or = x ^ y;
	int hDis = 0, i = 0;
	while (i<32) {
		if (x_or & 1 << i++)
			hDis++;
	}
	return hDis;
}

int main()
{
	int x = 1, y = 4;
	int ans = 2;
	int ret = hammingDistance(x, y);
	assert(ret == ans);
	return 0;
}
