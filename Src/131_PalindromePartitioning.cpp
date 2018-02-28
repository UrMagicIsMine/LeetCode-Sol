/* Given a string s, partition s such that every substring of the partition is a palindrome.
*
* Return all possible palindrome partitioning of s.
*
* For example, given s = "aab",
* Return
*
* [
*   ["aa","b"],
*   ["a","a","b"]
* ]
*/

#include <vector>
#include <queue>
#include <cassert>
using namespace std;

bool _isSubstrPalidrome(const string& sz, int beg, int end) {

	for (int i = beg, j = end; i < j; i++, j--) {
		if (sz[i] != sz[j])
			return false;
	}
	return true;
}

void _partition(const string &sz, int N, vector<vector<string>>& resl, vector<string> & cur, int idx) {

	if (idx == N) {
		resl.push_back(cur);
	}
	else {
		for (int i = idx; i<N; i++) {
			if (_isSubstrPalidrome(sz, idx, i)) {
				cur.push_back(sz.substr(idx, i - idx + 1));
				_partition(sz, N, resl, cur, i + 1);
				cur.pop_back();
			}
		}
	}
	return;
}

vector<vector<string>> partition(string s) {

	vector<vector<string>> resl;
	int N = s.size();
	if (N == 0)
		return resl;
	vector<string> cur;
	_partition(s, N, resl, cur, 0);
	return resl;
}

int main()
{
  string sz = "abbab";
	vector<vector<string>> ret = partition(sz);
	vector<vector<string>> ans = { { "a", "b", "b", "a", "b" },
								   { "a", "b", "bab" },
								   { "a", "bb", "a", "b" },
								   { "abba", "b" } };

	assert(ret == ans);
	return 0;
}
