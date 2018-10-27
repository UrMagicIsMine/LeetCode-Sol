/* Given a non-empty array of integers, return the k most frequent elements.

For example,
Given [1,1,1,2,2,3] and k = 2, return [1,2].

Note:
You may assume k is always valid, 1 <= k <= number of unique elements.
Your algorithm's time complexity must be better than O(n log n), where n is the array's size.

*/
#include <unordered_map>
#include<vector>
#include<algorithm>
#include <cassert>
using namespace std;

/* 1) count freq using hash table O(N);
 * 2) store hash table using vector, sort vector based on frequency in descending order;
 * 3) get top K frequent result;
 */

vector<int> topKFrequent(vector<int>& nums, int k) {
	unordered_map<int, int> hashtbl;

	for (auto i : nums)
		hashtbl[i]++;

	vector<pair<int, int>> freqVec;
	for (auto pr : hashtbl)
		freqVec.push_back(pr);

	sort(freqVec.begin(), freqVec.end(), [](pair<int, int>&p1, pair<int, int>&p2)
                                        {return p1.second > p2.second;});

	vector<int> resl(k);
	for (int i = 0; i<k; i++)
		resl[i] = freqVec[i].first;

	return resl;
}

int main()
{
	vector<int> nums = { 1,2,3,4,2,3,4,1,2,3,2,1,1,1 };
	vector<int> ret = topKFrequent(nums, 2);
	vector<int> ans = { 1,2 };
	assert(ret == ans);
	return 0;
}
