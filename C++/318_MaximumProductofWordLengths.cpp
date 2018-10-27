/* Given a string array words, find the maximum value of length(word[i]) *
* length(word[j]) where the two words do not share common letters. You may assume
*  that each word will contain only lower case letters. If no such two words exist,
* return 0.
*
* Example 1:
* Given ["abcw", "baz", "foo", "bar", "xtfn", "abcdef"]
* Return 16
* The two words can be "abcw", "xtfn".
*
* Example 2:
* Given ["a", "ab", "abc", "d", "cd", "bcd", "abcd"]
* Return 4
* The two words can be "ab", "cd".
*
* Example 3:
* Given ["a", "aa", "aaa", "aaaa"]
* Return 0
* No such pair of words.

*/
#include <bitset>
#include <string>
#include <vector>
#include <algorithm>
#include <cassert>
using namespace std;

/* Solution 1: O(N^2) Complexity */

bool _hasCommCharacter(const string& s1, const string& s2) {
	bitset<26> charbits;

	for (int i = 0; i < s1.length(); i++)
		charbits.set((s1[i] - 'a'), true);

	for (int j = 0; j < s2.length(); j++) {
		if (charbits.test(s2[j] - 'a'))
			return true;
	}
	return false;
}

int maxProduct_Sln1(vector<string>& words) {

	int ret = 0;
	int N = words.size();
	for (int i = 0; i < N; i++) {

		for (int j = i + 1; j < N; j++)
		{
			bool hasComm = _hasCommCharacter(words[i], words[j]);
			if (!hasComm)
				ret = max<int>(ret, words[i].length() * words[j].length());
		}
	}
	return ret;
}

/* Solution 2: Same logic, more compact solution with O(N^2) Complexity */

int maxProduct_Sln2(vector<string>& words) {

	int ret = 0;
	int N = words.size();

	std::vector<int> wBits(N, 0);
	for (int i = 0; i < N; i++) {
		for (int ib = 0; ib < words[i].length(); ib++)
			wBits[i] |= (1 << words[i][ib] - 'a');
	}

	for (int i = 0; i < N; i++) {
		for (int j = i + 1; j < N; j++)
			if (!(wBits[i] & wBits[j]))
				ret = max<int>(ret, words[i].length() * words[j].length());
	}

	return ret;
}

int main()
{
	vector<string> words = { "abcw","baz","foo","bar","xtfn","abcdef" };
	int ans = 16;
	int ret1 = maxProduct_Sln1(words);
	assert(ret1 == ans);

	int ret2 = maxProduct_Sln2(words);
	assert(ret1 == ans);
	return 0;

}
