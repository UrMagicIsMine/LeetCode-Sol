/* Given a string S and a string T, find the minimum window in S which will
* contain all the characters in T in complexity O(n).
*
* Example:
*
* Input: S = "ADOBECODEBANC", T = "ABC"
* Output: "BANC"
* Note:
*
* If there is no such window in S that covers all characters in T, return the
* empty string "".
* If there is such window, you are guaranteed that there will always be only one
* unique minimum window in S.
*/

#include <vector>
#include <algorithm>
#include <unordered_map>
#include <cassert>
using namespace std;

/*
1. Use two pointers: front and back to represent a window.
2. Move front to find a valid window.
3. When a valid window is found, move back to find a smaller window.
*/

string minWindow(string s, string t) {
	/* initialize the hash map */
	unordered_map<char, int> ctimes;
	for (auto c : t)
		ctimes[c]++;

	int N = s.length(), Num = t.length();
	int minLen = INT_MAX, min_beg = 0, min_end = 0;
	int front = 0, back = 0;

	for (; front < N; front++) {

		/* modify counter and hash map */
		if (ctimes[s[front]] > 0)
			Num--;
		ctimes[s[front]]--;

		/* counter condition */
		while (Num == 0) {

			/* update min_Len here if finding minimum*/

			if ((front + 1 - back) < minLen) {
				minLen = front - back + 1;
				min_beg = back;
				min_end = front;
			}

			/* increase back, update hash map and counter to make counter invalid again */
			ctimes[s[back]]++;
			if (ctimes[s[back]] > 0)
				Num++;

			back++;
		}

	}
	if (minLen != INT_MAX)
		return s.substr(min_beg, minLen);
	else
		return "";
}

int main()
{
	string s = "ADOBECODEBANC", t = "ABC";
	string ans = "BANC";
	string ret = minWindow(s, t);
	assert(ret == ans);
	return 0;
}
