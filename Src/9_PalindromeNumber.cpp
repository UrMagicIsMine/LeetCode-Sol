/* Determine whether an integer is a palindrome. An integer is a palindrome when
* it reads the same backward as forward.
*
* Example 1:
*
* Input: 121
* Output: true
* Example 2:
*
* Input: -121
* Output: false
* Explanation: From left to right, it reads -121. From right to left, it becomes
* 121-. Therefore it is not a palindrome.
* Example 3:
*
* Input: 10
* Output: false
* Explanation: Reads 01 from right to left. Therefore it is not a palindrome.
*/

#include <string>
#include <vector>
#include <numeric>
#include <algorithm>
#include <cassert>
using namespace std;

bool isPalindrome_Sln1(int x) {

	/* When x < 0, x is not a palindrome.
	* Also if the last digit of the number is 0, in order to be a palindrome,
	* the first digit of the number also needs to be 0.
	* Only 0 satisfy this property.
	*/

	if (x < 0 || (x != 0 && x % 10 == 0))
		return false;

	/* reverse the integer, do not need to consider overflow, false anyway */
	int num = 0, tmp = x;
	while (tmp) {
		num = num * 10 + tmp % 10;
		tmp = tmp / 10;
	}

	return num == x;
}

bool isPalindrome_Sln2(int x) {

	if (x < 0 || (x != 0 && x % 10 == 0))
		return false;

	/* reverse half of the integer, do not need to consider overflow */
	int num = 0;
	while (num < x) {
		num = num * 10 + x % 10;
		x = x / 10;
	}

	/* When the length is an odd number, we can get rid of the middle digit by
  * revertedNumber/10, For example when the input is 12321, at the end of the
  * while loop we get x = 12, revertedNumber = 123, since the middle digit doesn't
  * matter in palidrome(it will always equal to itself), we can simply get rid of
  * it.
  */

	return num == x || num / 10 == x;
}

int main()
{
	int x = 123321;
	bool ans = true;
	bool ret1 = isPalindrome_Sln1(x);
	assert(ret1 == ans);
  bool ret2 = isPalindrome_Sln2(x);
	assert(ret2 == ans);
	return 0;
}
