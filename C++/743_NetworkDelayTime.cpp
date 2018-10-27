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

		const int INF = 0x00ffffff;
		vector<int> time(N+1, INF);

		typedef pair<int, int> pii_t; // first: dest, second : time
		vector<vector<pii_t>> graph(N+1);
		for(auto & v : times)
				graph[v[0]].emplace_back(v[1], v[2]);

		// first : time, second: node
		priority_queue<pii_t, vector<pii_t>, greater<pii_t>> heap;
		time[K] = 0;
		heap.push(make_pair(0, K));

		while(!heap.empty()){

				pii_t p = heap.top();
				heap.pop();
				int u = p.second;
				if(p.first > time[u]) continue;

				for(auto& ngbr : graph[u]){
						int v = ngbr.first;
						int cost = ngbr.second;
						if(time[v] > time[u] + cost){ // relaxation
								time[v] = time[u] + cost;
								heap.push(make_pair(time[v], v));
						}
				}
		}

		int maxDelay = *max_element(time.begin() + 1, time.end());
		return maxDelay == INF? -1 : maxDelay;

}

/* Bellman-Ford's algorithm, O(VE) */

int networkDelayTime_BF(vector<vector<int>>& times, int N, int K) {

		const int INF = 0x00ffffff;
		vector<int> time(N+1, INF);
		time[K] = 0;
		for(int i = 0; i < N; i++){
				for(auto& e : times){
						int u = e[0];
						int v = e[1];
						int cost = e[2];

						if(time[v] > time[u] + cost){
								time[v] = time[u] + cost;
						}
				}
		}

		int maxDelay = *max_element(time.begin() + 1, time.end());
		return maxDelay == INF? -1 : maxDelay;

}

int main()
{
	vector<vector<int>> times = { {2, 1, 1},{2, 3, 1},{3, 4, 1} };
	int N = 4;
	int K = 2;
	int ans = 2;
	int ret1 = networkDelayTime_DS(times, N, K);
	assert(ret1 == ans);
	int ret2 = networkDelayTime_BF(times, N, K);
	assert(ret2 == ans);
	return 0;
}
