/* Given a collection of candidate numbers (candidates) and a target number
* (target), find all unique combinations in candidates where the candidate numbers
* sums to target.
*
* Each number in candidates may only be used once in the combination.
*
* Note:
*
* All numbers (including target) will be positive integers.
* The solution set must not contain duplicate combinations.
* Example 1:
*
* Input: candidates = [10,1,2,7,6,1,5], target = 8,
* A solution set is:
* [
*   [1, 7],
*   [1, 2, 5],
*   [2, 6],
*   [1, 1, 6]
* ]
* Example 2:
*
* Input: candidates = [2,5,2,1,2], target = 5,
* A solution set is:
* [
*   [1,2,2],
*   [5]
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
			_DFS(resl, candidates, i + 1, curVec, target - candidates[i]);
			curVec.pop_back();

			// skip pushing duplicate numbers, important
			while (i + 1 < candidates.size() && candidates[i] == candidates[i + 1])
				i++;
		}
	}
	return;
}

vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
	sort(candidates.begin(), candidates.end());
	vector<vector<int>> resl;
	vector<int> curVec;
	_DFS(resl, candidates, 0, curVec, target);
	return resl;
}

int main()
{
	vector<int> candidates = { 10,1,2,7,6,1,5 };
	int target = 8;
	vector<vector<int>> ans = { {1,1,6},{1,2,5},{1,7},{2,6} };
	vector<vector<int>> ret = combinationSum2(candidates, target);
	assert(ret == ans);
	return 0;
}
