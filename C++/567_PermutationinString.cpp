/* Given two strings s1 and s2, write a function to return true if s2 contains
* the permutation of s1. In other words, one of the first string's permutations
* is the substring of the second string.
* Example 1:
* Input:s1 = "ab" s2 = "eidbaooo"
* Output:True
* Explanation: s2 contains one permutation of s1 ("ba").
* Example 2:
* Input:s1= "ab" s2 = "eidboaoo"
* Output: False
* Note:
* The input strings only contain lower case letters.
* The length of both given strings is in range [1, 10,000].
*/

#include <vector>
#include <algorithm>
#include <cassert>
using namespace std;

bool checkInclusion(string s1, string s2) {

	vector<int> s1Vec(26, 0), s2Vec(26, 0);
	for (int i = 0; i < s1.size(); i++)
		s1Vec[s1[i] - 'a']++;

	for (int i = 0; i <s2.length(); i++) {

		s2Vec[s2[i] - 'a']++;
		if (i >= s1.length() - 1) {
			if (s1Vec == s2Vec)
				return true;
			s2Vec[s2[i - s1.length() + 1] - 'a']--;
		}

	}
	return false;
}

int main()
{
	string s1 = "ab", s2 = "eidbaooo";
	bool ans = true;
	bool ret = checkInclusion(s1, s2);
	assert(ret == ans);
	return 0;
}
