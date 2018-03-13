/* Given a list of daily temperatures, produce a list that, for each day in the
* input, tells you how many days you would have to wait until a warmer temperature.
* If there is no future day for which this is possible, put 0 instead.
*
* For example, given the list temperatures = [73, 74, 75, 71, 69, 72, 76, 73],
* your output should be [1, 1, 4, 2, 1, 1, 0, 0].
*
* Note: The length of temperatures will be in the range [1, 30000]. Each
* temperature will be an integer in the range [30, 100].
*/

#include <stack>
#include <vector>
#include <cassert>
using namespace std;

vector<int> dailyTemperatures(vector<int>& temperatures) {

	int N = temperatures.size();
	vector<int> resl(N, 0);

	stack<pair<int, int>> tempStack;

	for (int i = 0; i < N; i++) {
		while (!tempStack.empty() && tempStack.top().first < temperatures[i]) {
			resl[tempStack.top().second] = i - tempStack.top().second;
			tempStack.pop();
		}
		tempStack.push(make_pair(temperatures[i], i));
	}
	return resl;

}

int main()
{
	vector<int> temperatures = { 73,74,75,71,69,72,76,73 };
	vector<int> ans = { 1,1,4,2,1,1,0,0 };

	auto ret1 = dailyTemperatures(temperatures);
	assert(ret1 == ans);
	return 0;
}
