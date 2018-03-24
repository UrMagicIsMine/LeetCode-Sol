/* Given a string, sort it in decreasing order based on the frequency of characters.
*
* Example 1:
*
* Input: "tree"
* Output: "eert"
* Explanation:
* 'e' appears twice while 'r' and 't' both appear once.
* So 'e' must appear before both 'r' and 't'. Therefore "eetr" is also a valid answer.
*/
#include <unordered_map>
#include<vector>
#include<algorithm>
#include <cassert>
using namespace std;

/* 1) count freq using hash table O(N);
 * 2) store hash table using vector, sort vector in decreasing order based on
 * the frequency of characters;
 * 3) get top K frequent result;
 */

string frequencySort(string s) {
	unordered_map<char, int> hashtbl;
	for (auto c : s)
		hashtbl[c]++;

	int i = 0;
	vector<pair<char, int>> freqVecs(hashtbl.size());
	for (auto& p : hashtbl)
		freqVecs[i++] = p;

	using P_CI = pair<char, int>;
	sort(freqVecs.begin(), freqVecs.end(), [&](P_CI&p1, P_CI&p2) {
		return p1.second > p2.second || (p1.second == p2.second && p1.first < p2.first);});

	string resl;
	for (auto& p : freqVecs)
		resl += string(p.second, p.first);

	return resl;
}

int main()
{
	string word = "leetcode";
	string ret = frequencySort(word);
	string ans = "eeecdlot";
	assert(ret == ans);
	return 0;
}
