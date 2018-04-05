/* There are N network nodes, labelled 1 to N.
*
* Given times, a list of travel times as directed edges times[i] = (u, v, w),
* where u is the source node, v is the target node, and w is the time it takes
* for a signal to travel from source to target.
*
* Now, we send a signal from a certain node K. How long will it take for all nodes
* to receive the signal? If it is impossible, return -1.
*
* Note:
* N will be in the range [1, 100].
* K will be in the range [1, N].
* The length of times will be in the range [1, 6000].
* All edges times[i] = (u, v, w) will have 1 <= u, v <= N and 1 <= w <= 100.
*/

#include <vector>
#include <algorithm>
#include <numeric>
#include <functional>
#include <unordered_map>
#include <queue>
#include <cassert>
using namespace std;


/* Dijkstra's algorithm, O(ElogE) */

int networkDelayTime_DS(vector<vector<int>>& times, int N, int K) {

	/* construct the graph */
	unordered_map<int, vector<vector<int>>> graph;
	for (int i = 0; i < times.size(); i++) {

		int u = times[i][0];
		int v = times[i][1];
		int w = times[i][2];

		vector<int> tmp(2, 0);
		tmp[0] = v;
		tmp[1] = w;
		graph[u].emplace_back(tmp);
	}

	using PII = pair<int, int>;
	auto lambda = [](PII& p1, PII& p2) {
		return p1.first > p2.first;
	};

	vector<bool> visited(N + 1, false);
	vector<int> darray(N + 1, INT_MAX);
	darray[K] = 0;

	priority_queue<PII, vector<PII>, decltype(lambda)> heap(lambda);
	heap.emplace(make_pair(0, K));

	while (!heap.empty()) {

		int itop = heap.top().second;
		heap.pop();
		visited[itop] = true;

		for (int i = 0; i < graph[itop].size(); i++) {

			int u = graph[itop][i][0];
			int w = graph[itop][i][1];

			if (!visited[u] && darray[u] > darray[itop] + w) {
				darray[u] = darray[itop] + w;
				heap.emplace(make_pair(darray[u], u));
			}
		}
	}

	int maxtime = *max_element(darray.begin() + 1, darray.end());
	return maxtime == INT_MAX ? -1 : maxtime;

}

/* Dijkstra's algorithm, O(VE) */

int networkDelayTime_BF(vector<vector<int>>& times, int N, int K) {

	/* construct the graph */
	unordered_map<int, vector<vector<int>>> graph;
	for (int i = 0; i < times.size(); i++) {

		int u = times[i][0];
		int v = times[i][1];
		int w = times[i][2];

		vector<int> tmp(2, 0);
		tmp[0] = v;
		tmp[1] = w;
		graph[u].emplace_back(tmp);
	}

	vector<int> darray(N + 1, INT_MAX);
	darray[K] = 0;
	for (int i = 1; i < N; i++) {

		for (int e = 0; e < times.size(); e++) {
			int u = times[e][0];
			int v = times[e][1];
			int w = times[e][2];

			if (darray[u] != INT_MAX && darray[v] > darray[u] + w)
				darray[v] = darray[u] + w;
		}

	}

	int maxtime = *max_element(darray.begin() + 1, darray.end());
	return maxtime == INT_MAX ? -1 : maxtime;
}

int main()
{
	vector<vector<int>> times = { {2, 1, 1},{2, 3, 1},{3, 4, 1} };
	int N = 4;
	int K = 2;
	int ans = 2;
	int ret1 = networkDelayTime_DS(times, N, K);
	assert(ret1 == ans);
	int ret2 = networkDelayTime_DS(times, N, K);
	assert(ret2 == ans);
	return 0;
}
