/* Given a char array representing tasks CPU need to do. It contains capital
* letters A to Z where different letters represent different tasks.Tasks could
* be done without original order. Each task could be done in one interval. For
* each interval, CPU could finish one task or just be idle.
*
* However, there is a non-negative cooling interval n that means between two
* same tasks, there must be at least n intervals that CPU are doing different
* tasks or just be idle.
*
* You need to return the least number of intervals the CPU will take to finish all the given tasks.
*
* Example 1:
* Input: tasks = ["A","A","A","B","B","B"], n = 2
* Output: 8
* Explanation: A -> B -> idle -> A -> B -> idle -> A -> B.
* Note:
* The number of tasks is in the range [1, 10000].
* The integer n is in the range [0, 100].
*/

#include <vector>
#include <queue>
#include <unordered_map>
#include <algorithm>
#include <cassert>
using namespace std;

int leastInterval_MT(vector<char>& tasks, int n) {
	int ret = 0;
	unordered_map<char, int> tsMap;
	int maxcnt = 0;
	for (auto c : tasks) {
		tsMap[c]++;
		maxcnt = max(maxcnt, tsMap[c]);
	}
	ret = (maxcnt - 1) * (n + 1);
	for (auto ts : tsMap)
		if (ts.second == maxcnt)
			ret++;

	return max<int>(ret, tasks.size());
}

int leastInterval_PQ(vector<char>& tasks, int n) {
	int ret = 0;

	using P_IC = pair<int, char>;
	auto cmp = [](P_IC p1, P_IC p2) {return p1.first < p2.first;};
	priority_queue<P_IC, vector<P_IC>, decltype(cmp) > taskheap(cmp);


	//auto cmp = [](int left, int right) { return (left ^ 1) < (right ^ 1);};
	//std::priority_queue<int, std::vector<int>, decltype(cmp)> q3(cmp);

	vector<int> tNums(26, 0);
	for (auto t : tasks)
		tNums[t - 'A']++;

	for (int i = 0; i < 26; i++)
		if (tNums[i] > 0)
			taskheap.push(make_pair(tNums[i], i + 'A'));

	while (!taskheap.empty()) {

		int N = min<int>(taskheap.size(), n + 1);
		int tmp = N;

		vector<P_IC> tskTmpVec;

		while (tmp--) {
			P_IC pTop = taskheap.top();
			taskheap.pop();
			pTop.first--;
			if (pTop.first > 0)
				tskTmpVec.push_back(pTop);
			ret++;
		}
		if (N < (n + 1) && (!taskheap.empty() || !tskTmpVec.empty()))
			ret += n + 1 - N;

		for (auto pr : tskTmpVec)
			taskheap.push(pr);
	}

	return ret;
}

int main()
{
	vector<char> tasks = { 'A','A','A','A','A','A','B','C','D','E','F','G' };
	int n = 2;
	int ans = 16;
	int ret1 = leastInterval_MT(tasks, n);
	assert(ret1 == ans);

	int ret2 = leastInterval_MT(tasks, n);
	assert(ret2 == ans);
	return 0;
}
