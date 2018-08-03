/*
Given n nodes labeled from 0 to n-1 and a list of undirected edges (each edge is
a pair of nodes), write a function to check whether these edges make up a valid
tree.

Example 1:

Input: n = 5, and edges = [[0,1], [0,2], [0,3], [1,4]]
Output: true
Example 2:

Input: n = 5, and edges = [[0,1], [1,2], [2,3], [1,3], [1,4]]
Output: false
Note: you can assume that no duplicate edges will appear in edges. Since all edges
are undirected, [0,1] is the same as [1,0] and thus will not appear together in
edges.
*/

#include <vector>
using namespace std;

bool _DFS(vector<vector<int>> & graph, vector<bool>& visited, int idx, int parent) {
	if (visited[idx] == true)
		return false;

	visited[idx] = true;

	for (auto i : graph[idx]) {
		if (i == parent) continue;
		if (_DFS(graph, visited, i, idx) == false)
			return false;
	}
	return true;
}

bool validTree(int n, vector<pair<int, int>>& edges) {
	vector<vector<int>> graph(n);
	for (auto & e : edges) {
		graph[e.first].push_back(e.second);
		graph[e.second].push_back(e.first);
	}

	vector<bool> visited(n, false);

	/* determine has cycle */
	if (_DFS(graph, visited, 0, -1) == false)
		return false;

	/* determine if all are connected */
	for (auto v : visited) {
		if (v == false)
			return false;
	}
	return true;
}


// BFS solution

bool validTree(int n, vector<pair<int, int>>& edges) {
	vector<unordered_set<int>> graph(n);
	for (auto &e : edges) {
		graph[e.first].insert(e.second);
		graph[e.second].insert(e.first);
	}

	vector<bool> visited(n, false);
	queue<int> que;
	que.push(0);

	while (!que.empty()) {

		int node = que.front();
		que.pop();
		if (visited[node]) return false;
		visited[node] = true;
		n--;
		for (auto ngbr : graph[node]) {
			graph[ngbr].erase(node); // delete parent
			que.push(ngbr);
		}

	}
	return n == 0;
}

// Union Find Set solution

class UnionFindSet {

public:
	UnionFindSet(int n) : _par(n, 0), _rank(n, 0) {
		for (int i = 0; i < n; i++)
			_par[i] = i;
	}

	int find(int x) {
		if (x == _par[x])
			return x;
		else
			return _par[x] = find(_par[x]); // path compression;
	}

	bool Union(int x, int y) {
		int rx = find(x);
		int ry = find(y);

		if (rx == ry)
			return false;

		if (_rank[rx] < _rank[ry])
			_par[rx] = ry;
		else {
			_par[ry] = rx;
			if (_rank[rx] == _rank[ry])
				_rank[rx]++;
		}
		return true;
	}

private:
	vector<int> _par;
	vector<int> _rank;

};

bool validTree(int n, vector<pair<int, int>>& edges) {

	if ((n - 1) != edges.size())
		return false;

	UnionFindSet s(n);

	for (auto& e : edges) {
		if (!s.Union(e.first, e.second))
			return false;
	}
	return true;
}

int main() {
	int n = 5;
	vector<pair<int, int>> edges = { {0,1 }, { 2,1 }, { 2,0 }, { 2,4 } };
	bool ret = validTree(n, edges);
	return 0;
}
