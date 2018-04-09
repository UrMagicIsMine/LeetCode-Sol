/* Write a program to check whether a given number is an ugly number.
*
* Ugly numbers are positive numbers whose prime factors only include 2, 3, 5. For
* example, 6, 8 are ugly while 14 is not ugly since it includes another prime factor 7.
*
* Note:
*
* 1 is typically treated as an ugly number.
* Input is within the 32-bit signed integer range.
*/

#include <vector>
#include <string>
#include <cassert>
using namespace std;

bool isUgly(int num) {

	if (num <= 0)
		return false;

	while (num != 1) {
		if (num % 2 == 0)
			num = num / 2;
		else if (num % 3 == 0)
			num = num / 3;
		else if (num % 5 == 0)
			num = num / 5;
		else
			return false;
	}
	return true;
}

int main()
{
	int num = 15;
	bool ans = true;
	bool ret = isUgly(num);
	assert(ret == ans);
	return 0;
}
