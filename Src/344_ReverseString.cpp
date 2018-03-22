/* Write a function that takes a string as input and returns the string reversed.

Example:
Given s = "hello", return "olleh".
*/

#include <string>
#include <cassert>
using namespace std;

string reverseString(string s) {
	if (s.size() == 0)
		return s;
	int i = 0, j = s.size() - 1;
	for (; i < j; i++, j--)
		swap(s[i], s[j]);

	return s;

}

int main()
{
	string ret = reverseString("hello");
	string ans = "olleh";
	assert(ret == ans);
	return 0;
}
