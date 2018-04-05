/* There are a total of n courses you have to take, labeled from 0 to n - 1.
*
* Some courses may have prerequisites, for example to take course 0 you have to
* first take course 1, which is expressed as a pair: [0,1]
*
* Given the total number of courses and a list of prerequisite pairs, is it possible
* for you to finish all courses?
*
* For example:
*
* 2, [[1,0]]
* There are a total of 2 courses to take. To take course 1 you should have finished
* course 0. So it is possible.
*
* 2, [[1,0],[0,1]]
* There are a total of 2 courses to take. To take course 1 you should have finished
* course 0, and to take course 0 you should also have finished course 1. So it is
* impossible.
*
* Note:
* The input prerequisites is a graph represented by a list of edges, not adjacency
* matrices. Read more about how a graph is represented.
* You may assume that there are no duplicate edges in the input prerequisites.
*/

#include <vector>
#include <algorithm>
#include <numeric>
#include <functional>
#include <unordered_map>
#include <queue>
#include <cassert>
using namespace std;

int _DFS(unordered_map<int, vector<int>>& graphs, vector<int>& finishable, vector<bool>& visited, int iNode) {

	if (finishable[iNode] != -1)
		return finishable[iNode];

	if (visited[iNode] == true) {
		finishable[iNode] = 0;
		return 0;
	}

	visited[iNode] = true;
	for (int i = 0; i < graphs[iNode].size(); i++) {
		int ret = _DFS(graphs, finishable, visited, graphs[iNode][i]);
		if (ret == 0) {
			finishable[iNode] = 0;
			return 0;
		}
	}
	visited[iNode] = false;
	finishable[iNode] = 1;
	return 1;
}

bool canFinish(int numCourses, vector<pair<int, int>>& prerequisites) {

	unordered_map<int, vector<int>> graphs;
	for (int i = 0; i < prerequisites.size(); i++)
		graphs[prerequisites[i].first].push_back(prerequisites[i].second);

	int N = numCourses;
	vector<int> finishable(N, -1);

	for (int i = 0; i < N; i++) {
		vector<bool> visited(N, false);
		if (finishable[i] == -1) {
			_DFS(graphs, finishable, visited, i);
		}
		if (finishable[i] == 0)
			return false;
	}
	return true;

}

int main()
{
	int numCourses = 2;
	vector<pair<int, int>> prerequisites = { {0,1}, {1,0} };
	bool ret = canFinish(numCourses, prerequisites);
	bool ans = false;
	assert(ret == ans);
	return 0;
}
