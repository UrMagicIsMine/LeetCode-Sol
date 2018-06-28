/*
In this chapter, we discuss the problem of (Balanced) Binary Search Tree
*/


struct TreeNode{
  int val;
  TreeNode* left;
  TreeNode* right;
  TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
}

bool contains(const int& val, TreeNode* root){
  TreeNode *pNode = root;
  while(pNode){
    if(pNode->val == val)
      return true;
    else if(pNode->val < val)
      pNode = pNode->right;
    else
      pNode = pNode->left;
  }
  return false;
}

TreeNode* getMin(TreeNode* root){
  while(root && root->left)
    root = root->left;
  return root;
}

TreeNode* getMax(TreeNode* root){
  while(root && root->right)
    root = root->right;
  return root;
}

void insert(const int& val, TreeNode*& root){
  TreeNode *&pNode = root;
  while(pNode){
    if(pNode->val == val)
      return;
    else if(pNode->val < val)
      pNode = pNode->right;
    else
      pNode = pNode->left;
  }
  pNode = new TreeNode(val);
  return;
}

TreeNode* delete(int key, TreeNode* root){

  if(root == nullptr)
    return nullptr;

  TreeNode dummy(0), *pParent = &dummy;
  dummy.left = root;
  TreeNode *pNode = root;

  // find the key
  while(pNode){
    if(pNode->val == key)
      break;
    else if(pNode->val < key){
      pParent = pNode;
      pNode = pNode->right;
    }
    else{
      pParent = pNode;
      pNode = pNode->left;
    }
  }

  if(pNode == nullptr)
    return dummy.left;

  // if pNode is a leaf node
  if(pNode->left == nullptr && pNode->right == nullptr){
    if(pParent->left == pNode)
      pParent->left = nullptr;
    else
      pParent->right = nullptr;
    delete pNode;
  }
  else if(pNode->left && pNode->right){
    // has two children;
    //find successor;
    TreeNode *pSor = pNode->right, *pSparent = pNode;
    while(pSor->left){
      pSparent = pSor;
      pSor = pSor->left;
    }
    pNode->val = pSor->val;
    if(pSparent->left == pSor)
      pSparent->left = pSor->right;
    else
      pSparent->right = pSor->right;

    delete pSor;
  }
  else{
    TreeNode* pChild = pNode->left? pNode->left : pNode->right;
    if(pParent->left == pNode)
      pParent->left = pChild;
    else
      pParent->right = pChild;
    delete pNode;
  }
  return dummy.left;
}
