/* Given an array of integers that is already sorted in ascending order, find
* two numbers such that they add up to a specific target number.
*
* The function twoSum should return indices of the two numbers such that they
* add up to the target, where index1 must be less than index2. Please note that
*  your returned answers (both index1 and index2) are not zero-based.
*
* You may assume that each input would have exactly one solution and you may
* not use the same element twice.
*
* Input: numbers={2, 7, 11, 15}, target=9
* Output: index1=1, index2=2
*/

#include <vector>
#include <cassert>
using namespace std;

vector<int> twoSum(vector<int>& numbers, int target) {

	int N = numbers.size();
	for (int ibeg = 0, iend = N - 1; ibeg < iend; ) {
		int sum = numbers[ibeg] + numbers[iend];
		if (sum == target)
			return vector<int>({ ibeg + 1,iend + 1 });
		else if (sum < target)
			ibeg++;
		else
			iend--;
	}
	assert(0);
}

int main()
{
	std::vector<int> ver1 = { 1,3,5,6,9 };
	vector<int> ret = twoSum(ver1, 11);
	vector<int> ans = { 3,4 };
	assert(ret == ans);
	return 0;
}
