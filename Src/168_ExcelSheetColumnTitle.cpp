/* Given a positive integer, return its corresponding column title as
* appear in an Excel sheet.
*
* For example:
*
*     1 -> A
*     2 -> B
*     3 -> C
*     ...
*     26 -> Z
*     27 -> AA
*     28 -> AB
*/

#include <string>
#include <cassert>
using namespace std;

string convertToTitle(int n) {

	string title;
	int res;
	while (n) {
		res = (n - 1) % 26;
		title = (char('A' + res)) + title;
		n = (n - 1) / 26;
	}
	return title;
}

int main()
{
	string ret = convertToTitle(52);
	assert(ret == "AZ");
	return 0;
}
