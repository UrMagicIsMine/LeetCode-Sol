/* You are given an integer array sorted in ascending order (may contain
* duplicates), you need to split them into several subsequences, where each
* subsequences consist of at least 3 consecutive integers. Return whether you
* can make such a split.
*
* Example 1:
* Input: [1,2,3,3,4,5]
* Output: True
* Explanation:
* You can split them into two consecutive subsequences :
* 1, 2, 3
* 3, 4, 5
* Example 2:
* Input: [1,2,3,3,4,4,5,5]
* Output: True
* Explanation:
* You can split them into two consecutive subsequences :
* 1, 2, 3, 4, 5
* 3, 4, 5
* Example 3:
* Input: [1,2,3,4,4,5]
* Output: False
* Note:
* The length of the input is in range of [1, 10000]
*/
#include <unordered_map>
#include <queue>
#include <vector>
#include <algorithm>
#include <functional>
#include <cassert>
using namespace std;

/* greedy algorithm, O(N)
 */

bool isPossible(vector<int>& nums) {

	/* in descending order */
	unordered_map<int, priority_queue<int, vector<int>, greater<int>>> subSqs;

	int need_more = 0;
	for (auto num : nums) {

		if (!subSqs[num - 1].empty()) {

			/* feed the shortest sequence */
			int count = subSqs[num - 1].top();
			/* new sequece now ends in num,
			update the length of subSqs ending in num-1 and num*/
			subSqs[num - 1].pop();
			subSqs[num].push(++count);
			/* already meet the minum length, reduce need_more */
			if (count == 3)
				need_more--;
		}
		else {
			/* insert a new sequence, increase need_more */
			subSqs[num].push(1);
			need_more++;
		}
	}
	return need_more == 0;
}

int main()
{
	vector<int> nums = {1,2,3,3,4,5};
	bool ret = isPossible(nums);
	bool ans = true;
	assert(ret == ans);
	return 0;
}
