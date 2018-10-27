/* Given a string S, we can transform every letter individually to be lowercase
* or uppercase to create another string.  Return a list of all possible strings
* we could create.
*
* Examples:
* Input: S = "a1b2"
* Output: ["a1b2", "a1B2", "A1b2", "A1B2"]
*
* Input: S = "3z4"
* Output: ["3z4", "3Z4"]
*
* Input: S = "12345"
* Output: ["12345"]
* Note:
*
* S will be a string with length at most 12.
* S will consist only of letters or digits.
*/

#include <string>
#include <vector>
#include <cassert>
using namespace std;

using vec1D = vector<int>;
using vec2D = vector<vec1D>;

void _permBT(vector<string>& strVec, const string& S, string & cur, int i) {
	if (cur.size() == S.size()) {
		strVec.push_back(cur);
		return;
	}
	else {
		if (isalpha(S[i])) {
			cur.push_back(tolower(S[i]));
			_permBT(strVec, S, cur, i + 1);
			cur.pop_back();
			cur.push_back(toupper(S[i]));
			_permBT(strVec, S, cur, i + 1);
			cur.pop_back();
		}
		else {
			cur.push_back(S[i]);
			_permBT(strVec, S, cur, i + 1);
			cur.pop_back();
		}
	}
	return;
}

vector<string> letterCasePermutation(string S) {
	vector<string> resl;
	string runsz;
	_permBT(resl, S, runsz, 0);
	return resl;
}

int main()
{
	string s = "a1b2";
	vector<string> ret = letterCasePermutation(s);
	vector<string> ans = { {"a1b2"},{ "a1B2" } ,{ "A1b2" } ,{ "A1B2" } };
	assert(ret == ans);
	return 0;
}
