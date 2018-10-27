/* Given an array of integers, find if the array contains any duplicates. Your
* function should return true if any value appears at least twice in the array,
* and it should return false if every element is distinct.
*/

#include <unordered_set>
#include <vector>
#include <cassert>
using namespace std;

bool containsDuplicate(vector<int>& nums) {

	unordered_set<int> numset;
	for (auto i : nums)
		if (numset.find(i) == numset.end())
			numset.insert(i);
		else
			return true;

	return false;

}

int main()
{
	vector<int> nums = { 0 };
	bool ret = containsDuplicate(nums);
	bool ans = false;
	assert(ret == ans);
	return 0;
}
