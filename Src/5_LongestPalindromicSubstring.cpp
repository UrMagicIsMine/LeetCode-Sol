/* Given a string s, find the longest palindromic substring in s. You may assume
* that the maximum length of s is 1000.
*
* Example 1:
*
* Input: "babad"
* Output: "bab"
* Note: "aba" is also a valid answer.
* Example 2:
*
* Input: "cbbd"
* Output: "bb"
*/

#include <string>
#include <algorithm>
#include <cassert>
using namespace std;

/*
We observe that a palindrome mirrors around its center.
Therefore, a palindrome can be expanded from its center,
and there are only 2n - 1 such centers.

You might be asking why there are 2n - 1 but not n centers?
The reason is the center of a palindrome can be in between two letters.
Such palindromes have even number of letters (such as "abba")
and its center are between the two "bb"s.
*/

int palLength(const string& s, int i, int j) {
	int Len = 0;
	while (i >= 0 && j < s.size()) {
		if (s[i] == s[j]) {
			Len += (i == j ? 1 : 2);
			i--;
			j++;
		}
		else
			break;
	}
	return Len;
}

string longestPalindrome(string s) {

	if (s.size() == 0)
		return "";

	int maxLen = 0, imid = 0;;
	for (int i = 0; i < s.size(); i++) {
		int Len1 = palLength(s, i, i);
		int Len2 = palLength(s, i, i + 1);
		if (Len1 > maxLen || Len2 > maxLen) {
			maxLen = max(Len1, Len2);
			imid = i;
		}
	}

	if (maxLen & 1)
		return s.substr(imid - maxLen / 2, maxLen);
	else
		return s.substr(imid - maxLen / 2 + 1, maxLen);
}

int main()
{
	string s = "babad";
	string ans = "bab";
	string ret = longestPalindrome(s);
	assert(ret == ans);
	return 0;
}
