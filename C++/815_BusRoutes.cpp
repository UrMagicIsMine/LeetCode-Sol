/*
We have a list of bus routes. Each routes[i] is a bus route that the i-th bus
repeats forever. For example if routes[0] = [1, 5, 7], this means that the first
bus (0-th indexed) travels in the sequence 1->5->7->1->5->7->1->... forever.

We start at bus stop S (initially not on a bus), and we want to go to bus stop T.
Travelling by buses only, what is the least number of buses we must take to reach
our destination? Return -1 if it is not possible.

Example:
Input:
routes = [[1, 2, 7], [3, 6, 7]]
S = 1
T = 6
Output: 2
Explanation:
The best strategy is take the first bus to the bus stop 7, then take the second
bus to the bus stop 6.
Note:

1 <= routes.length <= 500.
1 <= routes[i].length <= 500.
0 <= routes[i][j] < 10 ^ 6.
*/

#include <vector>
#include <unordered_map>

int numBusesToDestination(vector<vector<int>>& routes, int S, int T) {

	if (S == T) return 0;

	unordered_map<int, vector<int>> s2rMap; // stop -> route
	for (int i = 0; i < routes.size(); i++) {
		for (auto j : routes[i])
			s2rMap[j].push_back(i);
	}

	vector<bool> visited(routes.size(), false); // is route taken
	queue<int> que;
	que.push(S);
	int bus = 0;

	while (!que.empty()) {

		bus++;
		int n = que.size();
		while (n--) {
			int istop = que.front();
			que.pop();

			for (auto route : s2rMap[istop]) {
				if (visited[route]) continue;
				for (auto s : routes[route]) {
					if (s == T) return bus;
					que.push(s);
				}
				visited[route] = true;
			}
		}
	}
	return -1;
}
