/* You are given a string, s, and a list of words, words, that are all of the
* same length. Find all starting indices of substring(s) in s that is a
* concatenation of each word in words exactly once and without any intervening
* characters.
*
* Example 1:
*
* Input:
*   s = "barfoothefoobarman",
*   words = ["foo","bar"]
* Output: [0,9]
* Explanation: Substrings starting at index 0 and 9 are "barfoor" and "foobar"
* respectively.
* The output order does not matter, returning [9,0] is fine too.
* Example 2:
*
* Input:
*   s = "wordgoodstudentgoodword",
*   words = ["word","student"]
* Output: []
*/

#include <vector>
#include <unordered_map>
#include <cassert>
using namespace std;

/* We use an unordered_map<string, int> worddict to record the expected times of
* each word and another unordered_map<string, int> seen to record the times we
* have seen. Then we check for every possible position of i. Once we meet an
* unexpected word or the times of some word is larger than its expected times,
* we stop the check. If we finish the check successfully, push i to the result
* indexes.*/

vector<int> findSubstring(string s, vector<string>& words) {

	vector<int> resl;
	if (words.size() == 0)
		return resl;

  // use hash table to record the expected times of each words
	unordered_map<string, int> worddict;
	for (auto &w : words)
		worddict[w]++;

	int strLen = s.length(), wdNum = words.size(), wdLen = words[0].size();

	for (int i = 0; i <= strLen - wdNum * wdLen; i++) {

    // use hash table to record the times we have seen
		unordered_map<string, int> seen;
		int j = i;
		for (; j <= strLen; j += wdLen) {
			string tmp = s.substr(j, wdLen);
			if (worddict.find(tmp) != worddict.end()) {
				seen[tmp]++;
				if (seen[tmp] > worddict[tmp])
					break;
			}
			else
				break;
		}

		if (j == i + wdNum * wdLen)
			resl.push_back(i);

	}
	return resl;
}

int main()
{
	string s = "barfoothefoobarman";
	vector<string> words = { "foo","bar" };
	vector<int> ans = { 0,9 };
	vector<int> ret = findSubstring(s, words);
	assert(ret == ans);
	return 0;
}
