/* Given a non-empty string s and a dictionary wordDict containing a list of
* non-empty words, determine if s can be segmented into a space-separated
* sequence of one or more dictionary words. You may assume the dictionary does
* not contain duplicate words.
*
* For example, given
* s = "leetcode",
* dict = ["leet", "code"].
*
* Return true because "leetcode" can be segmented as "leet code".
*
*/

#include <vector>
#include <unordered_set>
#include <cassert>
using namespace std;

/******************************************************************************/
/* Solution 1: backtracing solution, recursively find solution, run-time exceed
 * limit in OJ
 */

bool _wordBreakFunc(const string &s, int N, int idx, const unordered_set<string>& wordDict) {

	if (idx == N) {
		return true;
	}
	else {
		for (int i = idx; i< N; i++) {
			if (wordDict.find(s.substr(idx, i - idx + 1)) != wordDict.end()) {
        /* if return true path from here */
				if (_wordBreakFunc(s, N, i + 1, wordDict))
					return true;
			}
		}
	}
	return false;
}

bool wordBreak_BT(string s, vector<string>& wordDict) {

	unordered_set<string> wordDicthash(wordDict.begin(), wordDict.end());
	return _wordBreakFunc(s, s.size(), 0, wordDicthash);

}

/******************************************************************************/
/* Solution 2: Dynamic programming solution, DP array DP[i] stores if [0,i] can
 * be decomposed into sub strings in wordDict, worst case run-time O(N^2)
 */

bool wordBreak_DP(string s, vector<string>& wordDict) {

	if (wordDict.size() == 0)
		return false;

	unordered_set<string> wordDicthash(wordDict.begin(), wordDict.end());
	int N = s.size();
	vector<bool> dpFlag(N + 1, false);
	dpFlag[0] = true;

	for (int i = 1; i <= N; i++) {
		for (int j = i - 1; j >= 0; j--) {
			if (dpFlag[j] && wordDicthash.find(s.substr(j, i - j)) != wordDicthash.end()) {
				dpFlag[i] = true;
				break;
			}
		}
	}
	return dpFlag[N];
}

int main()
{
	string s = "wordDictcontaining";
	vector<string> wordDict = { "word","con","ning","tai","Dict"};
	bool ret_BT = wordBreak_BT(s, wordDict);
	assert(ret_BT == true);
	bool ret_DP = wordBreak_DP(s, wordDict);
	assert(ret_DP == true);
	return 0;
}
