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

#include <vector>
#include <deque>

using namespace std;

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
bool isSym(deque<TreeNode*>& DeqNodes){
    int i = 0, j = int(DeqNodes.size()) - 1;

    for(; i < j; i++, j--){
        if(!DeqNodes[i] && !DeqNodes[j])
            continue;
        if(DeqNodes[i] && DeqNodes[j] && DeqNodes[i]->val == DeqNodes[j]->val)
            continue;
        return false;
    }
    return true;
}

bool isSymmetric(TreeNode* root) {

    deque<TreeNode*> DeqNodes;
    DeqNodes.push_back(root);

    while(!DeqNodes.empty()){
        int N = DeqNodes.size();
        while(N--){

            TreeNode* pNode = DeqNodes.front();
            DeqNodes.pop_front();
            if(pNode){
                DeqNodes.push_back(pNode->left);
                DeqNodes.push_back(pNode->right);
            }
        }

        if(!isSym(DeqNodes))
            return false;
    }
    return true;
}

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
