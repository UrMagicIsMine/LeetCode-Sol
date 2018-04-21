/* Given a list of unique words, find all pairs of distinct indices (i, j) in the
* given list, so that the concatenation of the two words, i.e. words[i] + words[j]
* is a palindrome.
*
* Example 1:
* Given words = ["bat", "tab", "cat"]
* Return [[0, 1], [1, 0]]
* The palindromes are ["battab", "tabbat"]
* Example 2:
* Given words = ["abcd", "dcba", "lls", "s", "sssll"]
* Return [[0, 1], [1, 0], [3, 2], [2, 4]]
* The palindromes are ["dcbaabcd", "abcddcba", "slls", "llssssll"]
*/

#include <vector>
#include <algorithm>
#include <unordered_map>
#include <cassert>
using namespace std;

bool isPal(string& str) {
	int i = 0, j = str.length() - 1;
	while (i < j) {
		if (str[i++] != str[j--])
			return false;
	}
	return true;
}

vector<vector<int>> palindromePairs(vector<string>& words) {
	int N = words.size();
	unordered_map<string, int> dict;

  // Traverse the array, build map. Key is the reversed string, value is index in array
	for (int i = 0; i < N; i++) {
		string str = words[i];
		reverse(str.begin(), str.end());
		dict[str] = i;
	}
	vector<vector<int>> resl;

  /* Partition the word into left and right, and see
  1) if there exists a candidate in map equals the left side of current word,
  and right side of current word is palindrome, so concatenate(current word,
  candidate) forms a pair: left | right | candidate.
  2) same for checking the right side of current word: candidate | left | right.
  */

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < words[i].size(); j++) {
			string sleft = words[i].substr(0, j);
			string srght = words[i].substr(j, words[i].size() - j);
			auto it = dict.find(sleft);
			if (it != dict.end() && isPal(srght) && i != it->second)
				resl.push_back({ i, it->second });
			it = dict.find(srght);
			if (it != dict.end() && isPal(sleft) && i != it->second)
				resl.push_back({ it->second, i });
		}

    // handle speical cases, where "" exists
		if (words[i] == "") {
			for (int k = 0; k < N; k++) {
				if (i != k && isPal(words[k]))
					resl.push_back({ i, k });
			}
		}
	}
	return resl;
}

int main()
{
	vector<string> words = { {"abcd", "dcba", "lls", "s", "sssll" } };
	vector<vector<int>> ret = palindromePairs(words);
	vector<vector<int>> ans = {{1, 0}, { 0, 1 }, { 3, 2 }, { 2, 4 }};
	assert(ret == ans);
	return 0;
}
