/* Given a collection of distinct integers, return all possible permutations.

Example:

Input: [1,2,3]
Output:
[
  [1,2,3],
  [1,3,2],
  [2,1,3],
  [2,3,1],
  [3,1,2],
  [3,2,1]
]
*/

#include <vector>
#include <numeric>
#include <algorithm>
#include <cassert>
using namespace std;

bool _nextPermutation(vector<int>& nums) {
	int N = nums.size();
	if (N <= 1)
		return false;

	int i = N - 2;
	for (; i >= 0; i--)
		if (nums[i] < nums[i + 1]) break;

	// descending order
	if (i == -1) {
		reverse(nums.begin(), nums.end());
		return false;
	}

	// find the place to swap;
	int k = N - 1;
	for (; k >= 0; k--) {
		if (nums[k] > nums[i])
			break;
	}

	swap(nums[i], nums[k]);
	reverse(nums.begin() + i + 1, nums.end());
	return true;
}

vector<vector<int>> permute_LP(vector<int>& nums) {

	sort(nums.begin(), nums.end());
	vector<vector<int>> resl;
	do {
		resl.push_back(nums);
	} while (_nextPermutation(nums));
	return resl;
}

/* backtracking solution, O(N!) */

void _DFS(vector<vector<int>>& resl, vector<int> candidates, vector<int>& curVec) {
	if (candidates.empty()) {
		resl.push_back(curVec);
		return;
	}

	for (int i = 0; i < candidates.size(); i++) {
		curVec.push_back(candidates[i]);
		vector<int> nextcandidates;//(candidates.size() - 1, 0);
		for (int j = 0; j < candidates.size(); j++)
			if (j != i)
				nextcandidates.push_back(candidates[j]);
		_DFS(resl, nextcandidates, curVec);
		curVec.pop_back();
	}
	return;
}

vector<vector<int>> permute_BT(vector<int>& nums) {

	vector<vector<int>> resl;
	vector<int> curVec;
	_DFS(resl, nums, curVec);
	return resl;
}

int main()
{
	vector<int> nums = { 2,1,3 };
	vector<vector<int>> ans = { {1, 2, 3},{1, 3, 2},{2, 1, 3},{2, 3, 1},{3, 1, 2},{3, 2, 1} };
	vector<vector<int>> ret = permute_LP(nums);
	assert(ret == ans);
	vector<vector<int>> ret2 = permute_BT(nums);
	assert(ret2 == ans);
	return 0;
}
