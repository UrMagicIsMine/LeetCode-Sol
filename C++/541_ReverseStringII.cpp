/* Given a string and an integer k, you need to reverse the first k characters
* for every 2k characters counting from the start of the string. If there are
* less than k characters left, reverse all of them. If there are less than 2k
* but greater than or equal to k characters, then reverse the first k characters
* and left the other as original.
Example:
Input: s = "abcdefg", k = 2
Output: "bacdfeg"
Restrictions:
The string consists of lower English letters only.
Length of the given string and k will in the range [1, 10000]
*/

#include <string>
#include <algorithm>
#include <cassert>
using namespace std;

string reverseStr(string s, int k) {
	int N = s.size();
	if (k <= 1 || N == 0)
		return s;

	int pos1 = 0;
	int pos2 = 2 * k;
	while (pos1 < N) {
		int i = pos1;
		int j = min(pos1 + k - 1, N - 1);
		for (; i<j; i++, j--)
			swap(s[i], s[j]);

		pos1 = pos2;
		pos2 += 2 * k;
	}
	return s;
}

int main()
{
	string ret = reverseStr("abcdefg", 2);
	string ans = "bacdfeg";
	assert(ret == ans);
	return 0;
}
