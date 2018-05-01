/*Roman numerals are represented by seven different symbols: I, V, X, L, C, D and M.

Symbol       Value
I             1
V             5
X             10
L             50
C             100
D             500
M             1000
For example, two is written as II in Roman numeral, just two one's added together.
Twelve is written as, XII, which is simply X + II. The number twenty seven is written
as XXVII, which is XX + V + II.

Roman numerals are usually written largest to smallest from left to right. However,
the numeral for four is not IIII. Instead, the number four is written as IV.
Because the one is before the five we subtract it making four. The same principle
applies to the number nine, which is written as IX. There are six instances where
subtraction is used:

I can be placed before V (5) and X (10) to make 4 and 9.
X can be placed before L (50) and C (100) to make 40 and 90.
C can be placed before D (500) and M (1000) to make 400 and 900.
Given a roman numeral, convert it to an integer. Input is guaranteed to be within
the range from 1 to 3999.

Example 1:

Input: "III"
Output: 3
Example 2:

Input: "IV"
Output: 4
Example 3:

Input: "IX"
Output: 9
Example 4:

Input: "LVIII"
Output: 58
Explanation: C = 100, L = 50, XXX = 30 and III = 3.
Example 5:

Input: "MCMXCIV"
Output: 1994
Explanation: M = 1000, CM = 900, XC = 90 and IV = 4.
*/
#include <vector>
#include <unordered_map>
#include <cassert>
using namespace std;

int romanToInt(string s) {
	unordered_map<char, int> tables = { { 'I', 1 },{ 'V',5 },{ 'X', 10 },{ 'L', 50 },
                                      { 'C', 100 },{ 'D', 500 },{ 'M', 1000 } };
	int ret = 0, N = s.length();
	ret = tables[s[N - 1]];
	for (int i = N - 2; i >= 0; i--) {
		if (tables[s[i]] >= tables[s[i + 1]])
			ret += tables[s[i]];
		else
			ret -= tables[s[i]];
	}
	return ret;
}

int romanToInt2(string s) {

	if (s.empty())
		return 0;
	vector<int> tables('X' + 1);
	tables['I'] = 1;
	tables['V'] = 5;
	tables['X'] = 10;
	tables['L'] = 50;
	tables['C'] = 100;
	tables['D'] = 500;
	tables['M'] = 1000;
	int ret = 0;

	for (int i = 0; i < s.length() - 1; i++) {
		if (tables[s[i]] < tables[s[i + 1]])
			ret -= tables[s[i]];
		else
			ret += tables[s[i]];
	}
	ret += tables[s.back()];
	return ret;
}

int main()
{
	int ans = 678;
	string str = "DCLXXVIII";
	int ret = romanToInt2(str);
	assert(ret == ans);
	return 0;
}
