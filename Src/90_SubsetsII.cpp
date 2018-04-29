/* Given a collection of integers that might contain duplicates, nums, return all possible subsets (the power set).

Note: The solution set must not contain duplicate subsets.

Example:

Input: [1,2,2]
Output:
[
  [2],
  [1],
  [1,2,2],
  [2,2],
  [1,2],
  []
]
*/
#include <vector>
#include <algorithm>
#include <cassert>
using namespace std;

void _DFS1(vector<vector<int>>& resl, vector<int>&curVec, const vector<int>& nums, int pos, int N) {

	if (curVec.size() == N) {
		resl.push_back(curVec);
		return;
	}

	if (N - curVec.size() > nums.size() - pos)
		return;

	for (int i = pos; i < nums.size(); i++) {
		curVec.push_back(nums[i]);
		_DFS1(resl, curVec, nums, i + 1, N);
		curVec.pop_back();

		while (i + 1 < nums.size() && nums[i] == nums[i + 1])
			i++;
	}
	return;
}

vector<vector<int>> subsetsWithDup_Sln1(vector<int>& nums) {
	sort(nums.begin(), nums.end());
	vector<vector<int>> resl;
	vector<int> curVec;
	int N = nums.size();
	for (int i = 0; i <= N; i++)
		_DFS1(resl, curVec, nums, 0, i);
	return resl;
}

void _DFS2(vector<vector<int>>& resl, vector<int>&curVec, const vector<int>& nums, int pos) {

	if (pos >= nums.size())
		return;

	for (int i = pos; i < nums.size(); i++) {
		curVec.push_back(nums[i]);
		resl.push_back(curVec);
		_DFS2(resl, curVec, nums, i + 1);
		curVec.pop_back();

		while (i + 1 < nums.size() && nums[i] == nums[i + 1])
			i++;
	}
	return;
}

vector<vector<int>> subsetsWithDup_Sln2(vector<int>& nums) {
	sort(nums.begin(), nums.end());
	vector<int> curVec;
	vector<vector<int>> resl(1, curVec);
	_DFS2(resl, curVec, nums, 0);
	return resl;
}

int main()
{
	vector<int> nums = { 1,2,2 };
	vector<vector<int>> ret1 = subsetsWithDup_Sln1(nums);
	vector<vector<int>> ans1 = { {},{1},{2},{1, 2},{2, 2},{1, 2, 2} };
	assert(ret1 == ans1);
	vector<vector<int>> ans2 = { {},{1},{1, 2},{1, 2, 2},{2},{2, 2 } };
	vector<vector<int>> ret2 = subsetsWithDup_Sln2(nums);
	assert(ret2 == ans2);
	return 0;
}
