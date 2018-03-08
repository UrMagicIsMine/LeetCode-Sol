/* For a undirected graph with tree characteristics, we can choose any node as
* the root. The result graph is then a rooted tree. Among all possible rooted
* trees, those with minimum height are called minimum height trees (MHTs). Given
* such a graph, write a function to find all the MHTs and return a list of their
* root labels.
*
* Format
* The graph contains n nodes which are labeled from 0 to n - 1. You will be given
* the number n and a list of undirected edges (each edge is a pair of labels).
*
* You can assume that no duplicate edges will appear in edges. Since all edges
* are undirected, [0, 1] is the same as [1, 0] and thus will not appear together
* in edges.
*
* Example 1:
*
* Given n = 4, edges = [[1, 0], [1, 2], [1, 3]]
*
*         0
*         |
*         1
*        / \
*       2   3
* return [1]
*
* Example 2:
*
* Given n = 6, edges = [[0, 3], [1, 3], [2, 3], [4, 3], [5, 4]]
*
*      0  1  2
*       \ | /
*         3
*         |
*         4
*         |
*         5
* return [3, 4]
*
* Note:
*
* (1) According to the definition of tree on Wikipedia: “a tree is an undirected
* graph in which any two vertices are connected by exactly one path. In other words,
* any connected graph without simple cycles is a tree.”
*
* (2) The height of a rooted tree is the number of edges on the longest downward
* path between the root and a leaf.
*/

#include <vector>
#include <set>
#include <cassert>
using namespace std;

/* The basic idea is "keep deleting leaves layer-by-layer, until reach the root."
* Specifically, first find all the leaves, then remove them. After removing, some
* nodes will become new leaves. So we can continue remove them. Eventually, there
* is only 1 or 2 nodes left. If there is only one node left, it is the root. If
* there are 2 nodes, either of them could be a possible root.
*
* Time Complexity: Since each node will be removed at most once, the complexity is O(n).*/

vector<int> findMinHeightTrees(int n, vector<pair<int, int>>& edges) {

	if (n == 1)
		return vector<int>{0};
	if (n == 2)
		return vector<int>{1, 2};

	vector<int> resl;

	vector<set<int>> neigbourVec(n);
	/* build connectivity table */
	for (auto& it : edges) {
		neigbourVec[it.first].insert(it.second);
		neigbourVec[it.second].insert(it.first);
	}

	/* find all the leaf node */
	vector<int> leaves_Prev;
	for (int i = 0; i < n; i++) {
		if (neigbourVec[i].size() == 1)
			leaves_Prev.push_back(i);
	}

	/* delete the leaf node repeatedly */
	vector<int> leaves_Post;
	while (true) {
		leaves_Post.clear();
		for (auto leaf : leaves_Prev) {
			if (!neigbourVec[leaf].empty()) {
				int node = *(neigbourVec[leaf].begin());
				neigbourVec[node].erase(leaf);
				/* save the new leaft node */
				if (neigbourVec[node].size() == 1)
					leaves_Post.push_back(node);
			}
		}

		if (leaves_Post.empty())
			return leaves_Prev;

		swap(leaves_Prev, leaves_Post);
	}

}

int main()
{
	vector<pair<int,int>> edges = { { 1, 0 },{ 1, 2 },{ 1, 3 } };
	vector<int> ret1 = findMinHeightTrees(4, edges);
	vector<int> ans1 = { 1 };
	assert(ret1 == ans1);

	vector<pair<int, int>> edges2 = { { 0, 1 },{ 0, 2 },{ 0, 3 },{ 3, 4 },{ 5, 4 } };
	vector<int> ret2 = findMinHeightTrees(6, edges2);
	vector<int> ans2 = { 3 };
	assert(ret2 == ans2);
	return 0;

}
