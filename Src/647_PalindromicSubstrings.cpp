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

int countSubstrings_sln1(string s) {

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

/* Solution 2: O(N^2) solution */

int _cntPal(const string& s, int beg, int end){
		int cnt = 0;
		for(; beg>=0 && end < s.length() && s[beg]==s[end]; beg--, end++ )
				cnt++;
		return cnt;
}

int countSubstrings_sln2(string s) {

	int N = s.size();
	vector<int> dpVec(N + 1, 0);
		int ret = 0;
	for (int i = 0; i < N; i++) { /* use i as middle to search */
				ret += _cntPal(s, i, i); /* palindromic string size are odd */
				ret += _cntPal(s, i, i+1); /* palindromic string size are even */
	}
	return ret;

}

int main()
{
	string s = "aba";
	int ans = 4;
	auto ret1 = countSubstrings_sln1(s);
	assert(ret1 == ans);

	auto ret2 = countSubstrings_sln2(s);
	assert(ret2 == ans);
	return 0;
}
