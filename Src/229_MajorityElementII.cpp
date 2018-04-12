/* Given an integer array of size n, find all elements that appear more than
* [ n/3 ] times. The algorithm should run in linear time and in O(1) space.
*/

#include <vector>
#include <unordered_map>
#include <stack>
#include <cassert>
using namespace std;

vector<int> majorityElement_HT(vector<int>& nums) {

	unordered_map<int, int> numfreq;
	int N = nums.size() / 3;
	vector<int> resl;
	for (int i = 0; i < nums.size(); i++) {
		numfreq[nums[i]]++;
		if (numfreq[nums[i]] == N + 1)
			resl.push_back(nums[i]);
	}
	return resl;
}

/* Boyer-Moore Majority Vote algorithm generalization to elements appear more 
* than floor(n/k) times*/

vector<int> majorityElement_BM(vector<int>& nums) {

	int x = 0, y = 1, nx = 0, ny = 0;
	for (auto i : nums) {

		if (i == x)
			nx++;
		else if (i == y)
			ny++;
		else if (nx == 0)
			x = i, nx = 1;
		else if (ny == 0)
			y = i, ny = 1;
		else
			nx--, ny--;

	}
	nx = 0, ny = 0;
	for (auto i : nums) {
		if (i == x)
			nx++;
		if (i == y)
			ny++;
	}
	vector<int> resl;
	if (nx > nums.size() / 3)
		resl.push_back(x);
	if (ny > nums.size() / 3)
		resl.push_back(y);

	return resl;
}

int main()
{
	vector<int> nums = { 1, 2, 2, 3, 2, 1, 1, 3 };
	vector<int> ans1 = { 1,2 }, ans2 = { 2,1 };
	vector<int> ret1 = majorityElement_HT(nums);
	assert( ret1 == ans1 || ret1 == ans2 );
	vector<int> ret2 = majorityElement_BM(nums);
	assert(ret2 == ans1 || ret2 == ans2);
	return 0;
}
