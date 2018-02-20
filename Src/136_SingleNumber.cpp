/* Given an array of integers, every element appears twice
* except for one. Find that single one.
*
* Note:
* Your algorithm should have a linear runtime complexity.
* Could you implement it without using extra memory?
*
*/
#include <vector>

using namespace std;

/*
* The main idea of the algorithm:
*    XOR of two equal numbers is 0 : a^a=0.
*
*/
int singleNumber(vector<int>& nums) {

	int tmp = nums[0];
	for (int i = 1; i < nums.size(); i++)
		tmp ^= nums[i];
	return tmp;

}

int main()
{
	vector<int> nums =  { 1,2,3,4,4,2,1,};
	int ret = singleNumber(nums);
	return 0;
}
