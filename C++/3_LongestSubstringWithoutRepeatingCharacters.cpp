/* Given a string, find the length of the longest substring without repeating
* characters.
*
* Examples:
*
* Given "abcabcbb", the answer is "abc", which the length is 3.
*
* Given "bbbbb", the answer is "b", with the length of 1.
*
* Given "pwwkew", the answer is "wke", with the length of 3. Note that the answer
* must be a substring, "pwke" is a subsequence and not a substring.
*/

#include <string>
#include <algorithm>
#include <unordered_map>
#include <cassert>
using namespace std;

/* we repeatedly check a substring to see if it has duplicate character. If a
* substring s_ij from index i to j - 1 is already checked to have no duplicate
* characters. We only need to check if s[j] is already in the substring s_​ij.
* By using HashSet as a sliding window, checking if a character in the hash table
* can be done in O(1).
*
* We use HashSet to store the characters in current window [i, j) (j = i initially).
* Then we slide the index j to the right. If it is not in the Hash table, we slide
* j further, and update max length result. If s[j] is in the Hash table, move i
* forward to the location of previous s[j] and remove numbers behind it.
*
* run-time O(2N), memory O(min(m,n)), m is the size of the charset/alphabet
*/

int lengthOfLongestSubstring_HT1(string s) {
	if (s.size() == 0)
		return 0;
	int resl = 1, front = 0, back = 0;
	unordered_map<char, int> chartbl;
	for (; front < s.size(); front++) {
		auto it = chartbl.find(s[front]);
		if (it == chartbl.end()) {
			resl = max(resl, front - back + 1);
		}
		else {
			/* be careful of invalidating iterator */
			int tmp = it->second;
			while (back <= tmp)
				chartbl.erase(s[back++]);
		}
		chartbl.emplace(s[front], front);
	}
	return resl;
}

/* for the back pointer, we can do better. when we found a repeated character,
* we can skip the characters immediately.
* The reason is that if s[j] have a duplicate in the range [i, j) with index j'
​​* we don't need to increase i little by little. We can skip all the elements in
* the range [i, j'] and let i to be j' + 1 directly.
* run-time O(N), memory O(min(m,n))
*/

int lengthOfLongestSubstring_HT2(string s) {
	unordered_map<char, int> char_table;
	int front = 0, back = 0, ret = 0;
	for (; front < s.size(); front++) {
			auto iter = char_table.find(s[front]);
			if (iter == char_table.end() || iter->second < back) {
					ret = max(ret, front - back + 1);
			} else {
					back = iter->second + 1;
			}
			char_table[s[front]] = front;
	}
	return ret;
}

int main()
{
	string s = "pwwkew";
	int ans = 3;
	int ret1 = lengthOfLongestSubstring_HT1(s);
	assert(ret1 == ans);
	int ret2 = lengthOfLongestSubstring_HT2(s);
	assert(ret2 == ans);
	return 0;
}
