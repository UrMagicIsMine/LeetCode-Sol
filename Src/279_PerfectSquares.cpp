/* Given a positive integer n, find the least number of perfect square numbers
* (for example, 1, 4, 9, 16, ...) which sum to n.
*
* For example, given n = 12, return 3 because 12 = 4 + 4 + 4; given n = 13,
* return 2 because 13 = 4 + 9.
*/

#include <queue>
#include <vector>
#include <cassert>
using namespace std;

int numSquares(int n) {

	vector<int> SQNumsBase;
	vector<int> Visited(n, 0);
	for (int i = 1; i*i <= n; i++) {
		SQNumsBase.push_back(i*i);
		Visited[i*i - 1] = 1;
	}

	if (Visited[n - 1])
		return 1;
	/* QueSQNum stores all the numbers that can be reached
	by the summation of the same number of square numbers, for
	the first level, QueSQNum contains all the square numbers */
	queue<int> QueSQNum;
	for (int i = 0; i < SQNumsBase.size(); i++)
		QueSQNum.push(SQNumsBase[i]);
	int iSumLevel = 1;

	while (!QueSQNum.empty()) {
		iSumLevel++;
		int N = QueSQNum.size();
		for (int i = 0; i<N; i++) {
			int iSQCur = QueSQNum.front();

			for (int j = 0; j<SQNumsBase.size(); j++) {
				int iSum = iSQCur + SQNumsBase[j];
				if (iSum == n)
					return iSumLevel;
				else if (iSum < n &&  Visited[iSum - 1] == 0) {
					// If Visited[iSum - 1] > 0, this is not the first time
					// that we visit this node and we should skip the node (iSum).
					Visited[iSum - 1] = 1;
					QueSQNum.push(iSum);
				}
				else if (iSum > n)
					// We don't need to consider the nodes which are greater ]
					// than n.
					break;
			}
			QueSQNum.pop();
		}
	}
}

int main()
{
	int num = 134;
	int ret = numSquares(num);
	int ans = 3;
	assert(ret == ans);
	return 0;
}
