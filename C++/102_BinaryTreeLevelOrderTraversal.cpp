/*
* Given a binary tree, return the level order traversal of its nodes' values. (ie, from left to right, level by level).
*
* For example:
* Given binary tree [3,9,20,null,null,15,7],
*     3
*    / \
*   9  20
*     /  \
*    15   7
* return its level order traversal as:
* [
*   [3],
*   [9,20],
*   [15,7]
* ]
*/

#include <vector>
#include <queue>

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

typedef vector<int> vec1D;
typedef vector<vec1D> vec2D;

vector<vector<int>> levelOrder(TreeNode* root) {
    vec2D resl;
    if( root ){

        queue<TreeNode*> queNode;
        queNode.push(root);

        while(!queNode.empty()){

            int i = 0, N = queNode.size();

            vec1D vecTmp;
            vecTmp.resize(N);
            TreeNode * pTop = nullptr;
            while(N--){

                pTop = queNode.front();
                vecTmp[i++] = pTop->val;

                if( pTop->left )
                    queNode.push(pTop->left);
                if( pTop->right )
                    queNode.push(pTop->right);
                queNode.pop();
            }
            resl.push_back(std::move(vecTmp));
        }
    }
    return resl;
}

int main()
{
	vector<TreeNode> vec = {1,2,2,3,3};
	vec[0].left = &vec[1];
	vec[0].right = &vec[2];
	vec[1].right = &vec[3];
	vec[2].right = &vec[4];

	vec2D ret = levelOrder(&vec[0]);
	return 0;
}
