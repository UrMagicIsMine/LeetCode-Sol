/* The gray code is a binary numeral system where two successive values differ
in only one bit.

Given a non-negative integer n representing the total number of bits in the code,
print the sequence of gray code. A gray code sequence must begin with 0.

For example, given n = 2, return [0,1,3,2]. Its gray code sequence is:

00 - 0
01 - 1
11 - 3
10 - 2
Note:
For a given n, a gray code sequence is not uniquely defined.

For example, [0,2,3,1] is also a valid gray code sequence according to the above
definition.
*/
#include <vector>
#include <cassert>
using namespace std;

/*Run-time O(2^n)*/

vector<int> grayCode(int n) {

	vector<int> resl;
	int size = 1 << n;
	resl.reserve(size);
	resl.push_back(0);
	for (int i = 0; i < n; i++) {
		int N = resl.size();
		for (int j = N - 1; j >= 0; j--) {
			resl.push_back(resl[j] | (1 << i));
		}
	}
	return resl;
}

int main()
{
	int n = 3;
	vector<int> ans = { 0,1,3,2,6,7,5,4 };
	vector<int> ret = grayCode(n);
	assert(ret == ans);
	return 0;
}
