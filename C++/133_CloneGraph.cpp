/* Clone an undirected graph. Each node in the graph contains a label and a list
*  of its neighbors.
*
* OJ's undirected graph serialization:
* Nodes are labeled uniquely.
*
* We use # as a separator for each node, and , as a separator for node label and
* each neighbor of the node.
* As an example, consider the serialized graph {0,1,2#1,2#2,2}.
*
* The graph has a total of three nodes, and therefore contains three parts as
* separated by #.
*
* First node is labeled as 0. Connect node 0 to both nodes 1 and 2.
* Second node is labeled as 1. Connect node 1 to node 2.
* Third node is labeled as 2. Connect node 2 to node 2 (itself), thus forming a
* self-cycle.
* Visually, the graph looks like the following:
*
*        1
*       / \
*      /   \
*     0 --- 2
*          / \
*          \_/
*
*/

#include <vector>
#include <queue>
#include <unordered_map>
#include <cassert>
using namespace std;

/**
* Definition for undirected graph.
*/
struct UndirectedGraphNode {
	int label;
	vector<UndirectedGraphNode *> neighbors;
	UndirectedGraphNode(int x) : label(x) {};
};

typedef UndirectedGraphNode UDGNode;
typedef unordered_map<UDGNode*, UDGNode*> UDGNodesHash;

UndirectedGraphNode *_getGraphNode(UndirectedGraphNode *node, UDGNodesHash& htable) {
	/* return null; */
	if (!node)
		return nullptr;

	if (htable.find(node) == htable.end()) {
		UDGNode * pNode = new UDGNode(node->label);
		htable[node] = pNode;
		int N = (node->neighbors).size();
		(pNode->neighbors).reserve(N);
		for (int i = 0; i < N; i++) {
			pNode->neighbors.push_back(_getGraphNode((node->neighbors)[i], htable));
		}
		return pNode;
	}
	return htable[node];

}

UndirectedGraphNode *cloneGraph_DFS(UndirectedGraphNode *node) {

	UDGNodesHash htable;
	return _getGraphNode(node, htable);
}

UndirectedGraphNode *cloneGraph_BFS(UndirectedGraphNode *node) {
	if (!node)
		return nullptr;
	unordered_map<UndirectedGraphNode*, UndirectedGraphNode*> nodeMaps;
	queue<UndirectedGraphNode*> queNodes;
	queNodes.push(node);
	UndirectedGraphNode* cur = new UndirectedGraphNode(node->label);
	nodeMaps[node] = cur;
	while (!queNodes.empty()) {
		UndirectedGraphNode* pNode = queNodes.front();
		queNodes.pop();
		vector<UndirectedGraphNode *>& nbs = pNode->neighbors;
		for (int i = 0; i < nbs.size(); i++) {

			if (nodeMaps.find(nbs[i]) == nodeMaps.end()) {

				UndirectedGraphNode* pNew = new UndirectedGraphNode(nbs[i]->label);
				nodeMaps[nbs[i]] = pNew;
				queNodes.push(nbs[i]);
			}
			nodeMaps[pNode]->neighbors.push_back(nodeMaps[nbs[i]]);

		}
	}
	return nodeMaps[node];
}

int main()
{
	UndirectedGraphNode *pNode1 = new UndirectedGraphNode(0);
	UndirectedGraphNode *pNode2 = new UndirectedGraphNode(1);
	UndirectedGraphNode *pNode3 = new UndirectedGraphNode(2);
	pNode1->neighbors.push_back(pNode2);
	pNode1->neighbors.push_back(pNode3);
	pNode2->neighbors.push_back(pNode3);
	pNode3->neighbors.push_back(pNode3);
	UndirectedGraphNode *pRet = cloneGraph_BFS(pNode1);
	return 0;
}
