/* Given a non-negative integer num, repeatedly add all its digits until the
* result has only one digit.
*
* For example:
*
* Given num = 38, the process is like: 3 + 8 = 11, 1 + 1 = 2. Since 2 has only
* one digit, return it.
*
* Follow up:
* Could you do it without any loop/recursion in O(1) runtime?
*/

#include <cassert>
using namespace std;

int addDigits_Sln1(int num) {

	while (num > 9) {
		int sum = 0;
		while (num) {
			sum += num % 10;
			num = num / 10;
		}
		num = sum;
	}
	return num;
}

/*
https://en.wikipedia.org/wiki/Digital_root#Congruence_formula
*/

int addDigits_Sln2(int num) {
	return 1 + (num - 1) % 9;
}

int main()
{
	int num = 1234;
	int ans = 1;
	int ret1 = addDigits_Sln1(num);
	assert(ret1 == ans);

	int ret2 = addDigits_Sln2(num);
	assert(ret2 == ans);
	return 0;
}
