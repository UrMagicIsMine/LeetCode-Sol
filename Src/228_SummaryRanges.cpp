/* Given a sorted integer array without duplicates, return the summary of its ranges.
*
* Example 1:
* Input: [0,1,2,4,5,7]
* Output: ["0->2","4->5","7"]
* Example 2:
* Input: [0,2,3,4,6,8,9]
* Output: ["0","2->4","6","8->9"]
*/

#include <vector>
#include <string>
#include <cassert>
using namespace std;

vector<string> summaryRanges(vector<int>& nums) {

	vector<vector<int>> ranges;
	for (int i = 0; i < nums.size(); i++) {

		if (ranges.empty() || nums[i] != ranges.back().back() + 1) {
			ranges.push_back(vector<int>());
			ranges.back().push_back(nums[i]);
		}
		else if (nums[i] == ranges.back().back() + 1) {
			if (ranges.back().size() == 1)
				ranges.back().push_back(nums[i]);
			else
				ranges.back()[1] = nums[i];
		}
	}

	vector<string> resl;

	for (auto &r : ranges) {

		string s;
		if (r.size() == 1)
			s = to_string(r[0]);
		else
			s = to_string(r[0]) + "->" + to_string(r[1]);
		resl.emplace_back(s);
	}
	return resl;
}

int main()
{
	vector<int> nums = { 0,1,2,4,5,7 };
	vector<string> ans = { "0->2","4->5","7" };
	vector<string> ret = summaryRanges(nums);
	assert(ret == ans);
	return 0;
}
