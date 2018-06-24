/* Convert a non-negative integer to its english words representation. Given input is guaranteed to be less than 231 - 1.

Example 1:

Input: 123
Output: "One Hundred Twenty Three"
Example 2:

Input: 12345
Output: "Twelve Thousand Three Hundred Forty Five"
Example 3:

Input: 1234567
Output: "One Million Two Hundred Thirty Four Thousand Five Hundred Sixty Seven"
Example 4:

Input: 1234567891
Output: "One Billion Two Hundred Thirty Four Million Five Hundred Sixty Seven Thousand Eight Hundred Ninety One"
*/

#include <vector>
#include <string>
#include <cassert>
using namespace std;

string _addPre(string& pre, string& sz) {

	if (pre.size() == 0)
		return sz;

	if (sz.size() == 0)
		return pre;
	else
		return pre + " " + sz;
}

string _addPost(string& sz, string& post) {

	if (post.size() == 0)
		return sz;

	if (sz.size() == 0)
		return post;
	else
		return sz + " " + post;
}

string numberToWords(int num) {
	if (num == 0)
		return "Zero";
	vector<string> str1 = { "", "One", "Two", "Three", "Four", "Five", "Six", "Seven", "Eight", "Nine" };
	vector<string> str2 = { "Ten", "Eleven", "Twelve", "Thirteen", "Fourteen", "Fifteen", "Sixteen", "Seventeen", "Eighteen", "Nineteen" };
	vector<string> str3 = { "", "Ten", "Twenty", "Thirty", "Forty", "Fifty", "Sixty", "Seventy", "Eighty", "Ninety" };
	vector<string> str4 = { "", "Thousand", "Million", "Billion" };
	string hundred = "Hundred";
	int i = 0, res = 0;
	vector<string> resl;
	while (num) {
		string tmp;
		res = num % 1000;
		num /= 1000;

		if (res >= 100) {
			tmp = _addPre(hundred, tmp);
			tmp = _addPre(str1[res / 100], tmp);
			res %= 100;
		}
		if (res >= 20) {
			tmp = _addPost(tmp, str3[res / 10]);
			res = res % 10;
		}
		else if (res >= 10) {
			tmp = _addPost(tmp, str2[res % 10]);
			res = 0;
		}

		if (res > 0)
			tmp = _addPost(tmp, str1[res]);

		resl.push_back(tmp);

		i++;

	}
	string ret;
	for (int i = 0; i < resl.size(); i++) {
		if (i > 0 && resl[i].size() != 0)
			ret = _addPre(str4[i], ret);
		ret = _addPre(resl[i], ret);
	}
	return ret;
}

int main() {

	string ret = numberToWords(1000010);
	return 0;
}
