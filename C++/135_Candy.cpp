/* There are N children standing in a line. Each child is assigned a rating value.
*
* You are giving candies to these children subjected to the following requirements:
*
* Each child must have at least one candy.
* Children with a higher rating get more candies than their neighbors.
* What is the minimum candies you must give?
*
* Example 1:
*
* Input: [1,0,2]
* Output: 5
* Explanation: You can allocate to the first, second and third child with 2, 1, 2
* candies respectively.
* Example 2:
*
* Input: [1,2,2]
* Output: 4
* Explanation: You can allocate to the first, second and third child with 1, 2, 1
* candies respectively. The third child gets 1 candy because it satisfies the
* above two conditions.
*/

#include <vector>
#include <numeric>
#include <algorithm>
#include <cassert>
using namespace std;

/* One simple solution is to do two scans:
1) one foward scan (from 1 to N-1) to make sure child i has more candies than its
left neighbor if its rate is higher than its left neighbor. After the forward scan,
we can guarantee that the left neighbor relationship is correct but we have to do
more to make the right neighbor relationship in order;
2) do the backwarad scan (from N-2 to 0) to make child i has more candies than
its right neighbor i+1 if its rate is higher than its right neighbor. */

int candy(vector<int>& ratings) {
	int N = ratings.size();
	vector<int> candies(N, 1);
	for (int i = 1; i < N; i++) {
		if (ratings[i] > ratings[i - 1])
			candies[i] = candies[i - 1] + 1;
	}
	for (int i = N - 2; i >= 0; i--) {
		if (ratings[i] > ratings[i + 1])
			candies[i] = max(candies[i], candies[i + 1] + 1);
	}

	return accumulate(candies.begin(), candies.end(), 0);
}

int main()
{
	vector<int> ratings = { 1,0,2 };
	int ans = 5;
	int ret = candy(ratings);
	assert(ret == ans);
	return 0;
}
