/* Given a non-empty list of words, return the k most frequent elements.
*
* Your answer should be sorted by frequency from highest to lowest. If two words
* have the same frequency, then the word with the lower alphabetical order comes first.
*
* Example 1:
* Input: ["i", "love", "leetcode", "i", "love", "coding"], k = 2
* Output: ["i", "love"]
* Explanation: "i" and "love" are the two most frequent words.
*     Note that "i" comes before "love" due to a lower alphabetical order.
* Example 2:
* Input: ["the", "day", "is", "sunny", "the", "the", "the", "sunny", "is", "is"], k = 4
* Output: ["the", "is", "sunny", "day"]
* Explanation: "the", "is", "sunny" and "day" are the four most frequent words,
*     with the number of occurrence being 4, 3, 2 and 1 respectively.
* Note:
* You may assume k is always valid, 1 <= k <= number of unique elements.
* Input words contain only lowercase letters.
* Follow up:
* Try to solve it in O(n log k) time and O(n) extra space.
*/
#include <unordered_map>
#include<vector>
#include<algorithm>
#include <cassert>
using namespace std;

/* 1) count freq using hash table O(N);
 * 2) store hash table using vector, sort vector based on frequency in descending
 * order and string in ascending order;
 * 3) get top K frequent result;
 */

vector<string> topKFrequent(vector<string>& words, int k) {
	unordered_map<string, int> hashtbl;
	for (auto w : words)
		hashtbl[w]++;

	vector<pair<string, int>> freqVec(hashtbl.size());
	int i = 0;
	for (auto pr : hashtbl)
		freqVec[i++] = pr;

	using P_SI = pair<string, int>;
	auto lambda = [](P_SI& p1, P_SI& p2) {return p1.second > p2.second
                          || (p1.second == p2.second && p1.first < p2.first);};
	sort(freqVec.begin(), freqVec.end(), lambda);

	vector<string> resl(k);
	for (i = 0; i<k; i++)
		resl[i] = freqVec[i].first;

	return resl;
}

int main()
{
	vector<string> words = { "i", "love", "leetcode", "i", "love", "coding" };
	vector<string> ret = topKFrequent(words, 2);
	vector<string> ans = { "i","love" };
	assert(ret == ans);
	return 0;
}
