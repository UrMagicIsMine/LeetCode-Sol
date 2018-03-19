/* You need to find the largest value in each row of a binary tree.
*
* Example:
* Input:
*
*           1
*          / \
*         3   2
*        / \   \
*       5   3   9
*
* Output: [1, 3, 9]
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

vector<int> largestValues(TreeNode* root) {

	vector<int> resl;
	if (root == nullptr)
		return resl;

	queue<TreeNode*> queNodes;
	queNodes.push(root);
	while (!queNodes.empty()) {

		int i = queNodes.front()->val;
		int N = queNodes.size();
		while (N--) {

			TreeNode * pNode = queNodes.front();
			if (pNode->val > i)
				i = pNode->val;

			if (pNode->left)
				queNodes.push(pNode->left);
			if (pNode->right)
				queNodes.push(pNode->right);

			queNodes.pop();
		}
		resl.push_back(i);
	}
	return resl;
}

int main()
{
	vector<TreeNode> vec = { 2,1,3 };
	vec[0].left = &vec[1];
	vec[0].right = &vec[2];
	vector<int> ans = { 2,3 };
	vector<int> ret = largestValues(&vec[0]);
	assert(ret == ans);
	return 0;
}
