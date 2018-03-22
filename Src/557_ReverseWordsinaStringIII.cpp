/* Given a string, you need to reverse the order of characters in each word
* within a sentence while still preserving whitespace and initial word order.
*
* Example 1:
* Input: "Let's take LeetCode contest"
* Output: "s'teL ekat edoCteeL tsetnoc"
* Note: In the string, each word is separated by single space and there will not
* be any extra space in the string.
*/

#include <string>
#include <cassert>
using namespace std;

string reverseWords(string s) {

	int pos1 = 0;
	int N = s.size();

	while (pos1 < N) {
		int pos2 = s.find(' ', pos1);
		if (pos2 == string::npos)
			pos2 = N;

		int i = pos1;
		int j = pos2 - 1;
		for (; i < j; i++, j--)
			swap(s[i], s[j]);
		if (pos2 == N)
			break;

		pos1 = pos2 + 1;

	}
	return s;
}

int main()
{
	string ret = reverseWords("Let's take LeetCode contest");
	string ans = "s'teL ekat edoCteeL tsetnoc";
	assert(ret == ans);
	return 0;
}
