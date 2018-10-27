/* Given a binary tree, return all root-to-leaf paths.
*
* For example, given the following binary tree:
*
*    1
*  /   \
* 2     3
*  \
*   5
* All root-to-leaf paths are:
*
* ["1->2->5", "1->3"]
*/

#include <string>
#include <vector>
#include <numeric>
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

bool _isLeaf(TreeNode* pNode) {
	return pNode->left == nullptr && pNode->right == nullptr;
}

void _DFS(vector<string>& paths, vector<string> &cur, TreeNode* pNode) {

	if (_isLeaf(pNode)) {
		paths.emplace_back(accumulate(cur.begin(), cur.end(), string("")) + to_string(pNode->val));
		return;
	}
	else {

		cur.push_back(to_string(pNode->val) + "->");
		if (pNode->left)
			_DFS(paths, cur, pNode->left);
		if (pNode->right)
			_DFS(paths, cur, pNode->right);
		cur.pop_back();
	}
}

vector<string> binaryTreePaths(TreeNode* root) {
	vector<string> resl;
	if (root == nullptr)
		return resl;

	vector<string> cur;
	_DFS(resl, cur, root);
	return resl;
}

int main()
{
	vector<TreeNode> vec = { 1,2,3,5 };
	vec[0].left = &vec[1];
	vec[0].right = &vec[2];
	vec[1].right = &vec[3];
	vector<string> ans = { "1->2->5", "1->3" };
	vector<string> ret = binaryTreePaths(&vec[0]);
	assert(ret == ans);
	return 0;
}
