/* Given a binary search tree (BST), find the lowest common ancestor (LCA) of two given nodes in the BST.

According to the definition of LCA on Wikipedia: “The lowest common ancestor is defined between two nodes v and w as the lowest node in T that has both v and w as descendants (where we allow a node to be a descendant of itself).”

        _______6______
       /              \
    ___2__          ___8__
   /      \        /      \
   0      _4       7       9
         /  \
         3   5
For example, the lowest common ancestor (LCA) of nodes 2 and 8 is 6. Another example is LCA of nodes 2 and 4 is 2, since a node can be a descendant of itself according to the LCA definition.
*/

#include <vector>
#include <queue>
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

void _DFS(TreeNode * pNode, int& num) {

	if (pNode) {
		num++;
		_DFS(pNode->left, num);
		_DFS(pNode->right, num);
	}

}

int countNodes_DFS(TreeNode* root) {

	int num = 0;
	_DFS(root, num);
	return num;

}

int countNodes_BFS(TreeNode* root) {

	if (root == nullptr)
		return 0;

	queue<TreeNode*> queNodes;
	queNodes.push(root);
	int num = 0;
	while (!queNodes.empty()) {

		int N = queNodes.size();
		num += N;
		while (N--) {

			TreeNode * pTop = queNodes.front();
			if (pTop->left)
				queNodes.push(pTop->left);
			if (pTop->right)
				queNodes.push(pTop->right);

			queNodes.pop();
		}
	}
	return num;
}

/*
The height of a tree can be found by just going left. Let a single node tree have
height 0. Find the height h of the whole tree. If the whole tree is empty, i.e.,
has height -1, there are 0 nodes.

Otherwise check whether the height of the right subtree is just one less than that
of the whole tree, meaning left and right subtree have the same height.

  If yes, then the last node on the last tree row is in the right subtree and the
left subtree is a full tree of height h-1. So we take the 2^h-1 nodes of the left
subtree plus the 1 root node plus recursively the number of nodes in the right subtree.
  If no, then the last node on the last tree row is in the left subtree and the
  right subtree is a full tree of height h-2. So we take the 2^(h-1)-1 nodes of
  the right subtree plus the 1 root node plus recursively the number of nodes in
  the left subtree.

Since I halve the tree in every recursive step, I have O(log(n)) steps. Finding a
height costs O(log(n)). So overall O(log(n)^2).
*/

int _height(TreeNode* pNode) {
	return pNode == nullptr ? -1 : 1 + _height(pNode->left);
}

int countNodes(TreeNode* root) {

	int h = _height(root);
	int num = 0;

	while (root) {

		if (_height(root->right) != h - 1) {
			/* right tree is a full tree */
			num += 1 << h - 1;
			root = root->left;
		}
		else {
			num += 1 << h;
			root = root->right;
		}
		h--;
	}
	return num;
}

int main()
{
	vector<TreeNode> tree = { 2,1 };
	tree[0].left = &tree[1];
	int ans = tree.size();
	int ret1 = countNodes_DFS(&tree[0]);
	int ret2 = countNodes_BFS(&tree[0]);
	int ret3 = countNodes(&tree[0]);
	assert(ret1 == ans);
	assert(ret2 == ans);
	assert(ret3 == ans);
	return 0;
}
