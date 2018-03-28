/* Given a string, find the first non-repeating character in it and return it's
* index. If it doesn't exist, return -1.
*
* Examples:
*
* s = "leetcode"
* return 0.
*
* s = "loveleetcode",
* return 2.
* Note: You may assume the string contain only lowercase letters.
*/

#include <string>
#include <vector>
#include <cassert>
using namespace std;

int firstUniqChar(string s) {

	vector<int> numtbl(26, 0);
	for (auto c : s)
		numtbl[c - 'a']++;

	for (auto i = 0; i<s.length(); i++)
		if (numtbl[s[i] - 'a'] == 1)
			return i;

	return -1;

}

int main()
{
	string s = "leetcode";
	int ans = 0;
	int ret = firstUniqChar(s);
	assert(ret == ans);
	return 0;
}
