/* Given a set of candidate numbers (candidates) (without duplicates) and a target
* number (target), find all unique combinations in candidates where the candidate
* numbers sums to target.
*
* The same repeated number may be chosen from candidates unlimited number of times.
*
* Note:
*
* All numbers (including target) will be positive integers.
* The solution set must not contain duplicate combinations.
* Example 1:
*
* Input: candidates = [2,3,6,7], target = 7,
* A solution set is:
* [
*   [7],
*   [2,2,3]
* ]
* Example 2:
*
* Input: candidates = [2,3,5], target = 8,
* A solution set is:
* [
*   [2,2,2,2],
*   [2,3,3],
*   [3,5]
* ]
*/

#include <vector>
#include <string>
#include <algorithm>
#include <cassert>
using namespace std;

void _DFS(vector<vector<int>>& resl, const vector<int>& candidates, int pos, vector<int>& curVec, int target) {

	if (target == 0) {
		resl.push_back(curVec);
		return;
	}

	for (int i = pos; i < candidates.size(); i++) {

		if (candidates[i] <= target) {
			curVec.push_back(candidates[i]);
			_DFS(resl, candidates, i, curVec, target - candidates[i]);
			curVec.pop_back();
		}

	}
	return;
}

vector<vector<int>> combinationSum(vector<int>& candidates, int target) {

	sort(candidates.begin(), candidates.end());
	vector<int> curVec;
	vector<vector<int>> resl;
	_DFS(resl, candidates, 0, curVec, target);
	return resl;
}

int main()
{
	vector<int> candidates = { 2,3,6,7 };
	int target = 7;
	vector<vector<int>> ans = { {2,2,3}, {7} };
	vector<vector<int>> ret = combinationSum(candidates, target);
	assert(ret == ans);
	return 0;
}
