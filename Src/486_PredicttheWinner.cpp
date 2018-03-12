/* Given an array of scores that are non-negative integers. Player 1 picks one
* of the numbers from either end of the array followed by the player 2 and then
* player 1 and so on. Each time a player picks a number, that number will not be
* available for the next player. This continues until all the scores have been
* chosen. The player with the maximum score wins.
*
* Given an array of scores, predict whether player 1 is the winner. You can
* assume each player plays to maximize his score.
*
* Example 1:
*   Input: [1, 5, 2]
*   Output: False
*   Explanation: Initially, player 1 can choose between 1 and 2.
*                If he chooses 2 (or 1), then player 2 can choose from 1 (or 2)
*                and 5. If player 2 chooses 5, then player 1 will be left with 1 (or 2).
*                So, final score of player 1 is 1 + 2 = 3, and player 2 is 5.
*                Hence, player 1 will never be the winner and you need to return False.
* Example 2:
*   Input: [1, 5, 233, 7]
*   Output: True
*   Explanation: Player 1 first chooses 1. Then player 2 have to choose between
*                5 and 7. No matter which number player 2 choose, player 1 can
*                choose 233. Finally, player 1 has more score (234) than player 2 (12),
*                so you need to return True representing player1 can win.
Note:
  -- 1 <= length of the array <= 20.
  -- Any scores in the given array are non-negative integers and will not exceed 10,000,000.
  -- If the scores of both players are equal, then player 1 is still the winner.
*/

#include <vector>
#include <algorithm>
#include <cassert>
using namespace std;


/* DP solution, O(1)
* dp(i, j) stores the score difference between player1 and player 2 for an given
* array A[i, j], if dp(0,N - 1) >=0 means palyer1 win;
* Update formula:
*     dp(i, j) = max(nums[j] - dp(i, j-1), nums[i] - dp(i+1, j));
*/
bool PredictTheWinner(vector<int>& nums) {

	int N = nums.size();
	//difference of player one who first starts minus player two in the range of [i,j];
	vector<vector<int>> dp(N, vector<int>(N, 0));

	for (int i = 0; i<N; i++)
		dp[i][i] = nums[i];

	/* Loop sub array with length = 2, 3, ... N */
	for (int Len = 2; Len <= N; Len++) {
		/* Update dp(i,j) for every sub-array with length == Len, window sliding */
		for (int i = 0, j = Len - 1; j<N; i++, j++) {
			dp[i][j] = max(nums[j] - dp[i][j - 1], nums[i] - dp[i + 1][j]);
		}
	}
	return dp[0][N - 1] >= 0;
}

int main()
{
	vector<int> nums = { 1,5,2 };
	int ans = false;

	auto ret1 = PredictTheWinner(nums);
	assert(ret1 == ans);
	return 0;
}
