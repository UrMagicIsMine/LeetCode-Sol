/* Given a non negative integer number num. For every numbers i in the range
* 0 <= i <= num calculate the number of 1's in their binary representation and
* return them as an array.
*
* Example:
* For num = 5 you should return [0,1,1,2,1,2].
*
* Follow up:
*
* It is very easy to come up with a solution with run time O(n*sizeof(integer)).
* But can you do it in linear time O(n) /possibly in a single pass?
* Space complexity should be O(n).
* Can you do it like a boss? Do it without using any builtin function like
* __builtin_popcount in c++ or in any other language.
*/

#include <cassert>
#include <vector>
#include <algorithm>
using namespace std;

/* succinct DP solution */

vector<int> countBits(int num) {

	vector<int> resl(num + 1, 0);
	for (int i = 1; i <= num; i++)
		resl[i] = i & 1 ? (resl[i / 2] + 1) : resl[i / 2];

	return resl;
}

int main()
{
	int num = 6;
	vector<int> ans = { 0,1,1,2,1,2,2 };
	vector<int> ret = countBits(num);
	assert(ret == ans);
	return 0;

}
