/* Given two binary trees and imagine that when you put one of them to cover the
* other, some nodes of the two trees are overlapped while the others are not.
*
* You need to merge them into a new binary tree. The merge rule is that if two
* nodes overlap, then sum node values up as the new value of the merged node.
* Otherwise, the NOT null node will be used as the node of new tree.
*
* Example 1:
* Input:
* 	Tree 1                     Tree 2
*           1                         2
*          / \                       / \
*         3   2                     1   3
*        /                           \   \
*       5                             4   7
* Output:
* Merged tree:
* 	     3
* 	    / \
* 	   4   5
* 	  / \   \
* 	 5   4   7
* Note: The merging process must start from the root nodes of both trees.
*/
#include<vector>
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

/* this solution keeps the original trees unchanged,
   the returned tree is a new created tree */

TreeNode* mergeTrees_Sln1(TreeNode* t1, TreeNode* t2) {

	TreeNode* pNode = nullptr;

	if (t1 != nullptr || t2 != nullptr) {
		if (t1 == nullptr) {
			pNode = new TreeNode(t2->val);
			pNode->left = mergeTrees_Sln1(t1, t2->left);
			pNode->right = mergeTrees_Sln1(t1, t2->right);
		}
		else if (t2 == nullptr) {
			pNode = new TreeNode(t1->val);
			pNode->left = mergeTrees_Sln1(t1->left, t2);
			pNode->right = mergeTrees_Sln1(t1->right, t2);
		}
		else {
			pNode = new TreeNode(t1->val + t2->val);
			pNode->left = mergeTrees_Sln1(t1->left, t2->left);
			pNode->right = mergeTrees_Sln1(t1->right, t2->right);
		}
	}
	return pNode;
}

/* this solution messed up with the original trees*/

TreeNode* mergeTrees_Sln2(TreeNode* t1, TreeNode* t2) {

	if (!t1)
		return t2;
	if (!t2)
		return t1;
	t1->val += t2->val;
	t1->left = mergeTrees_Sln2(t1->left, t2->left);
	t1->right = mergeTrees_Sln2(t1->right, t2->right);

	return t1;
}

int main()
{

	return 0;
}
