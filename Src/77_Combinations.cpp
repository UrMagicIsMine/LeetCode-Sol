/* Given two integers n and k, return all possible combinations of k numbers out of 1 ... n.

Example:

Input: n = 4, k = 2
Output:
[
  [2,4],
  [3,4],
  [2,3],
  [1,2],
  [1,3],
  [1,4],
]
*/
#include <vector>
#include <cassert>
using namespace std;

void _DFS(vector<vector<int>>& resl, const vector<int>&nums, vector<int>&curVec, int pos, int k) {
	if (curVec.size() == k) {
		resl.push_back(curVec);
		return;
	}

	if (nums.size() - pos < k - curVec.size())
		return;

	for (int i = pos; i < nums.size(); i++) {
		curVec.push_back(nums[i]);
		_DFS(resl, nums, curVec, i + 1, k);
		curVec.pop_back();
	}
	return;
}

vector<vector<int>> combine(int n, int k) {
	vector<int> nums(n, 0);
	for (int i = 0; i < n; i++)
		nums[i] = i + 1;

	vector<vector<int>> resl;
	vector<int> curVec;
	_DFS(resl, nums, curVec, 0, k);
	return resl;
}

int main()
{
	int n = 4, k = 2;
	vector<vector<int>> ans = { {1, 2},{1, 3},{1, 4},{2, 3},{2, 4},{3, 4} };
	vector<vector<int>> ret = combine(n, k);
	assert(ret == ans);
	return 0;
}
