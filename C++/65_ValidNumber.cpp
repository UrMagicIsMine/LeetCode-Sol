/* Validate if a given string is numeric.

Some examples:
"0" => true
" 0.1 " => true
"abc" => false
"1 a" => false
"2e10" => true

Note: It is intended for the problem statement to be ambiguous. You should gather
all requirements up front before implementing one.
*/

#include <string>
#include <cassert>
using namespace std;

bool isNumber(string s) {
	int N = s.length();
	int i = 0;
	//skip white space
	while (i<N && s[i] == ' ') i++;
	// skip +/- in front
	if (i<N && (s[i] == '+' || s[i] == '-')) i++;
	bool isNum = false;
	while (i<N && isdigit(s[i])) {
		isNum = true;
		i++;
	}
  // check '.'
	if (i<N && s[i] == '.') {
		i++;
		while (i<N && isdigit(s[i])) {
			isNum = true;
			i++;
		}
	}
  // check 'e'
	if (i<N && isNum && s[i] == 'e') {
		i++;
		isNum = false;
		if (i<N && (s[i] == '+' || s[i] == '-')) i++;
		while (i<N && isdigit(s[i])) {
			isNum = true;
			i++;
		}
	}

	while (i < N && s[i] == ' ') i++;
	return isNum && i == N;
}

int main()
{
	string s = " +1.2e10  ";
	bool ans = true;
	bool ret = isNumber(s);
	assert(ret == ans);
	return 0;
}
