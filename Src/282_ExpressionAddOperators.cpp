/* Given a string that contains only digits 0-9 and a target value, return all
possibilities to add binary operators (not unary) +, -, or * between the digits
so they evaluate to the target value.

Example 1:

Input: num = "123", target = 6
Output: ["1+2+3", "1*2*3"]
Example 2:

Input: num = "232", target = 8
Output: ["2*3+2", "2+3*2"]
Example 3:

Input: num = "105", target = 5
Output: ["1*0+5","10-5"]
Example 4:

Input: num = "00", target = 0
Output: ["0+0", "0-0", "0*0"]
Example 5:

Input: num = "3456237490", target = 9191
Output: []
*/

#include <vector>
#include <string>
#include <cassert>
using namespace std;

void _DFS(vector<string>& resl, string path, const string& nums, int target, int pos, long long val, long long mul) {

	if (pos == nums.size()) {
		if (val == target)
			resl.push_back(std::move(path));
		return;
	}

	for (int i = pos; i < nums.size(); i++) {

		if (i != pos && nums[pos] == '0') break;
		string sCur = nums.substr(pos, i - pos + 1);
		long long curVal = stol(sCur);
		if (pos == 0)
			_DFS(resl, sCur, nums, target, i + 1, val + curVal, curVal);
		else {
			_DFS(resl, path + "+" + sCur, nums, target, i + 1, val + curVal, curVal);
			_DFS(resl, path + "-" + sCur, nums, target, i + 1, val - curVal, -curVal);
			_DFS(resl, path + "*" + sCur, nums, target, i + 1, val - mul + mul * curVal, mul * curVal);
		}
	}
	return;
}

vector<string> addOperators(string num, int target) {

	vector<string> resl;
	string path;
	_DFS(resl, path, num, target, 0, 0, 0);
	return resl;

}

int main() {
	string num = "123";
	int target = 6;
	vector<string> ret = addOperators(num, target);
	vector<string> ans = { "1+2+3", "1*2*3" };
	assert(ret == ans);
	return 0;
}
