/* Given two binary strings, return their sum (also a binary string).

The input strings are both non-empty and contains only characters 1 or 0.

Example 1:

Input: a = "11", b = "1"
Output: "100"
Example 2:

Input: a = "1010", b = "1011"
Output: "10101"
*/

#include <string>
#include <vector>
#include <algorithm>
#include <functional>
#include <cassert>
using namespace std;

string addBinary(string a, string b) {
	int la = a.length(), lb = b.length(), carry = 0;
	string ret;
	while (la || lb || carry) {

		int int_a = (la>0) ? a[la - 1] - '0' : 0;
		int int_b = (lb>0) ? b[lb - 1] - '0' : 0;
		int tmp = int_a + int_b + carry;
		if (tmp >1) {
			tmp -= 2;
			carry = 1;
		}
		else
			carry = 0;
		ret = string(1, '0' + tmp) + ret;
		if (la > 0)
			la--;
		if (lb > 0)
			lb--;

	}
	return ret;
}

int main()
{
	string a = "1010", b = "1011";
	string ans = "10101";
	string ret = addBinary(a,b);
	assert(ret == ans);
	return 0;
}
