/* Find all possible combinations of k numbers that add up to a number n, given
* that only numbers from 1 to 9 can be used and each combination should be a
* unique set of numbers.
*
* Example 1:
*
* Input: k = 3, n = 7
*
* Output:
*
* [[1,2,4]]
*
* Example 2:
*
* Input: k = 3, n = 9
*
* Output:
*
* [[1,2,6], [1,3,5], [2,3,4]]
*/

#include <string>
#include <bitset>
#include <vector>
#include <map>
#include <algorithm>
#include <cassert>
using namespace std;

using vec1D = vector<int>;
using vec2D = vector<vec1D>;

void combineBT(vec2D& resl, vec1D& cur, int curSum, int target, int k, int next) {

	if (cur.size() == k) {
		if(curSum == target)
			resl.push_back(cur);
		return;
	}
	else {

		for (int i = next; i < 10; i++) {

			if (curSum + i <= target && cur.size() < k) {
				cur.push_back(i);
				combineBT(resl, cur, curSum + i, target, k, i + 1);
				cur.pop_back();
			}
		}
	}
	return;
}

vector<vector<int>> combinationSum3(int k, int n) {
	vec2D resl;
	vec1D cur;
	combineBT(resl, cur, 0, n, k, 1);
	return resl;
}

int main()
{
	int num = 1;
	vec2D ret = combinationSum3(3,7);
	vec2D ans = { {1,2,4} };
	assert(ret == ans);
	return 0;
}
