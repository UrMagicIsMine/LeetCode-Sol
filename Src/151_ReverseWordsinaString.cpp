/* Given an input string, reverse the string word by word.
*
* For example,
* Given s = "the sky is blue",
* return "blue is sky the".
*/

#include <iostream>
#include <sstream>
#include <string>
using namespace std;

void reverseWords(string &s) {

	istringstream is(s);
	string tmp;
	is >> s;
	while (is >> tmp)
		s = tmp + " " + s;

	if (s[0] == ' ') s = "";
}

int main()
{
	string sz = "the sky is blue";
	reverseWords(sz);
	return 0;
}
