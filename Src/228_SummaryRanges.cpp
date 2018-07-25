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
		vector<string> resl;
		if(nums.size() == 0)
				return resl;
		int start = nums[0], cnt = 1;
		for(int i = 1; i < nums.size(); i++){
				if(nums[i] - nums[i-1] == 1){
						cnt++;
				}
				else{
						if(cnt == 1)
								resl.push_back(to_string(start));
						else
								resl.push_back(to_string(start) + "->" + to_string(nums[i-1]));
						start = nums[i];
						cnt = 1;
				}
		}
		if(cnt == 1)
				resl.push_back(to_string(start));
		else
				resl.push_back(to_string(start) + "->" + to_string(nums.back()));

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
