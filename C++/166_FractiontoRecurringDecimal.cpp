/* Given two integers representing the numerator and denominator of a fraction,
* return the fraction in string format.
*
* If the fractional part is repeating, enclose the repeating part in parentheses.
*
* For example,
*
* Given numerator = 1, denominator = 2, return "0.5".
* Given numerator = 2, denominator = 1, return "2".
* Given numerator = 2, denominator = 3, return "0.(6)".
*/

#include <string>
#include <unordered_map>
#include <cassert>
using namespace std;

/**
* Definition for singly-linked list.
*/
struct ListNode {
	int val;
	ListNode *next;
	ListNode(int x) : val(x), next(nullptr) {}
};

string fractionToDecimal(int numerator, int denominator) {

	/* numerator == 0, return "0" */
	if ( numerator == 0)
		return "0";

	/* numerator == 0, return "NAN" */
	if (denominator == 0)
		return "NAN";

	string sz;
	/* add sign in front of the string */
	if (numerator < 0 ^ denominator < 0)
		sz = "-";

	/* get the absolute value */
	long long num = abs((long long)numerator);
	long long den = abs((long long)denominator);

	/* get integer part and residue */
	sz += to_string(num / den);
	long long residue = num % den;
	if (residue == 0)
		return sz;

	/* consider the fractional part */
	sz += '.';
	unordered_map<long long, int> resHashTable;
	while (residue) {

		if (resHashTable.find(residue) != resHashTable.end()) {
			/* duplicate residue found, enclose the repeating part in parentheses. */
			sz.insert(resHashTable[residue], "(");
			sz += ')';
			break;
		}
		/* store the residue into hash table, value equals to the
		position of current string length */
		resHashTable[residue] = sz.size();
		residue *= 10;
		sz += to_string(residue / den);
		residue %= den;
	}
	return sz;

}

int main()
{
	string ret = fractionToDecimal(24, -7);
	string ans = "-3.(428571)";
	assert(ret == ans);
	return 0;
}
