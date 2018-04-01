/* Sometimes people repeat letters to represent extra feeling, such as "hello"
* -> "heeellooo", "hi" -> "hiiii".  Here, we have groups, of adjacent letters
* that are all the same character, and adjacent characters to the group are
* different.  A group is extended if that group is length 3 or more, so "e" and
* "o" would be extended in the first example, and "i" would be extended in the
* second example.  As another example, the groups of "abbcccaaaa" would be "a",
* "bb", "ccc", and "aaaa"; and "ccc" and "aaaa" are the extended groups of that
* string.
*
* For some given string S, a query word is stretchy if it can be made to be equal
* to S by extending some groups.  Formally, we are allowed to repeatedly choose
* a group (as defined above) of characters c, and add some number of the same
* character c to it so that the length of the group is 3 or more.  Note that we
* cannot extend a group of size one like "h" to a group of size two like "hh" -
* all extensions must leave the group extended - ie., at least 3 characters long.
*
* Given a list of query words, return the number of words that are stretchy.
*
* Example:
* Input:
* S = "heeellooo"
* words = ["hello", "hi", "helo"]
* Output: 1
* Explanation:
* We can extend "e" and "o" in the word "hello" to get "heeellooo".
* We can't extend "helo" to get "heeellooo" because the group "ll" is not extended.
* Notes:
*
* 0 <= len(S) <= 100.
* 0 <= len(words) <= 100.
* 0 <= len(words[i]) <= 100.
* S and all words in words consist only of lowercase letters
*/

#include <string>
#include <vector>
#include <cassert>
using namespace std;

int expressiveWords(string S, vector<string>& words) {

	vector<pair<char, int>> sinfo;

	for (int i = 0; i<S.length(); ) {
		int j = i;
		while (j < S.length() - 1 && S[j] == S[j + 1])
			j++;
		sinfo.push_back(make_pair(S[i], j - i + 1));
		i = j + 1;
	}

	int ret = 0;

	for (auto &w : words) {
		bool suc = true;
		int c = 0;
		for (int i = 0; i < w.length(); ) {
			int j = i;
			while (j < w.length() - 1 && w[j] == w[j + 1])
				j++;

			int num = j - i + 1;
			if (sinfo[c].first == w[i]) {
				int tarnum = sinfo[c].second;
				bool ext = ((num == tarnum && tarnum < 3) || (num <= tarnum && tarnum >= 3));
				if (ext == false) {
					suc = false;
					break;
				}

			}
			else {
				suc = false;
				break;
			}
			c++;
			i = j + 1;
		}
		if (suc && c == sinfo.size())
			ret++;
	}
	return ret;
}

int main()
{
	string S = "heeellooo";
	vector<string> words = { "hello", "hi", "helo" };
	int ans = 1;
	int ret = expressiveWords(S, words);
	assert(ret == ans);
	return 0;
}
