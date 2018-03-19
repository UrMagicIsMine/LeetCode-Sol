/* Given a binary tree, find the leftmost value in the last row of the tree.
*
* Example 1:
* Input:
*
*     2
*    / \
*   1   3
*
* Output:
* 1
* Example 2:
* Input:
*
*         1
*        / \
*       2   3
*      /   / \
*     4   5   6
*        /
*       7
*
* Output:
* 7
* Note: You may assume the tree (i.e., the given root node) is not NULL.
*/

#include <queue>
#include <vector>
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

int findBottomLeftValue(TreeNode* root) {

	queue<TreeNode*> QueNodes;
	QueNodes.push(root);
	int ret = 0;
	while (!QueNodes.empty()) {
		ret = QueNodes.front()->val;
		int N = QueNodes.size();
		while (N--) {

			TreeNode * pNode = QueNodes.front();
			if (pNode->left)
				QueNodes.push(pNode->left);
			if (pNode->right)
				QueNodes.push(pNode->right);
			QueNodes.pop();
		}

	}
	return ret;
}

int main()
{
	vector<TreeNode> vec = { 2,1,3 };
	vec[0].left = &vec[1];
	vec[0].right = &vec[2];
	int ans = 1;
	int ret = findBottomLeftValue(&vec[0]);
	assert(ret == ans);
	return 0;
}
