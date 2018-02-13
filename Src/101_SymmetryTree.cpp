/*
* Given a binary tree, check whether it is a mirror of itself (ie, symmetric around its center).
*
* For example, this binary tree [1,2,2,3,4,4,3] is symmetric:
*
*     1
*    / \
*   2   2
*  / \ / \
* 3  4 4  3
* But the following [1,2,2,null,3,null,3] is not:
*    1
*   / \
*  2   2
*   \   \
*   3    3
* Note:
* Bonus points if you could solve it both recursively and iteratively.
*/

/*
* Definition for a binary tree node.
*/
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

/******************************************************************************/

/* Begin of Recursive solution */
bool isSymmetricRecursive(TreeNode* p, TreeNode *q)
{
    if( p && q )
        return p->val == q->val
            && isSymmetricRecursive( p->left, q->right )
            && isSymmetricRecursive( p->right, q->left );
    else if ( !p && !q )
        return true;
    else
        return false;
}

bool isSymmetricRecusive(TreeNode* root) {
    if( root ){
        return isSymmetricRecursive(root->left, root->right);
    }
    return true;
}

/* End of Recursive solution */

/******************************************************************************/

/* Begin of Iterative solution */
bool checkSymmetric(vector<TreeNode*> & vecNode)
{
	int ift = 0;
	int ibk = vecNode.size() - 1;
	for (; ift <= ibk; ift++, ibk--) {
		if ((vecNode[ift] && vecNode[ibk] && vecNode[ift]->val == vecNode[ibk]->val)
			|| (vecNode[ift] == nullptr && vecNode[ibk] == nullptr))
			continue;
		else
			return false;
	}
	return true;
}

void nextLevelInDeq(vector<TreeNode*> & vecNode, deque<TreeNode*>& deqNode)
{
	for (auto it = vecNode.begin(); it != vecNode.end(); it++) {
		if (*it) {
			deqNode.push_back((*it)->left);
			deqNode.push_back((*it)->right);
		}
	}
	return;
}

bool isSymmetricIterative(TreeNode* root) {

	if (!root)
		return true;
	deque<TreeNode*> deqNode;
	deqNode.push_back(root);

	while (!deqNode.empty()) {
		vector<TreeNode*> vecNode(deqNode.begin(), deqNode.end());
		deqNode.clear();

    // check the symmetric of each level
		if (checkSymmetric(vecNode)) {
			nextLevelInDeq(vecNode, deqNode);
		}
		else {
			return false;
		}
	}
	return true;
}
/* End of Iterative solution */

/******************************************************************************/

int main()
{
	vector<TreeNode> vec = {1,2,2,3,3};
	vec[0].left = &vec[1];
	vec[0].right = &vec[2];
	vec[1].right = &vec[3];
	vec[2].right = &vec[4];

	bool ret = isSymmetric(&vec[0]);
	return 0;
}
