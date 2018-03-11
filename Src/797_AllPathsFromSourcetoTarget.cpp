/* Given a directed, acyclic graph of N nodes.  Find all possible paths from node
* 0 to node N-1, and return them in any order.
*
* The graph is given as follows:  the nodes are 0, 1, ..., graph.length - 1.
* graph[i] is a list of all nodes j for which the edge (i, j) exists.
*
* Example:
* Input: [[1,2], [3], [3], []]
* Output: [[0,1,3],[0,2,3]]
* Explanation: The graph looks like this:
* 0--->1
* |    |
* v    v
* 2--->3
* There are two paths: 0 -> 1 -> 3 and 0 -> 2 -> 3.
* Note:
*
* The number of nodes in the graph will be in the range [2, 15].
* You can print different paths in any order, but you should keep the order of
* nodes inside one path.
*/

#include <vector>
#include <cassert>
using namespace std;

typedef vector<int> vec1D;
typedef vector<vec1D> vec2D;

void _DFS(const vec2D& graph, vec2D& resl, vec1D&path, int iNode, int target) {

	if (iNode == target) {
		resl.push_back(path);
	}
	else {
		for (int i = 0; i < graph[iNode].size(); i++)		{
			int nNode = graph[iNode][i];
			path.push_back(nNode);
			_DFS(graph, resl, path, nNode, target);
			path.pop_back();
		}
	}
	return;
}

vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) {
	vec2D resl;

	int N = graph.size();
	if (N == 0)
		return resl;

	vec1D path(1, 0);
	_DFS(graph, resl, path, 0, N - 1);
	return resl;
}

int main()
{
	vector<vector<int>> graph = { {1,2},{3},{3},{} };
	vector<vector<int>> ans = { { 0,1,3 },{ 0,2,3 } };
	auto ret = allPathsSourceTarget(graph);
	assert(ret == ans);
	return 0;
}
