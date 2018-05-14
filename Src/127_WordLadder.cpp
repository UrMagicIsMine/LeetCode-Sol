/* Given two words (beginWord and endWord), and a dictionary's word list,
* find the length of shortest transformation sequence from beginWord to
* endWord, such that:

* Only one letter can be changed at a time.
* Each transformed word must exist in the word list. Note that beginWord
* is not a transformed word.
* For example,
*
* Given:
* beginWord = "hit"
* endWord = "cog"
* wordList = ["hot","dot","dog","lot","log","cog"]
* As one shortest transformation is "hit" -> "hot" -> "dot" -> "dog" -> "cog",
* return its length 5.

* Note:
* -- Return 0 if there is no such transformation sequence.
* -- All words have the same length.
* -- All words contain only lowercase alphabetic characters.
* -- You may assume no duplicates in the word list.
* -- You may assume beginWord and endWord are non-empty and are not the same.
*
*/
#include <vector>
#include <string>
#include <set>
#include <queue>

using namespace std;

/***********************************************************************/

/* determine if s1 and s2 only diff by 1 character */
bool _is1CharDiffStr(const string & s1, const string & s2) {

	int NumDiffChar = 0;
	for (int i = 0; i < s1.size(); i++) {
		if (s1[i] != s2[i])
			NumDiffChar++;
		if (NumDiffChar == 2)
			return false;
	}
	return true;
}

/* be careful about erasing from associative container */
void _getNextStrQue(const string & bWord, set<string>& wordSet, queue<string> &QueueSet) {

	for (auto it = wordSet.begin(); it != wordSet.end(); /*do nothing*/) {

		if (_is1CharDiffStr(*it, bWord)) {
			QueueSet.push(*it);
			wordSet.erase(it++);
		}
		else
			++it;
	}
	return;
}

int ladderLength(string beginWord, string endWord, vector<string>& wordList) {

	set<string> wordSet(wordList.begin(), wordList.end());
	queue<string> strQueue;
	_getNextStrQue(beginWord, wordSet, strQueue);

	int level = 1;
	while (!strQueue.empty()) {
		level++; /* level up after finishing searching each level */
		int N = strQueue.size();

		/* Broad-search current level first */
		while (N--) {

			const string & str = strQueue.front();
			if (str == endWord)
				return level;

			_getNextStrQue(str, wordSet, strQueue);
			strQueue.pop();
		}
	}
	return 0;
}

int ladderLength_Sln2(string beginWord, string endWord, vector<string>& wordList) {

		unordered_set<string> candWords(wordList.begin(), wordList.end());

		if(candWords.find(endWord) == candWords.end())
				return 0;

	unordered_set<string> bSetWords, eSetWords;
	bSetWords.insert(beginWord);
	eSetWords.insert(endWord);
	int dist = 2;
	while (!bSetWords.empty()) {

		int N1 = bSetWords.size(), N2 = eSetWords.size();
		if (N1 > N2)
			swap(bSetWords, eSetWords);

		unordered_set<string> nSetWords;
		for (auto it = bSetWords.begin(); it != bSetWords.end(); it++) {

			string str = *it;
			int N = str.length();
			for (int i = 0; i < N; i++) {
				char p = str[i];
				for (char c = 'a'; c <= 'z'; c++) {
					if (p != c) {
						str[i] = c;

						if (eSetWords.find(str) != eSetWords.end())
							return dist;

						if (candWords.find(str) != candWords.end()) {
							nSetWords.insert(str);
							candWords.erase(str);
						}
						str[i] = p;
					}
				}
			}

		}
		dist++;
		swap(bSetWords, nSetWords);
	}
		return 0;
}

/***********************************************************************/

int main()
{
	vector<string> wordList = { "hot","dot","dog","lot","log","cog" };
	int ret = ladderLength("hit", "cog", wordList);
	return 0;
}
