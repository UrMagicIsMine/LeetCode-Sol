/* Given an array of numbers nums, in which exactly two elements appear only once
* and all the other elements appear exactly twice. Find the two elements that appear
* only once.
*
* For example:
*
* Given nums = [1, 2, 1, 3, 2, 5], return [3, 5].
*
* Note:
* The order of the result is not important. So in the above example, [5, 3] is
* also correct.
* Your algorithm should run in linear runtime complexity. Could you implement it
* using only constant space complexity?
*/

#include <vector>
#include <unordered_set>
#include <cassert>
using namespace std;

vector<int> singleNumber_HT(vector<int>& nums) {
	unordered_set<int> hashtbl;
	for (auto i : nums) {
		if (hashtbl.find(i) != hashtbl.end())
			hashtbl.erase(i);
		else
			hashtbl.insert(i);
	}
	return vector<int>(hashtbl.begin(), hashtbl.end());
}

vector<int> singleNumber_BM(vector<int>& nums) {

	int xorAB = 0;
	for (auto i : nums)
		xorAB ^= i;

	// the last bit that a diffs b
	int lastDiffBit = xorAB & (xorAB - 1) ^ xorAB;

	int retA = 0, retB = 0;
	for (auto i : nums) {
		// based on the last bit, group the items into groupA(include a) and groupB
		if (lastDiffBit & i)
			retA ^= i;
		else
			retB ^= i;
	}
	return vector<int>{retA, retB};
}

int main()
{
	vector<int> nums = { 1, 2, 1, 3, 2, 5 };
	vector<int> ans1 = { 3, 5 }, ans2 = { 5,3 };

	vector<int> ret1 = singleNumber_HT(nums);
	assert(ret1 == ans1 || ret1 == ans2);
	vector<int> ret2 = singleNumber_BM(nums);
	assert(ret2 == ans1 || ret2 == ans2);

	return 0;
}
