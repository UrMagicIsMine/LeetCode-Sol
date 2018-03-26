/* Given an encoded string, return it's decoded string.
*
* The encoding rule is: k[encoded_string], where the encoded_string inside the
* square brackets is being repeated exactly k times. Note that k is guaranteed
* to be a positive integer.
*
* You may assume that the input string is always valid; No extra white spaces,
* square brackets are well-formed, etc.
*
* Furthermore, you may assume that the original data does not contain any digits
* and that digits are only for those repeat numbers, k. For example, there won't
* be input like 3a or 2[4].
*
* Examples:
*
* s = "3[a]2[bc]", return "aaabcbc".
* s = "3[a2[c]]", return "accaccacc".
* s = "2[abc]3[cd]ef", return "abcabccdcdcdef".
*
*/

#include <vector>
#include <stack>
#include <string>
#include <cctype>
#include <cassert>
using namespace std;

string decodeString(string s) {

	stack<pair<int, string>> szStack;
	string resl;
	int num = 0;
	for (int i = 0; i < s.length(); ) {

		if (isdigit(s[i])) {

			/* get the num before [ */
			int j = 1;
			while (isdigit(s[i + j]))
				j++;

			num = stoi(s.substr(i, j));

			i = i + j;
		}
		else if (s[i] == '[') {
			i++;
			szStack.push(make_pair(num, ""));
		}
		else if (s[i] == ']') {

			pair<int, string>& sTop = szStack.top();
			string sz;
			while (sTop.first--)
				sz += sTop.second;

			szStack.pop();
			if (!szStack.empty())
				szStack.top().second += sz;
			else
				resl += sz;
			i++;
		}
		else if (isalpha(s[i])) {
			if (!szStack.empty())
				szStack.top().second += s[i];
			else
				resl += s[i];
			i++;
		}
	}
	return resl;
}

string decodeString(string s, int& i) {

	string resl;

	while (i < s.length() && s[i] != ']') {

		if (isalpha(s[i]))
			resl += s[i++];
		else {

			int n = 0;
			while (isdigit(s[i])) {
				n *= 10;
				n += s[i++] - '0';
			}

			i++;
			string sz = decodeString(s, i);
			i++;

			while (n--)
				resl += sz;
		}

	}
	return resl;
}

string decodeString_RCV(string s) {
	int i = 0;
	return decodeString(s, i);
}

int main()
{
	string s1 = "3[z]2[2[y]pq4[2[jk]e1[f]]]ef";
	string ans1 = "zzzyypqjkjkefjkjkefjkjkefjkjkefyypqjkjkefjkjkefjkjkefjkjkefef";
	string ret1 = decodeString(s1);
	assert(ret1 == ans1);

	string s2 = "3[a]2[bc]";
	string ans2 = "aaabcbc";
	string ret2 = decodeString_RCV(s2);
	assert(ret2 == ans2);

	return 0;
}
