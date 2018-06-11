/*
Given a string S, check if the letters can be rearranged so that two characters
that are adjacent to each other are not the same.

If possible, output any possible result.  If not possible, return the empty string.

Example 1:

Input: S = "aab"
Output: "aba"
Example 2:

Input: S = "aaab"
Output: ""
Note:

S will consist of lowercase letters and have length in range [1, 500].
*/

#include <vector>
#include <string>
#include <set>
#include <queue>
#include <algorithm>
#include <functional>
#include <cassert>
using namespace std;


/*
sort
*/

string reorganizeString(string S) {
	int N = S.length();
	vector<int> strFreq(26, 0);
	for (auto s : S)
		strFreq[s - 'a']++;

	vector<pair<int, char>> strMap;
	for (int i = 0; i < 26; i++) {
		if (strFreq[i] >(N + 1) / 2)
			return "";
		if (strFreq[i])
			strMap.emplace_back(strFreq[i], 'a' + i);
	}
	sort(strMap.rbegin(), strMap.rend());
	string str;
	for (auto p : strMap)
		str += string(p.first, p.second);

	int cnt = 0, i = 0, j = (N + 1) / 2;
	string ret;
	ret.reserve(N);
	while (ret.size() < N) {
		if (cnt & 1)
			ret.push_back(str[j++]);
		else
			ret.push_back(str[i++]);
		cnt++;
	}
	return ret;

}

int main()
{
	string sz = "aab", ans = "aba";
	string ret = reorganizeString(sz);
	assert(ret == ans);
	return 0;
}
