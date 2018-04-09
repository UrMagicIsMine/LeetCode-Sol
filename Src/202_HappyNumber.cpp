/* Write an algorithm to determine if a number is "happy".
*
* A happy number is a number defined by the following process: Starting with any
* positive integer, replace the number by the sum of the squares of its digits,
* and repeat the process until the number equals 1 (where it will stay), or it
* loops endlessly in a cycle which does not include 1. Those numbers for which
* this process ends in 1 are happy numbers.
*
* Example: 19 is a happy number
*
* 1^2 + 9^2 = 82
* 8^2 + 2^2 = 68
* 6^2 + 8^2 = 100
* 1^2 + 0^2 + 0^2 = 1
*/

#include <vector>
#include <stack>
#include <cassert>
using namespace std;

int next(int i) {

	int ret = 0;
	while (i) {

		int res = i % 10;
		i = i / 10;
		ret += res * res;
	}

	return ret;
}

/* adapt the Floyd Cycle detection algorithm */

bool isHappy(int n) {

	int fast = next(next(n));
	int slow = next(n);

	while (fast != slow) {
		fast = next(next(fast));
		slow = next(slow);
	}
	return fast == 1;
}

int main()
{
	int n = 19;
	bool ans = true;
	bool ret = isHappy(n);
	assert(ret == ans);
	return 0;
}
