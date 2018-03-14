/* Given a List of words, return the words that can be typed using letters of
* alphabet on only one row's of American keyboard like the image below.
* Example 1:
* Input: ["Hello", "Alaska", "Dad", "Peace"]
* Output: ["Alaska", "Dad"]
* Note:
* You may use one character in the keyboard more than once.
* You may assume the input string will only contain letters of alphabet.
*/

#include <string>
#include <vector>
#include <cassert>
using namespace std;

vector<string> findWords(vector<string>& words) {

	int charRow[26] = { 1,2,2,1,0,1,1,1,0,1,1,1,2,2,0,0,0,0,1,0,0,2,0,2,0,2 };
	vector<string> resl;
	for (int i = 0; i<words.size(); i++) {
		int row = charRow[tolower(words[i][0]) - 'a'];
		int j = 1;
		for (; j < words[i].size(); j++) {
			if (row != charRow[tolower(words[i][j]) - 'a'])
				break;
		}
		if (j == words[i].size())
			resl.push_back(words[i]);
	}
	return resl;
}

int main()
{
	vector<string> words = { "Hello", "Alaska", "Dad", "Peace" };
	vector<string> ans = { "Alaska", "Dad" };

	vector<string> ret = findWords(words);
	assert(ret == ans);
	return 0;
}
