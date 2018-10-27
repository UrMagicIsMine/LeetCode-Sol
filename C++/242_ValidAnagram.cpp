/* Given two strings s and t, write a function to determine if t is an anagram of s.

For example,
s = "anagram", t = "nagaram", return true.
s = "rat", t = "car", return false.

Note:
You may assume the string contains only lowercase alphabets.
*
*/

#include <vector>
#include <algorithm>
#include <cassert>
using namespace std;

bool isAnagram_HT(string s, string t) {
	if (s.size() != t.size())
		return false;

	vector<int> sVec(26, 0);
	vector<int> tVec(26, 0);
	for (int i = 0; i < s.size(); i++) {
		sVec[s[i] - 'a']++;
		tVec[t[i] - 'a']++;
	}
	return sVec == tVec;
}

bool isAnagram_ST(string s, string t) {
	if (s.size() != t.size())
		return false;
	sort(s.begin(), s.end());
	sort(t.begin(), t.end());
	return s == t;
}

int main()
{
	string s = "anagram", t = "nagaram";
	bool ans = true;
	bool ret1 = isAnagram_HT(s, t);
	assert(ret1 == ans);
	bool ret2 = isAnagram_ST(s, t);
	assert(ret2 == ans);
	return 0;
}
