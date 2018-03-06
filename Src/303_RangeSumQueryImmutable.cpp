/*
* Given an integer array nums, find the sum of the elements between indices i
* and j (i <= j), inclusive.
*
* Example:
* Given nums = [-2, 0, 3, -5, 2, -1]
*
* sumRange(0, 2) -> 1
* sumRange(2, 5) -> -1
* sumRange(0, 5) -> -3
* Note:
* You may assume that the array does not change.
* There are many calls to sumRange function.
*
*/

#include <vector>
#include <cassert>
using namespace std;

class NumArray {
public:
	NumArray(vector<int> nums) : _ArraySum(nums) {

		for (int i = 1; i <nums.size(); i++)
			_ArraySum[i] = nums[i] + _ArraySum[i - 1];

	}

	int sumRange(int i, int j) {
		if (i == 0)
			return _ArraySum[j];
		else
			return _ArraySum[j] - _ArraySum[i - 1];
	}

private:
	vector<int> _ArraySum;
};

int main()
{
	vector<int> nums = { 1,2,3,5,1,-2,7 };
	NumArray nArray(nums);

	int ret = nArray.sumRange(1, 5);
	assert(ret == 9);
	return 0;

}
