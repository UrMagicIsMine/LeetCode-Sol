/* Given an unsorted array of integers, find the length of the longest consecutive
* elements sequence.
*
* For example,
* Given [100, 4, 200, 1, 3, 2],
* The longest consecutive elements sequence is [1, 2, 3, 4]. Return its length: 4.
*
* Your algorithm should run in O(n) complexity.
*/

#include <vector>
#include <unordered_map>
#include <algorithm>
#include <cassert>
using namespace std;

/**
* O(NlogN) solution using sort
*/
int longestConsecutive_ST(vector<int>& nums) {

	if (nums.size() == 0)
		return 0;

	sort(nums.begin(), nums.end());

	int num = 1;
	int ret = num;
	for (int i = 1; i < nums.size(); i++) {
		if (nums[i] == nums[i - 1])
			continue;
		else if (nums[i] == nums[i - 1] + 1) {
			num++;
			ret = max(ret, num);
		}
		else
			num = 1;
	}
	return ret;

}

/*
use a hash map to store boundary information of consecutive sequence for each
element; there 4 cases when a new element i reached:
  1) neither i+1 nor i-1 has been seen: m[i]=1;
  2) both i+1 and i-1 have been seen: extend m[i+m[i+1]] and m[i-m[i-1]] to each other;
  3) only i+1 has been seen: extend m[i+m[i+1]] and m[i] to each other;
  4) only i-1 has been seen: extend m[i-m[i-1]] and m[i] to each other.
*/

int longestConsecutive_HT(vector<int>& nums) {

	if (nums.size() == 0)
		return 0;

	int iMax = 1;
	unordered_map<int, int> hashtbl;
	for (auto i : nums) {
		if (hashtbl[i])
			continue;
		else
		{
			hashtbl[i] = hashtbl[i - 1] + hashtbl[i + 1] + 1;
			if (hashtbl[i - 1])
				hashtbl[i - hashtbl[i - 1]] = hashtbl[i];
			if (hashtbl[i + 1])
				hashtbl[i + hashtbl[i + 1]] = hashtbl[i];
			iMax = max(iMax, hashtbl[i]);
		}
	}
	return iMax;
}


int main()
{
	vector<int> nums = { 100, 4, 200, 1, 3, 2 };
	int ans = 4;
	int ret1 = longestConsecutive_ST(nums);
	assert(ret1 == ans);
	int ret2 = longestConsecutive_HT(nums);
	assert(ret2 == ans);
	return 0;
}
