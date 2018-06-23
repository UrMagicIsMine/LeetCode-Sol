/*  Given a string s, you are allowed to convert it to a palindrome by adding
characters in front of it. Find and return the shortest palindrome you can find
by performing this transformation.

Example 1:

Input: "aacecaaa"
Output: "aaacecaaa"
Example 2:

Input: "abcd"
Output: "dcbabcd"
*/

// brute force solution, run-time O(N), memory O(1)

int _getPalLen(string s, int N, int idx) {
	int i = 0, j = 0;
	for (i = idx, j = idx + 1; i >= 0 && j < N; i--, j++) {
		if (s[i] != s[j])
			break;
	}

	if (i == -1)
		return j;

	for ( i = idx - 1, j = idx + 1; i >= 0 && j < N; i--, j++) {
		if (s[i] != s[j])
			break;
	}
	if (i == -1)
		return j;
	else
		return -1;
}

string shortestPalindrome(string s) {

	int N = s.size(), len = 0;
	if (N == 0)
		return s;

	for (int i = 0; i <= (N - 1) / 2; i++)
		len = max(len, _getPalLen(s, N, i));

	string str = s.substr(len, N - len);
	reverse(str.begin(), str.end());
	return str + s;
}


int main()
{
	string str = "aacecaaa";
	string ret = shortestPalindrome(str);
	return 0;
}
