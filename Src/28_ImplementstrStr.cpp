/* Implement strStr().
*
* Return the index of the first occurrence of needle in haystack, or -1 if needle
* is not part of haystack.
*
* Example 1:
*
* Input: haystack = "hello", needle = "ll"
* Output: 2
* Example 2:
*
* Input: haystack = "aaaaa", needle = "bba"
* Output: -1
* Clarification:
*
* What should we return when needle is an empty string? This is a great question
* to ask during an interview.
*
* For the purpose of this problem, we will return 0 when needle is an empty string.
*/

#include <vector>
#include <cassert>
using namespace std;

/* Brute-force solution, worst-case run-time O((M-N)N), space O(1) */

int strStr_BF(string haystack, string needle) {
	int len1 = haystack.length();
	int len2 = needle.length();
	if (len2 == 0)
		return 0;
	for (int i = 0; i <= len1 - len2; i++) {
		int j = 0;
		while (j < len2) {
			if (haystack[i + j] != needle[j])
				break;
			else
				j++;
		}
		if (j == len2)
			return i;
	}
	return -1;
}

int strStr_KMP(string haystack, string needle) {

}

int main()
{
	string haystack = "Hello", needle = "ll";
	int ans = 2;
	int ret1 = strStr_BF(haystack, needle);
	assert(ret1 == ans);
	int ret2 = strStr_BF(haystack, needle);
	assert(ret2 == ans);
	return 0;
}
