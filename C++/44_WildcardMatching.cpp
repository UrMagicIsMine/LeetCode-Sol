/*Given an input string (s) and a pattern (p), implement wildcard pattern matching
with support for '?' and '*'.

'?' Matches any single character.
'*' Matches any sequence of characters (including the empty sequence).
The matching should cover the entire input string (not partial).

Note:

s could be empty and contains only lowercase letters a-z.
p could be empty and contains only lowercase letters a-z, and characters like ? or *.
Example 1:

Input:
s = "aa"
p = "a"
Output: false
Explanation: "a" does not match the entire string "aa".
Example 2:

Input:
s = "aa"
p = "*"
Output: true
Explanation: '*' matches any sequence.
Example 3:

Input:
s = "cb"
p = "?a"
Output: false
Explanation: '?' matches 'c', but the second letter is 'a', which does not match 'b'.
Example 4:

Input:
s = "adceb"
p = "*a*b"
Output: true
Explanation: The first '*' matches the empty sequence, while the second '*' matches
the substring "dce".
Example 5:

Input:
s = "acdcb"
p = "a*c?b"
Output: false
*/
#include <vector>
#include <unordered_map>
#include <cassert>
using namespace std;

/*
For each element in s
If s[i]==p[j] or p[j] == '?' which means this is a match, then goes to next element i++ j++.
If p[j]=='*', this is also a match, but one or many chars may be available, so let us save this *'s position and the matched s position.
If not match, then we check if there is a * previously showed up,
       if there is no *,  return false;
       if there is an *,  we set current j to the next element of *, and set current i to the next saved s position.
*/

bool isMatch(string s, string p) {

	if (s.empty() && p.empty())
		return true;
	if (p.empty())
		return false;

	int star = -1, j = 0, mpos = 0;
	for (int i = 0; i < s.length(); ) {

		if (s[i] == p[j] || p[j] == '?') {
			j++, i++;
			continue;
		}
		if (p[j] == '*') {
			star = j;
			j++;
			mpos = i;
			continue;
		}
		if (star != -1) {
			j = star + 1;
			i = ++mpos;
			continue;
		}
		return false;
	}
	while (j < p.length() && p[j] == '*')
		j++;
	return j == p.length();
}

int main()
{
	string s = "adceb", p = "*a*b";
	bool ans = true;
	bool ret = isMatch(s, p);
	assert(ret == ans);
	return 0;
}
