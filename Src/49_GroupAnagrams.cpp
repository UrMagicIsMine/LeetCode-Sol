/* Given an array of strings, group anagrams together.

Example:

Input: ["eat", "tea", "tan", "ate", "nat", "bat"],
Output:
[
  ["ate","eat","tea"],
  ["nat","tan"],
  ["bat"]
]
Note:

All inputs will be in lowercase.
The order of your output does not matter.
*/

#include <vector>
#include <string>
#include <unordered_map>
#include <algorithm>
#include <cassert>
using namespace std;

vector<vector<string>> groupAnagrams(vector<string>& strs) {

	unordered_map<string, vector<string>> hashtable;
	for (auto s : strs) {
		string sz = s;
		sort(s.begin(), s.end());
		hashtable[s].emplace_back(sz);
	}
	vector<vector<string>> ret;
	for (auto vs : hashtable)
		ret.emplace_back(vs.second);
	return ret;
}

int main()
{
	vector<string> strs = { {"eat","tea","tan","ate","nat","bat"} };
	vector<vector<string>> ans = { { "eat","tea","ate" }, { "tan","nat" }, { "bat" } };
	vector<vector<string>> ret = groupAnagrams(strs);
	assert(ret == ans);
	return 0;
}
