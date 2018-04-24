/* Given two non-negative integers num1 and num2 represented as strings, return
* the product of num1 and num2, also represented as a string.
*
* Example 1:
*
* Input: num1 = "2", num2 = "3"
* Output: "6"
* Example 2:
*
* Input: num1 = "123", num2 = "456"
* Output: "56088"
* Note:
*
* The length of both num1 and num2 is < 110.
* Both num1 and num2 contain only digits 0-9.
* Both num1 and num2 do not contain any leading zero, except the number 0 itself.
* You must not use any built-in BigInteger library or convert the inputs to integer
* directly.
*/

#include <vector>
#include <string>
#include <algorithm>
#include <cassert>
using namespace std;

string multiply(string num1, string num2) {

	if (num1 == "0" || num2 == "0")
		return "0";

	int N1 = num1.size(), N2 = num2.size();
	string mul(N1 + N2, '0');

	for (int i = N1 - 1; i >= 0; i--) {
		for (int j = N2 - 1; j >= 0; j--) {

			int k = N1 - 1 + N2 - 1 - i - j;
			int num = ((num1[i] - '0') * (num2[j] - '0'));

			int adv = 0, l = 0;
			while (num || adv) {
				int tmp = num % 10 + (mul[k + l] - '0') + adv;
				num = num / 10;
				if (tmp >= 10) {
					tmp -= 10;
					adv = 1;
				}
				else
					adv = 0;
				mul[k + l] = '0' + tmp;
				l++;
			}
		}
	}

	int i = N1 + N2 - 1;
	while (mul[i] == '0')
		i--;

	string ret = mul.substr(0, i + 1);
	reverse(ret.begin(), ret.end());
	return ret;

}

int main()
{
	string num1 = "123", num2 = "456";
	string ans = "56088";
	string ret = multiply(num1, num2);
	assert(ret == ans);
	return 0;
}
