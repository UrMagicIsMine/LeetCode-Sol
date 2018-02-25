/* X is a good number if after rotating each digit individually by 180 degrees,
* we get a valid number that is different from X. A number is valid if each digit
* remains a digit after rotation. 0, 1, and 8 rotate to themselves; 2 and 5 rotate
* to each other; 6 and 9 rotate to each other, and the rest of the numbers do not
* rotate to any other number.
*
* Now given a positive number N, how many numbers X from 1 to N are good?
*
* Example:
* Input: 10
* Output: 4
* Explanation:
* There are four good numbers in the range [1, 10] : 2, 5, 6, 9.
* Note that 1 and 10 are not good numbers, since they remain unchanged after rotating.
* Note:
*
* N  will be in range [1, 10000].
*/

#include <string>
#include <algorithm>
#include <cassert>
using namespace std;

bool _isGoodNum(int i) {

	string sz = to_string(i);
	for (int i = 0; i < sz.length(); i++)
	{
		static string map = "0153429786";
		if (sz[i] == '3' || sz[i] == '4' || sz[i] == '7')
			return false;
		sz[i] = map[sz[i] - '0'];
	}
	int ir = stoi(sz);
	return i != ir;
}

int rotatedDigits(int N) {
	int cnt = 0;
	for (int i = 0; i <= N; i++)
		if (_isGoodNum(i))
			cnt++;
	return cnt;
}

int main()
{
	int ret = rotatedDigits(980);
	assert(ret == 303);
	return 0;
}
