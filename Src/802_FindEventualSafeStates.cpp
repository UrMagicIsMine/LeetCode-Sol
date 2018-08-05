/* In a directed graph, we start at some node and every turn, walk along a directed
* edge of the graph.  If we reach a node that is terminal (that is, it has no
* outgoing directed edges), we stop.
*
* Now, say our starting node is eventually safe if and only if we must eventually
* walk to a terminal node.  More specifically, there exists a natural number K so
* that for any choice of where to walk, we must have stopped at a terminal node
* in less than K steps.
*
* Which nodes are eventually safe?  Return them as an array in sorted order.
*
* The directed graph has N nodes with labels 0, 1, ..., N-1, where N is the length
* of graph.  The graph is given in the following form: graph[i] is a list of labels
* j such that (i, j) is a directed edge of the graph.
*
* Example:
* Input: graph = [[1,2],[2,3],[5],[0],[5],[],[]]
* Output: [2,4,5,6]
* Here is a diagram of the above graph.
*
* Illustration of graph
*
* Note:
*
* graph will have length at most 10000.
* The number of edges in the graph will not exceed 32000.
* Each graph[i] will be a sorted list of different integers, chosen within the
* range [0, graph.length - 1].
*/

#include <vector>
#include <algorithm>
#include <numeric>
#include <functional>
#include <unordered_map>
#include <queue>
#include <cassert>
using namespace std;

int _DFS(vector<vector<int>>& graph, vector<bool>& visited, vector<int>& safe, int iNode) {

	if (visited[iNode])
		return 0;

	if (safe[iNode] != -1)
		return safe[iNode];

	if (graph[iNode].size() == 0) {
		safe[iNode] = 1;
		return 1;
	}

	visited[iNode] = true;
	for (int i = 0; i < graph[iNode].size(); i++) {
		int ret = _DFS(graph, visited, safe, graph[iNode][i]);
		if (ret == 0) {
			safe[iNode] = 0;
			return 0;;
		}
	}
	visited[iNode] = false;
	safe[iNode] = 1;
	return 1;
}

vector<int> eventualSafeNodes(vector<vector<int>>& graph) {

	int N = graph.size();

	/* -1 unknown, 0 unsafe, 1 safe */
	vector<int> safe(N, -1);

	vector<int> resl;
	for (int i = 0; i < N; i++) {
		if (safe[i] == -1) {
			vector<bool> visited(N, false);
			_DFS(graph, visited, safe, i);
		}
		if (safe[i] == 1) {
			resl.push_back(i);
		}
	}
	return resl;
}

// updated solution

vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
	int n = graph.size();

	vector<int> status(n, 0);
	vector<bool> paths(n, false);

	vector<int> ret;
	for(int i = 0; i < n; i++){
		if(status[i] == 0){
			_DFS(graph, status, paths, i);
		}
		if(status[i] ==1)
			ret.push_back(i);
	}
	return ret;
}

bool _DFS(vector<vector<int>>& graph, vector<int>& status, vector<bool>&paths, int idx){
	if(paths[idx] == true){
		return false; // detect cycle
	}

	paths[idx] = true;
	for(auto i : graph[idx]){
		// child goes into cycle or detected cycle
		if(status[i] == -1 || (status[i] == 0 && _DFS(graph, status, paths, i) == false)){
			status[idx] = -1;
			paths[idx] = false;
			return false;
		}
	}
	paths[idx] = false;
	status[idx] = 1; // means safe
	return true;
}

int main()
{
	vector<vector<int>> graph = { {1, 2},{2, 3},{5},{0},{5},{},{} };
	vector<int> ret = eventualSafeNodes(graph);
	vector<int> ans = { 2,4,5,6 };
	assert(ret == ans);
	return 0;
}
