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

	/* QueSQNum stores all the numbers that can be reached
	by the summation of the same number of square numbers, for
	the first level, QueSQNum contains all the square numbers */

	queue<int> sumque;
	int level = 0;
	QueSQNum.push(0);
	vector<bool> visited(n+1, false);

	while(!QueSQNum.empty()){
		level++;
		int N = QueSQNum.size();
		for(int i = 0; i < N; i++){
			int cur = QueSQNum.front();
			for(int j = 1; j*j <= n; j++){
				int tmp = cur + j*j;
				if( tmp == n ){
						return level;
				}
				else if ( tmp < n && visited[tmp] == false ){
					// If Visited[iSum] == true, this is not the first time
					// that we visit this node and we should skip the node (iSum).
					visited[tmp] == true;
					QueSQNum.push(tmp);
				}
				else if( tmp > n )
					// We don't need to consider the nodes which are greater than n.
					break;
				}
				QueSQNum.pop();
		}
	}
	return -1;
}

int main()
{
	int num = 134;
	int ret = numSquares(num);
	int ans = 3;
	assert(ret == ans);
	return 0;
}
