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

bool _DFS(const vector<vector<int>> & graphs, vector<bool>& visited, vector<bool>& paths, int i){

		if(graphs[i].size() == 0)
				return true;

		if(paths[i] == true)
				return false;

		paths[i] = true;

		for(int j = 0; j < graphs[i].size(); j++){
				if(visited[graphs[i][j]])
						continue;
				if(!_DFS(graphs, visited, paths, graphs[i][j])){
						return false;
				}
		}
		visited[i] = true;
		paths[i] = false;
		return true;
}

bool canFinish(int numCourses, vector<pair<int, int>>& prerequisites) {

		vector<bool> visited(numCourses, false);
		vector<vector<int>> graphs(numCourses);
		// construct graph;

		for(auto p : prerequisites){
				graphs[p.second].push_back(p.first);
		}

		vector<bool> paths(numCourses, false);

		// traverse and find if there are loops
		for(int i = 0; i < numCourses; i++){
				if(!visited[i] && !_DFS(graphs, visited, paths, i)){
						return false;
				}
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
