/* There are a total of n courses you have to take, labeled from 0 to n - 1.
*
* Some courses may have prerequisites, for example to take course 0 you have to
* first take course 1, which is expressed as a pair: [0,1]
*
* Given the total number of courses and a list of prerequisite pairs, return the
* ordering of courses you should take to finish all courses.
*
* There may be multiple correct orders, you just need to return one of them. If
* it is impossible to finish all courses, return an empty array.
*
* For example:
*
* 2, [[1,0]]
* There are a total of 2 courses to take. To take course 1 you should have finished
* course 0. So the correct course order is [0,1]
*
* 4, [[1,0],[2,0],[3,1],[3,2]]
* There are a total of 4 courses to take. To take course 3 you should have finished
* both courses 1 and 2. Both courses 1 and 2 should be taken after you finished
* course 0. So one correct course order is [0,1,2,3]. Another correct ordering is
* [0,2,1,3].
*
* Note:
*
* The input prerequisites is a graph represented by a list of edges, not adjacency
* matrices. Read more about how a graph is represented.
* You may assume that there are no duplicate edges in the input prerequisites.
*
*
* click to show more hints.
*
* Hints:
*
* This problem is equivalent to finding the topological order in a directed graph.
* If a cycle exists, no topological ordering exists and therefore it will be
* impossible to take all courses.
* Topological Sort via DFS - A great video tutorial (21 minutes) on Coursera
* explaining the basic concepts of Topological Sort.
* Topological sort could also be done via BFS.
* 
*/

#include <vector>
#include <algorithm>
#include <numeric>
#include <functional>
#include <unordered_map>
#include <queue>
#include <cassert>
using namespace std;

bool _DFS(unordered_map<int, vector<int>> & graphs, vector<bool>& onpath, vector<bool>& visited, vector<int>& nodes, int iNode) {

	/* cycle detected */
	if (onpath[iNode])
		return false;

	/* visited already? */
	if (visited[iNode])
		return true;

	visited[iNode] = true;
	onpath[iNode] = true;
	for (int i = 0; i < graphs[iNode].size(); i++) {
		int iNext = graphs[iNode][i];
		int ret = _DFS(graphs, onpath, visited, nodes, iNext);
		if (ret == false)
			return false;
	}
	onpath[iNode] = false;
	nodes.push_back(iNode);
	return true;
}

vector<int> findOrder(int numCourses, vector<pair<int, int>>& prerequisites) {

	unordered_map<int, vector<int>> graphs;
	for (int i = 0; i < prerequisites.size(); i++)
		graphs[prerequisites[i].second].push_back(prerequisites[i].first);

	vector<int> nodes;
	vector<bool> visited(numCourses, false);
	vector<bool> onpath(numCourses, false);
	for (int i = 0; i < numCourses; i++) {

		if (!visited[i]) {

			int ret = _DFS(graphs, onpath, visited, nodes, i);
			if (ret == false)
				return vector<int>();
		}
	}
	reverse(nodes.begin(), nodes.end());
	return nodes;
}

int main()
{
	int numCourses = 4;
	vector<pair<int, int>> prerequisites = { {1, 0},{2, 0},{3, 1},{3, 2} };
	vector<int> ret = findOrder(numCourses, prerequisites);
	vector<int> ans = {0,2,1,3};
	assert(ret == ans);
	return 0;
}
