/* Given a string, your task is to count how many palindromic substrings in this
*  string.
*
* The substrings with different start indexes or end indexes are counted as
* different substrings even they consist of same characters.
*
* Example 1:
*	Input: "abc"
*	Output: 3
*	Explanation: Three palindromic strings: "a", "b", "c".
* Example 2:
*	Input: "aaa"
*	Output: 6
*	Explanation: Six palindromic strings: "a", "a", "a", "aa", "aa", "aaa".
* Note:
*	The input string length won't exceed 1000.
*/

#include <vector>
#include <cassert>
using namespace std;

bool isPal(const string& s, int beg, int end) {
	for (; beg <= end; beg++, end--) {
		if (s[beg] != s[end])
			return false;
	}
	return true;
}

/* DP solution, O(n^2), O(n^3)? need optimization */

int countSubstrings(string s) {

	int N = s.size();
	vector<int> dpVec(N + 1, 0);

	for (int i = 0; i < N; i++) {

		int palcnt = 0;
		for (int j = i; j >= 0; j--) {
			if (isPal(s, j, i))
				palcnt++;
		}
		dpVec[i+1] = dpVec[i] + palcnt;
	}
	return dpVec[N];
}

int main()
{
	string s = "aba";
	int ans = 4;
	auto ret = countSubstrings(s);
	assert(ret == ans);
	return 0;
}
