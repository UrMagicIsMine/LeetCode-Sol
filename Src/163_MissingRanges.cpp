/*
Given a sorted integer array nums, where the range of elements are in the inclusive
range [lower, upper], return its missing ranges.

Example:

Input: nums = [0, 1, 3, 50, 75], lower = 0 and upper = 99,
Output: ["2", "4->49", "51->74", "76->99"]
*/

#include <string>
#include <vector>
#include <cassert>

using namespace std;

string _getRange(long long low, long long high) {
	return (low == high) ? to_string(low) : to_string(low) + "->" + to_string(high);
}

vector<string> findMissingRanges(vector<int>& nums, int lower, int upper) {

	vector<string> resl;
	long long pre = (long long)lower - 1;
	for (int i = 0; i <= nums.size(); i++) {
		long long cur = (i == nums.size()) ? (long long)upper + 1 : nums[i];
		if (cur - pre >= 2)
			resl.push_back(_getRange(pre + 1, cur - 1));
		pre = cur;
	}
	return resl;
}


int main() {
	vector<int> nums = { 0, 1, 3, 50, 75 };
	int lower = 0, upper = 99;
	vector<string> ret = findMissingRanges(nums, lower, upper);
	vector<string> ans = { "2", "4->49", "51->74", "76->99" };
	assert(ret == ans);
}
