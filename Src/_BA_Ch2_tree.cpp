/*
In this chapter, we discuss the problem of tree
*/

#include <vector>
#include <stack>
#include <queue>

struct TreeNode{
  int val;
  TreeNode* left;
  TreeNode* right;
  TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
}

/*******************************************************************************/

// root, left, right
void PreOrder(TreeNode* root, vector<int>& vec){
  TreeNode* pNode = root;
  stack<TreeNode*> stNodes;
  while(root || !stNodes.empty()){
    if(pNode){
      vec.push_back(pNode->val);
      if(pNode->right)
        stNodes.push(pNode->right);
      pNode = pNode->left;
    }
    else{
      pNode = stNodes.top();
      stNodes.pop();
    }
  }
}

void PreOrderMorris(TreeNode* root, vector<int>& vec){
  TreeNode *pNode = root, *pCur;
  while(pNode){
    if(pNode->left == nullptr){
      // if the left child is null, move to the right child;
      vec.push_back(pNode->val);
      pNode = pNode->right;
    }
    else{
      // find inorder predecessor;
      pCur = pNode->left;
      while(pCur->right && pCur->right != pNode)
        pCur = pCur->right;

      if(pCur->right == pNode){
        // If the right child of inorder predecessor already points to this node
        pCur->right = nullptr;
        pNode = pNode->right;
      }
      else{
        // If the right child doesn't point to this node, visit this node and make
        // the right child point to this node;
        vec.push_back(pNode->val);
        pCur->right = pNode;
        pNode = pNode->left;
      }
    }
  }
}

/*******************************************************************************/

// left, root, right
void InOrder(TreeNode* root, vector<int>& vec){
  TreeNode* pNode = root;
  stack<TreeNode*> stNodes;
  while(pNode || !stNodes.empty()){
    if(pNode){
      stNodes.push(pNode);
      pNode = pNode->left;
    }
    else{
      pNode = stNodes.top();
      stNodes.pop();
      vec.push_back(pNode->val);
      pNode = pNode->right;
    }
  }
}

void MorrisTraversal(struct tNode *root)
{
  struct tNode *current,*pre;

  if(root == NULL)
     return;

  current = root;
  while(current != NULL)
  {
    if(current->left == NULL)
    {
      printf("%d ", current->data);
      current = current->right;
    }
    else
    {
      /* Find the inorder predecessor of current */
      pre = current->left;
      while(pre->right != NULL && pre->right != current)
        pre = pre->right;

      /* Make current as right child of its inorder predecessor */
      if(pre->right == NULL)
      {
        pre->right = current;
        current = current->left;
      }

      /* Revert the changes made in if part to restore the original
        tree i.e., fix the right child of predecssor */
      else
      {
        pre->right = NULL;
        printf("%d ",current->data);
        current = current->right;
      } /* End of if condition pre->right == NULL */
    } /* End of if condition current->left == NULL*/
  } /* End of while */
}

/*******************************************************************************/

// left, right, root
void PostOrder(TreeNode* root, vector<int>& vec){

}
