/* Given a set of distinct integers, nums, return all possible subsets (the power set).

Note: The solution set must not contain duplicate subsets.

Example:

Input: nums = [1,2,3]
Output:
[
  [3],
  [1],
  [2],
  [1,2,3],
  [1,3],
  [2,3],
  [1,2],
  []
]
*/
#include <vector>
#include <cassert>
using namespace std;

void _DFS(vector<vector<int>>& resl, const vector<int> & nums, vector<int>& curVec, int pos, int N) {
	if (curVec.size() == N) {
		resl.push_back(curVec);
		return;
	}
	if (nums.size() - pos < N - curVec.size())
		return;

	for (int i = pos; i < nums.size(); i++) {
		curVec.push_back(nums[i]);
		_DFS(resl, nums, curVec, i + 1, N);
		curVec.pop_back();
	}
	return;
}

vector<vector<int>> subsets(vector<int>& nums) {
	vector<vector<int>> resl;
	for (int i = 0; i <= nums.size(); i++) {
		vector<int> curVec;
		_DFS(resl, nums, curVec, 0, i);
	}
	return resl;
}

int main()
{
	vector<int> nums = { 1,2,3 };
	vector<vector<int>> ans = { {},{ 1 },{ 2 },{ 3 },{1, 2},{1, 3},{2, 3},{1, 2, 3} };
	vector<vector<int>> ret = subsets(nums);
	assert(ret == ans);
	return 0;
}
