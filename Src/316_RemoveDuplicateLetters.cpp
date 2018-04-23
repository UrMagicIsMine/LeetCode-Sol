/* Given a string which contains only lowercase letters, remove duplicate letters
* so that every letter appear once and only once. You must make sure your result
* is the smallest in lexicographical order among all possible results.
*
* Example:
* Given "bcabc"
* Return "abc"
*
* Given "cbacdcbc"
* Return "acdb"
*/

#include <vector>
#include <numeric>
#include <algorithm>
#include <cassert>
using namespace std;

/*
Given the string s, the greedy choice (i.e., the leftmost letter in the answer)
is the smallest s[i] such that the suffix s[i … ] contains all the unique letters
(Note that, when there are more than one smallest s[i]'s, we choose the leftmost one.
Why? Simply consider the example: “abcacb”.)

After determining the greedy choice s[i], we get a new string s’ from s by
  removing all letters to the left of s[i],
  removing all s[i]'s from s.
We then recursively solve the problem w.r.t.s’.

The runtime is O(26 * n) = O(n).
*/
string _remove(string& str, char c) {
	string ret;
	for (auto t : str) {
		if (t != c)
			ret.push_back(t);
	}
	return ret;
}

string removeDuplicateLetters(string s) {
	vector<int> cnt(26,0);
	int pos = 0;
	for (auto c : s)
		cnt[c - 'a']++;

	for (int i = 0; i < s.length(); i++) {
		if(s[i] < s[pos])
			pos = i;
		if (--cnt[s[i] - 'a'] == 0)
			break;
	}

	if (s.length() == 0)
		return "";
	else {
		string str = _remove(s.substr(pos + 1), s[pos]);
		string tmp = removeDuplicateLetters(str);
		return s[pos] + tmp;
	}

}

int main()
{
	string str = "abacb";
	string ans = "abc";
	string ret = removeDuplicateLetters(str);
	assert(ret == ans);
	return 0;
}
