/* Write a function to find the longest common prefix string amongst an array
* of strings.
*/

#include <vector>
#include <string>
#include <algorithm>
#include <cassert>
using namespace std;

string longestCommonPrefix(vector<string>& strs) {

	int N = INT_MAX;
	if (strs.size() == 0)
		return string("");

	if (strs.size() == 1)
		return strs[0];

  /* find the shortest length of string in the vector */
	for (int i = 0; i < strs.size(); i++) {
		N = min<int>(strs[i].size(), N);
	}

  /* do a matrix-like comparison */
	for (int j = 0; j < N; j++) {
		for (int i = 1; i < strs.size(); i++) {
			if (strs[0][j] != strs[i][j]) {
				return strs[0].substr(0, j);
			}
		}
	}
	return strs[0].substr(0, N);
}

int main()
{
	vector<string> strs = { "Hello World", "Hello" };
	string ans = "Hello";
	string ret = longestCommonPrefix(strs);
	assert(ret == ans);
	return 0;
}
