/* Two elements of a binary search tree (BST) are swapped by mistake.

Recover the tree without changing its structure.

Example 1:

Input: [1,3,null,null,2]

   1
  /
 3
  \
   2

Output: [3,1,null,null,2]

   3
  /
 1
  \
   2
Example 2:

Input: [3,1,4,null,null,2]

  3
 / \
1   4
   /
  2

Output: [2,1,4,null,null,3]

  2
 / \
1   4
   /
  3
Follow up:

A solution using O(n) space is pretty straight forward.
Could you devise a constant space solution?

*/
#include <vector>
#include <string>
#include <algorithm>
#include <cassert>
using namespace std;

/**
* Definition for a binary tree node.
*/
struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

void _inOrder(vector<TreeNode*>& NodeVec, TreeNode* pNode) {
	if (pNode) {
		_inOrder(NodeVec, pNode->left);
		NodeVec.push_back(pNode);
		_inOrder(NodeVec, pNode->right);
	}
	return;
}

void recoverTree_Sln1(TreeNode* root) {

	vector<TreeNode*> NodeVec;
	_inOrder(NodeVec, root);
	vector<int> NodeVals(NodeVec.size(), 0);

	int i = 0;
	for (auto p : NodeVec)
		NodeVals[i++] = p->val;
	i = 0;
	sort(NodeVals.begin(), NodeVals.end());
	for (auto p : NodeVec)
		p->val = NodeVals[i++];

	return;
}

/* solution 2, Find 
First Node that is larger than it's next
Second Node that is smaller than it's smaller than it's previous
*/

void _inOrder2(TreeNode* pNode, TreeNode* &p1, TreeNode* &p2, TreeNode*& pPrev){
		if(pNode){
				_inOrder2(pNode->left, p1, p2, pPrev);

				if(pPrev && !p1 && pNode->val <= pPrev->val)
						p1 = pPrev;
				if(pPrev && p1 && pNode->val <= pPrev->val)
						p2 = pNode;

				pPrev = pNode;

				_inOrder2(pNode->right, p1, p2, pPrev);
		}
		return;
}

void recoverTree_Sln2(TreeNode* root) {
		TreeNode *p1 = nullptr, *p2 = nullptr, *pPrev = nullptr;
		_inOrder2(root, p1, p2, pPrev);
		swap(p1->val, p2->val);
		return;
}

int main()
{
	vector<TreeNode> TreeNodes = { 3,1,4,2 };
	TreeNodes[0].left = &TreeNodes[1];
	TreeNodes[0].right = &TreeNodes[2];
	TreeNodes[2].left = &TreeNodes[3];
	TreeNode* pRoot = &TreeNodes[0];

	vector<int> ans = { 2,1,4,3 };

	vector<int> ret(4,0);
	recoverTree_Sln2(pRoot);
	for (int i = 0; i < TreeNodes.size(); i++) {
		ret[i] = TreeNodes[i].val;
	}
	assert(ret == ans);
	return 0;
}
