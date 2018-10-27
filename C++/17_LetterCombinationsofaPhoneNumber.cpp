/* Given a string containing digits from 2-9 inclusive, return all possible letter
* combinations that the number could represent.
*
* A mapping of digit to letters (just like on the telephone buttons) is given below.
* Note that 1 does not map to any letters.
*
* Example:
*
* Input: "23"
* Output: ["ad", "ae", "af", "bd", "be", "bf", "cd", "ce", "cf"].
* Note:
*
* Although the above answer is in lexicographical order, your answer could be in
* any order you want.
*
*/

#include <vector>
#include <numeric>
#include <algorithm>
#include <cassert>
using namespace std;

/* Depth-First Search solution, O(4^N) */

void _DFS(vector<string> & resl, string& curstr, const string& digits, int iPos) {

	static vector<string> ns_maps = { "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz" };

	if (iPos == digits.length()) {
		resl.push_back(curstr);
		return;
	}
	for (int i = 0; i < ns_maps[digits[iPos] - '2'].size(); i++) {

		curstr.push_back(ns_maps[digits[iPos] - '2'][i]);
		_DFS(resl, curstr, digits, iPos + 1);
		curstr.pop_back();
	}
	return;
}

vector<string> letterCombinations(string digits) {

	vector<string> resl;

	if (digits.length() == 0)
		return resl;

	string curstr;
	_DFS(resl, curstr, digits, 0);
	return resl;

}

int main()
{
	string digits = "23";
	vector<string> ans = { "ad","ae","af","bd","be","bf","cd","ce","cf" };
	vector<string> ret = letterCombinations(digits);
	assert(ret == ans);
	return 0;
}
