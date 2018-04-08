/* Given an array of integers and an integer k, find out whether there are two
* distinct indices i and j in the array such that nums[i] = nums[j] and the
* absolute difference between i and j is at most k.
*/

#include <vector>
#include <unordered_map>
#include <cassert>
using namespace std;

bool containsNearbyDuplicate(vector<int>& nums, int k) {

	unordered_map<int, int> hashtbl;

	for (int i = 0; i < nums.size(); i++) {
		if (hashtbl.find(nums[i]) != hashtbl.end() && i - hashtbl[nums[i]] <= k)
			return true;
		else
			hashtbl[nums[i]] = i;
	}

	return false;
}
int main()
{
	vector<int> nums = { 2,3,4,5,6,2,3,4 };
	bool ans = true;
	bool ret = containsNearbyDuplicate(nums, 5);
	assert(ret == ans);

	return 0;
}
