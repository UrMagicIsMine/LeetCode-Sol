/*
Given two strings s and t, determine if they are both one edit distance apart.

Note:

There are 3 possiblities to satisify one edit distance apart:

Insert a character into s to get t
Delete a character from s to get t
Replace a character of s to get t
Example 1:

Input: s = "ab", t = "acb"
Output: true
Explanation: We can insert 'c' into s to get t.
Example 2:

Input: s = "cab", t = "ad"
Output: false
Explanation: We cannot get t from s by only one step.
Example 3:

Input: s = "1203", t = "1213"
Output: true
Explanation: We can replace '0' with '1' to get t.
*/

#include <string>
#include <cassert>

using namespace std;

bool isOneEditDistance(string s, string t) {
	int m = s.length(), n = t.length();
	//if(m == 0 && n == 0) return false;
	string & s_str = m > n ? t : s;
	string & l_str = m > n ? s : t;

	if (l_str.length() - s_str.length() > 1)
		return false;

	int cnt = 0;
	bool misMatch = false;
	for (int i = 0; i < s_str.length(); i++) {
		if (s_str[i] != l_str[i]) {
			if (m == n) {
				s_str[i] = l_str[i];
			}
			else {
				s_str.insert(s_str.begin() + i, l_str[i]);
			}
			misMatch = true;
			break;
		}
	}
	return (!misMatch && s_str.length() + 1 == l_str.length())
		|| (misMatch && s_str == l_str);
}

int main(){
  string s = "1203", t = "1213";
  bool ret = isOneEditDistance(s, t);
  bool ans = true;
  assert(ret == ans);
}
