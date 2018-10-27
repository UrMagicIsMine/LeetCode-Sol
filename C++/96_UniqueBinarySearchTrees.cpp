/* Given n, how many structurally unique BST's (binary search trees) that store
values 1 ... n?

Example:

Input: 3
Output: 5
Explanation:
Given n = 3, there are a total of 5 unique BST's:

   1         3     3      2      1
    \       /     /      / \      \
     3     2     1      1   3      2
    /     /       \                 \
   2     1         2                 3
*/
#include <vector>
#include <map>
#include <cassert>
using namespace std;

int _DFS(map<pair<int, int>, int>& numMaps, int beg, int end) {

	auto p = make_pair(beg, end);
	if (numMaps.find(p) != numMaps.end())
		return numMaps[p];

	int ret = 0;
	if (beg >= end)
		ret = 1;
	else {
		for (int i = beg; i <= end; i++) {
			int lf = _DFS(numMaps, beg, i - 1);
			int lr = _DFS(numMaps, i + 1, end);
			ret += lf * lr;
		}
	}
	numMaps[p] = ret;
	return ret;
}

int numTrees(int n) {
	if (n == 0)
		return 0;

	map<pair<int, int>, int> numMaps;
	return _DFS(numMaps, 1, n);
}

int numTrees(int n) {
		vector<int> dp(n+1, 0);
		dp[0] = 1;
		dp[1] = 1;
		for(int i = 2; i <= n; i++){
				for(int top = 1; top <= i; top++){
						dp[i] += dp[top-1] * dp[i-top];
				}
		}
		return dp[n];
}

int main()
{
	int n = 18;
	int ans = 477638700;
	int ret = numTrees(n);
	assert(ret == ans);
	return 0;
}
