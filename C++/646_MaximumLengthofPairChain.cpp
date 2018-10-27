/* You are given n pairs of numbers. In every pair, the first number is always
* smaller than the second number.
*
* Now, we define a pair (c, d) can follow another pair (a, b) if and only if
* b < c. Chain of pairs can be formed in this fashion.
*
* Given a set of pairs, find the length longest chain which can be formed. You
* needn't use up all the given pairs. You can select pairs in any order.
*
* Example 1:
* Input: [[1,2], [2,3], [3,4]]
* Output: 2
* Explanation: The longest chain is [1,2] -> [3,4]
* Note:
* The number of given pairs will be in the range [1, 1000].
*/

#include <vector>
#include <algorithm>
#include <cassert>
using namespace std;

/* DP solution, O(n^2) */
int findLongestChain(vector<vector<int>>& pairs) {

	int N = pairs.size();
	if (N == 0)
		return 0;

	auto CompFunc = [](vector<int>& p1, vector<int>& p2) {
		if (p1[0] == p2[0])
			return p1[1] < p2[1];
		else
			return p1[0] < p2[0];
	};
	sort(pairs.begin(), pairs.end(), CompFunc);

	vector<int> LenDP(N, 1);
	int endPnt = pairs[0][1];
	for (int i = 1; i < N; i++) {
		if (pairs[i][0] > endPnt) {
			LenDP[i] = LenDP[i - 1] + 1;
			endPnt = pairs[i][1];
		}
		else
			LenDP[i] = LenDP[i - 1];

		if (pairs[i][1] < endPnt) {
			endPnt = pairs[i][1];
		}
	}

	return LenDP[N - 1];

}

int main()
{
	vector<vector<int>> pairs = { {1,2},{ 2,3 },{ 3,4 } };
	int ans = 2;
	auto ret1 = findLongestChain(pairs);
	assert(ret1 == ans);

	return 0;
}
