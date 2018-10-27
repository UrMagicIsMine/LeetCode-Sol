/* Given an array of words and a width maxWidth, format the text such that each
line has exactly maxWidth characters and is fully (left and right) justified.

You should pack your words in a greedy approach; that is, pack as many words as
you can in each line. Pad extra spaces ' ' when necessary so that each line has
exactly maxWidth characters.

Extra spaces between words should be distributed as evenly as possible. If the
number of spaces on a line do not divide evenly between words, the empty slots
on the left will be assigned more spaces than the slots on the right.

For the last line of text, it should be left justified and no extra space is
inserted between words.

Note:

A word is defined as a character sequence consisting of non-space characters only.
Each word's length is guaranteed to be greater than 0 and not exceed maxWidth.
The input array words contains at least one word.
Example 1:

Input:
words = ["This", "is", "an", "example", "of", "text", "justification."]
maxWidth = 16
Output:
[
   "This    is    an",
   "example  of text",
   "justification.  "
]
Example 2:

Input:
words = ["What","must","be","acknowledgment","shall","be"]
maxWidth = 16
Output:
[
  "What   must   be",
  "acknowledgment  ",
  "shall be        "
]
Explanation: Note that the last line is "shall be    " instead of "shall     be",
             because the last line must be left-justified instead of fully-justified.
             Note that the second line is also left-justified becase it contains
             only one word.
Example 3:

Input:
words = ["Science","is","what","we","understand","well","enough","to","explain",
         "to","a","computer.","Art","is","everything","else","we","do"]
maxWidth = 20
Output:
[
  "Science  is  what we",
  "understand      well",
  "enough to explain to",
  "a  computer.  Art is",
  "everything  else  we",
  "do                  "
]
*/
#include <vector>
#include <string>
#include <cassert>
using namespace std;

vector<string> fullJustify(vector<string>& words, int maxWidth) {

	int N = words.size();
	vector<string> resl;
	for (int i = 0; i < N; ) {
		int j = i, len = 0, sum = 0;
		while (i < N) {
			if (len == 0)
				len += words[i].length();
			else
				len += (words[i].length() + 1);
			if (len <= maxWidth) {
				i++;
				sum = len;
			}
			else
				break;
		}
		int nWords = i - j;
		int nSpace = maxWidth - sum + nWords - 1;
		if (i != N) {
			// justified;
			if (nWords == 1) {
				resl.emplace_back(words[j] + string(nSpace, ' '));
			}
			else {
				int nplace = nWords - 1;
				vector<int> numSpace(nplace, 0);
				int n = 0;
				while (n < nSpace) {
					numSpace[n%nplace]++;
					n++;
				}
				string tmp;
				for (int idx = j; idx < i - 1; idx++)
					tmp += (words[idx] + string(numSpace[idx-j], ' '));
				tmp += words[i - 1];
				resl.emplace_back(tmp);
			}

		}
		else {
			// last line, left justified;
			string tmp = words[j];
			for (int idx = j + 1; idx < i; idx++) {
				tmp += (' ' + words[idx]);
				nSpace--;
			}
			tmp += string(nSpace, ' ');
			resl.emplace_back(tmp);

		}

	}

	return resl;
}

int main()
{
	vector<string> words = { "This", "is", "an", "example", "of", "text", "justification." };
	vector<string> ans = { "This    is    an", "example  of text", "justification.  " };
	vector<string> ret = fullJustify(words, 16);
	assert(ret == ans);
	return 0;
}
