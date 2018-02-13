/* Given a binary tree, return the zigzag level order traversal of its nodes' values.
* (ie, from left to right, then right to left for the next level and alternate between).
*
* For example:
* Given binary tree [3,9,20,null,null,15,7],
*     3
*    / \
*   9  20
*     /  \
*    15   7
* return its zigzag level order traversal as:
* [
*   [3],
*   [20,9],
*   [15,7]
* ]
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

typedef vector<int> vec1D;
typedef vector<vec1D> vec2D;

vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
    vec2D resl;

    if(root){

        deque<TreeNode*> deqTree;
        deqTree.push_back(root);

        bool forward = true;
        while(!deqTree.empty()){

            vec1D vTmp;
            int i = 0, N = deqTree.size();
            vTmp.resize(N);

            if(forward){
                for( auto it = deqTree.begin(); it != deqTree.end(); it++ )
                    vTmp[i++] = (*it)->val;
            }
            else{
                for( auto it = deqTree.rbegin(); it != deqTree.rend(); it++ )
                    vTmp[i++] = (*it)->val;
            }
            forward = !forward;
            resl.push_back(std::move(vTmp));

            while(N--){

                TreeNode * pFront = deqTree.front();
                if(pFront->left)
                    deqTree.push_back(pFront->left);
                if(pFront->right)
                    deqTree.push_back(pFront->right);
                deqTree.pop_front();
            }
        }
    }
    return resl;
}

int main()
{
	vector<TreeNode> vec = {3,9,20,15,7};
	vec[0].left = &vec[1];
	vec[0].right = &vec[2];
	vec[1].right = &vec[3];
	vec[2].right = &vec[4];

	vec2D ret = levelOrder(&vec[0]);
	return 0;
}
