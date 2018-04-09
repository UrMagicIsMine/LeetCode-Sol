/* Given two strings s and t, determine if they are isomorphic.
*
* Two strings are isomorphic if the characters in s can be replaced to get t.
*
* All occurrences of a character must be replaced with another character while
* preserving the order of characters. No two characters may map to the same
* character but a character may map to itself.
*
* For example,
* Given "egg", "add", return true.
* Given "foo", "bar", return false.
* Given "paper", "title", return true.
* Note:
* You may assume both s and t have the same length.
*/

#include <vector>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <cassert>
using namespace std;

bool isIsomorphic(string s, string t) {

	unordered_map<char, char> c_map;
	unordered_set<char> c_mapped;
	for (int i = 0; i < s.length(); i++) {

		if (c_map.find(s[i]) == c_map.end()) {

			if (c_mapped.find(t[i]) != c_mapped.end())
				return false;
			c_map[s[i]] = t[i];
			c_mapped.insert(t[i]);
			continue;
		}
		if (c_map[s[i]] != t[i])
			return false;
	}
	return true;
}

int main()
{
	string s = "egg", t = "add";
	int ans = true;
	bool ret1 = isIsomorphic(s, t);
	assert(ret1 == ans);
	return 0;
}
