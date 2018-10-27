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

string removeDuplicateLetters(string s) {

	vector<int> freq(256, 0);
	for (auto c : s)
		freq[c]++;

	string ret = "0";
	vector<bool> visited(256, false);

	for (auto c : s) {
		freq[c]--;
		if (visited[c]) continue;
		while (c < ret.back() && freq[ret.back()]) {
			visited[ret.back()] = false;
			ret.pop_back();
		}
		ret.push_back(c);
		visited[c] = true;
	}
	return ret.substr(1);
}

int main()
{
	string str = "abacb";
	string ans = "abc";
	string ret = removeDuplicateLetters(str);
	assert(ret == ans);
	return 0;
}
