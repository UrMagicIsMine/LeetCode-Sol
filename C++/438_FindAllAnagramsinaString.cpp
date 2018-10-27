/* Given a string s and a non-empty string p, find all the start indices of p's
* anagrams in s.
*
* Strings consists of lowercase English letters only and the length of both
* strings s and p will not be larger than 20,100.
*
* The order of output does not matter.
*
* Example 1:
*
* Input:
* s: "cbaebabacd" p: "abc"
*
* Output:
* [0, 6]
*
* Explanation:
* The substring with start index = 0 is "cba", which is an anagram of "abc".
* The substring with start index = 6 is "bac", which is an anagram of "abc".
*/

#include <vector>
#include <algorithm>
#include <cassert>
using namespace std;

vector<int> findAnagrams(string s, string p) {

	vector<int> sVec(26, 0);
	vector<int> pVec(26, 0);

	int sLen = s.length();
	int pLen = p.length();
	for (int i = 0; i <pLen; i++)
		pVec[p[i] - 'a']++;

	vector<int> resl;
	for (int i = 0; i<sLen; i++) {
		sVec[s[i] - 'a']++;
		if (i >= pLen - 1) {
			if (sVec == pVec)
				resl.push_back(i - pLen + 1);
			sVec[s[i - pLen + 1] - 'a']--;
		}
	}
	return resl;
}

int main()
{
	string s = "cbaebabacd";
	string p = "abc";
	vector<int> ret = findAnagrams(s,p);
	vector<int> ans = { 0,6 };
	assert(ret == ans);
	return 0;
}
