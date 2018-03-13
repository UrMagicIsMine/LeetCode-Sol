/* You're now a baseball game point recorder.
*
* Given a list of strings, each string can be one of the 4 following types:
*
* Integer (one round's score): Directly represents the number of points you get
*                              in this round.
* "+" (one round's score): Represents that the points you get in this round are
*                          the sum of the last two valid round's points.
* "D" (one round's score): Represents that the points you get in this round are
*                          the doubled data of the last valid round's points.
* "C" (an operation, which isn't a round's score): Represents the last valid
*                          round's points you get were invalid and should be removed.
* Each round's operation is permanent and could have an impact on the round
* before and the round after.
*
* You need to return the sum of the points you could get in all the rounds.
*
* Example 1:
* Input: ["5","-2","4","C","D","9","+","+"]
* Output: 27
* Explanation:
*   Round 1: You could get 5 points. The sum is: 5.
*   Round 2: You could get -2 points. The sum is: 3.
*   Round 3: You could get 4 points. The sum is: 7.
*   Operation 1: The round 3's data is invalid. The sum is: 3.
*   Round 4: You could get -4 points (the round 3's data has been removed). The sum is: -1.
*   Round 5: You could get 9 points. The sum is: 8.
*   Round 6: You could get -4 + 9 = 5 points. The sum is 13.
*   Round 7: You could get 9 + 5 = 14 points. The sum is 27.
* Note:
* -- The size of the input list will be between 1 and 1000.
* -- Every integer represented in the list will be between -30000 and 30000.
*/

#include <string>
#include <vector>
#include <algorithm>
#include <numeric>
#include <cassert>
using namespace std;

int calPoints(vector<string>& ops) {

	vector<int> points;
	int N = 0;
	for (int i = 0; i < ops.size(); i++) {

		if (ops[i] == "C") {
			points.pop_back();
		}
		else if (ops[i] == "D") {
			int i = points.back();
			points.push_back(2 * i);
		}
		else if (ops[i] == "+") {
			points.push_back(points[points.size() - 1] + points[points.size() - 2]);
		}
		else {
			int score = stoi(ops[i]);
			points.push_back(score);
		}
	}
	return accumulate(points.begin(), points.end(), 0);
}

int main()
{
	vector<string> nums = { "5","-2","4","C","D","9","+","+" };
	int ans = 27;

	auto ret1 = calPoints(nums);
	assert(ret1 == ans);
	return 0;
}
