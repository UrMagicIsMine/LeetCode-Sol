/* Given a string s consists of upper/lower-case alphabets and empty space
* characters ' ', return the length of last word in the string.
*
* If the last word does not exist, return 0.
*
* Note: A word is defined as a character sequence consists of non-space characters
* only.
*
* Example:
*
* Input: "Hello World"
* Output: 5
*/

#include <sstream>
#include <string>
#include <cassert>
using namespace std;

int lengthOfLastWord(string s) {

	istringstream ss(s);
	string str;
	while (ss >> str)
		;
	return str.length();

}

int main()
{
	string s = "Hello World";
	int ans = 5;
	int ret = lengthOfLastWord(s);
	assert(ret == ans);
	return 0;
}
