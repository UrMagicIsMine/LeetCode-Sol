/* Given an integer array, your task is to find all the different possible
* increasing subsequences of the given array, and the length of an increasing
* subsequence should be at least 2 .
*
* Example:
* Input: [4, 6, 7, 7]
* Output: [[4, 6], [4, 7], [4, 6, 7], [4, 6, 7, 7], [6, 7], [6, 7, 7], [7,7], [4,7,7]]
* Note:
* The length of the given array will not exceed 15.
* The range of integer in the given array is [-100,100].
* The given array may contain duplicates, and two equal integers should also be
* considered as a special case of increasing sequence.
*
*/

#include <vector>
#include <set>
#include <cassert>
using namespace std;

void _findSubSeq(set<vector<int>>& seqset, const vector<int>& nums, vector<int>& seq, int pos) {

	if (seq.size() >= 2) {
		seqset.insert(seq);
	}
	for (int i = pos; i < nums.size(); i++) {

		if (seq.size() == 0 || nums[i] >= seq.back()) {
			seq.push_back(nums[i]);
			_findSubSeq(seqset, nums, seq, i + 1);
			seq.pop_back();
		}

	}
	return;
}

vector<vector<int>> findSubsequences(vector<int>& nums) {

	set<vector<int>> seqset;
	vector<int> seq;
	_findSubSeq(seqset, nums, seq, 0);
	vector<vector<int>> resl(seqset.begin(), seqset.end());
	return resl;
}

int main()
{
	vector<int> nums = { 4,6,7,7 };
	vector<vector<int>> ans = { {4,6},{ 4,6,7 },{ 4,6,7,7 },{ 4,7 },{ 4,7,7 },{ 6,7 },{ 6,7,7 },{ 7,7 } };
	vector<vector<int>> ret = findSubsequences(nums);
	assert(ret == ans);
	return 0;
}
