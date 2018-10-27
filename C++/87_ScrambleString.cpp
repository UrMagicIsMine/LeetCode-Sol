/* Given a string s1, we may represent it as a binary tree by partitioning it to
two non-empty substrings recursively.

Below is one possible representation of s1 = "great":

    great
   /    \
  gr    eat
 / \    /  \
g   r  e   at
           / \
          a   t
To scramble the string, we may choose any non-leaf node and swap its two children.

For example, if we choose the node "gr" and swap its two children, it produces a
scrambled string "rgeat".

    rgeat
   /    \
  rg    eat
 / \    /  \
r   g  e   at
           / \
          a   t
We say that "rgeat" is a scrambled string of "great".

Similarly, if we continue to swap the children of nodes "eat" and "at", it produces
a scrambled string "rgtae".

    rgtae
   /    \
  rg    tae
 / \    /  \
r   g  ta  e
       / \
      t   a
We say that "rgtae" is a scrambled string of "great".

Given two strings s1 and s2 of the same length, determine if s2 is a scrambled
string of s1.

Example 1:

Input: s1 = "great", s2 = "rgeat"
Output: true
Example 2:

Input: s1 = "abcde", s2 = "caebd"
Output: false
*/
#include <vector>
#include <string>
#include <algorithm>
#include <cassert>
using namespace std;

/*
The basic idea is to divide s1(s2) into two substrings with length k and len-k and
check if the two substrings s1[0..k-1] and s1[k, len-1] are the scrambles of
s2[0..k-1] and s2[k,len-1] or s2[len-k, len-1] and s2[0..len-k-1] via recursion
*/

bool isScramble(string s1, string s2) {

	if (s1.length() != s2.length())
		return false;
	int N = s1.length();
	if (s1 == s2)
		return true;

	vector<char> cnt(26, 0);
	for (int i = 0; i < N; i++) {
		cnt[s1[i] - 'a']++;
		cnt[s2[i] - 'a']--;
	}
	for (int i = 0; i < 26; i++) {
		if (cnt[i])
			return false;
	}

	for (int len = 1; len < N; len++) {

		if (isScramble(s1.substr(0, len), s2.substr(0, len)) && isScramble(s1.substr(len), s2.substr(len)))
			return true;
		if (isScramble(s1.substr(0, len), s2.substr(N - len)) && isScramble(s1.substr(len), s2.substr(0, N - len)))
			return true;

	}
	return false;
}

int main()
{
	string s1 = "abc", s2 = "bca";
	bool ans = true;
	bool ret = isScramble(s1, s2);
	assert(ret == ans);
	return 0;
}
