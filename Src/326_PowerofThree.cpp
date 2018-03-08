/* Given an integer, write a function to determine if it is a power of three.
*
* Follow up:
* Could you do it without using any loop / recursion?
*/

#include <unordered_set>
#include <cassert>
using namespace std;

bool isPowerOfThree_Sln1(int n) {
	if (n > 1)
		while (n % 3 == 0)
			n = n / 3;
	return n == 1;
}

bool isPowerOfThree_Sln2(int n) {
	unordered_set<int> p3HashSet = { 1, 3, 9, 27, 81, 243, 729, 2187, 6561,
									 19683, 59049, 177147, 531441, 1594323, 4782969,
									 14348907, 43046721, 129140163, 387420489, 1162261467 };

	return p3HashSet.find(n) != p3HashSet.end();
}

bool isPowerOfThree_Sln3(int n) {
	return n > 0 && (1162261467 % n == 0);
}

int main()
{
	bool ret1 = isPowerOfThree_Sln1(243);
	assert(ret1 == true);

	bool ret2 = isPowerOfThree_Sln2(243);
	assert(ret2 == true);

	bool ret3 = isPowerOfThree_Sln3(243);
	assert(ret3 == true);
	return 0;

}
