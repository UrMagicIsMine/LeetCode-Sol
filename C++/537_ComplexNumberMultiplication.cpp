/* Given two strings representing two complex numbers.
*
* You need to return a string representing their multiplication. Note i2 = -1
* according to the definition.
*
* Example 1:
* Input: "1+1i", "1+1i"
* Output: "0+2i"
* Explanation: (1 + i) * (1 + i) = 1 + i2 + 2 * i = 2i, and you need convert it
* to the form of 0+2i.
* Example 2:
* Input: "1+-1i", "1+-1i"
* Output: "0+-2i"
* Explanation: (1 - i) * (1 - i) = 1 + i2 - 2 * i = -2i, and you need convert it
* to the form of 0+-2i.
* Note:
*
* The input strings will not have extra blank.
* The input strings will be given in the form of a+bi, where the integer a and b
* will both belong to the range of [-100, 100]. And the output should be also in
* this form.
*/

#include <string>
#include <algorithm>
#include <cassert>
using namespace std;

pair<int, int> to_complex(string&a) {
	pair<int, int> ret;
	int pos = a.find('+');
	ret.first = stoi(a.substr(0, pos));
	ret.second = stoi(a.substr(pos + 1, a.size() - 1 - pos));
	return ret;
}

string _to_string(pair<int, int> comp) {
	return to_string(comp.first) + '+' + to_string(comp.second) + 'i';
}

string complexNumberMultiply(string a, string b) {
	pair<int, int> comp_a = to_complex(a);
	pair<int, int> comp_b = to_complex(b);

	pair<int, int> ret;
	ret.first = comp_a.first * comp_b.first - comp_a.second * comp_b.second;
	ret.second = comp_a.first * comp_b.second + comp_a.second * comp_b.first;
	return _to_string(ret);
}


int main()
{
	string comp1 = "1+1i";
	string ret = complexNumberMultiply(comp1, comp1);
	string ans = "0+2i";
	assert(ret == ans);
	return 0;
}
