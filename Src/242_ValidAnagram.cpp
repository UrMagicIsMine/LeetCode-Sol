/* Given two strings s and t, write a function to determine if t is an anagram of s.

For example,
s = "anagram", t = "nagaram", return true.
s = "rat", t = "car", return false.

Note:
You may assume the string contains only lowercase alphabets.
*
*/

#include <vector>
#include <cassert>
using namespace std;

bool isAnagram(string s, string t) {
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

int main()
{
	string s = "anagram", t = "nagaram";
	bool ans = true;
	bool ret = isAnagram(s, t);
	assert(ret == ans);
	return 0;
}
