/* Related to question Excel Sheet Column Title
*
* Given a column title as appear in an Excel sheet, return its corresponding column number.
*
* For example:
*
*     A -> 1
*     B -> 2
*     C -> 3
*      ...
*     Z -> 26
*     AA -> 27
*     AB -> 28
*/

#include <string>
#include <cassert>
using namespace std;

int titleToNumber_Bwd(string s) {

int resl = 0;
int mult = 1;
for(int i = s.length() - 1; i >=0; i-- ){

resl += (s[i] - 'A' + 1) * mult;
mult *= 26;

}
return resl;
}

int titleToNumber_Fwd(string s) {
	int res = 0;
	for (char c : s) {
		res *= 26;
		res += c - 'A' + 1;
	}
	return res;
}

int main()
{
	int ret1 = titleToNumber_Bwd("ABZ");
	int ret2 = titleToNumber_Fwd("ABZ");
	assert(ret1 == 754);
	assert(ret2 == 754);
	return 0;
}
