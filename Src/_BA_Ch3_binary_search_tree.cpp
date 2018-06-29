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


/******************************************************************************/
// AVL tree
// insertion : https://www.geeksforgeeks.org/avl-tree-set-1-insertion/
// deleteion : https://www.geeksforgeeks.org/avl-tree-set-2-deletion/

struct AVLTreeNode{
  int val;
  AVLTreeNode* left;
  AVLTreeNode* right;
  int height;
  AVLTreeNode(int x) : val(x), left(nullptr), right(nullptr), height(1) {}
}

int height(AVLTreeNode* pNode){
  if(pNode == nullptr)
    return 0;
  return pNode->height;
}

// a utility function to right rotate subtree rooted with pNode
AVLTreeNode* rightRotate(AVLTreeNode* pY){

  AVLTreeNode* pX = pY->left;
  AVLTreeNode* pT2 = pX->right;

  pX->right = pY;
  pY->left = pT2;

  pY->height = max(height(pY->left), height(pY->right));
  pX->height = max(height(pX->left), height(pX->right));
  return pX;
}

// a utility function to right rotate subtree rooted with pNode
AVLTreeNode* leftRotate(AVLTreeNode* pX){

  AVLTreeNode* pY = pX->right;
  AVLTreeNode* pT2 = pY->left;

  pY->left = pX;
  pX->right = pT2;

  pX->height = max(height(pX->left), height(pX->right));
  pY->height = max(height(pY->left), height(pY->right));
  return pY;
}

// get balance factor of node
int getBalance(AVLTreeNode* pNode){
  if(pNode == nullptr)
    return 0;
  else
    return height(pNode->left) - height(pNode->right);
}

// insert a node
AVLTreeNode* insert(AVLTreeNode* root, int key){

  //1, perform normal BST insert;
  if(root == nullptr)
    return new AVLTreeNode(key);

  if(root->val < key)
    root->right = insert(root->right, key);
  else if(root->val > key)
    root->left = insert(root->left, key);
  else
    return root;

  //2, update height of this node
  root->height = max(height(root->left), height(root->right));

  //3, get the balance of this node
  int balance = getBalance(root);

  // if the node become unbalanced, they are 4 cases;
  // Left-Left case
  if(balance > 1 && key < root->left->val)
    return rightRotate(root);
  // Left-Right Case
  if(balance > 1 && key > root->left->val){
    root->left = leftRotate(root->left);
    return rightRotate(root);
  }
  // Right-Right Case
  if(balance < -1 && key > root->right->val)
    return leftRotate(root);
  // Right-Left case
  if(balance < -1 && key < root->right->val){
    root->right = rightRotate(root->right);
    return leftRotate(root);
  }
  // return balanced node pointer
  return root;
}

AVLTreeNode* deleteNode(AVLTreeNode* root, int key){

  //1, perform standard BST deletion
  if(root == nullptr)
    return root;
  if(root->val < key)
    root->right = deleteNode(root->right, key);
  else if(root->val > key)
    root->left = deleteNode(root->left, key);
  else{
    // find the node to delete
    if(root->left==nullptr || root->right == nullptr){
      // at most 1 child;
      AVLTreeNode* pChild = root->left? root->left : root->right;
      if(pChild == nullptr){
        delete root;
        return nullptr;
      }
      else{
        *root = *pChild;
        delete pChild;
      }
    }
    else{
      // has two children;
      // find successor;
      AVLTreeNode* pSor = root->right;
      while(pSor->left)
        pSor = pSor->left;
      root-val = pSor->val;
      root->right = deleteNode(root->right, pSor->val);
    }
  }
  // if(root == nullptr) return nullptr;
  // update height of current node
  root->height = max(height(root->left), height(root->right))+1;

  int balance = getBalance(root);
  // Left-Left
  if(balance > 1 && getBalance(root->left) > 0)
    return rightRotate(root);
  // Left-Right
  if(balance > 1 && getBalance(root->left) < 0){
    root->left = leftRotate(root->left);
    return rightRotate(root);
  }
  // Right-Right
  if(balance < -1 && getBalance(root->right) < 0)
    return leftRotate(root);
  // Right=Left
  if(balance < -1 && getBalance(root->right) > 0){
    root->right = rightRotate(root->right);
    return leftRotate(root);
  }
  return root;
}

/******************************************************************************/
// Red-Black tree

struct RBTreeNode{
  int val;
  RBTreeNode* left;
  RBTreeNode* right;
  int height;
  RBTreeNode(int x) : val(x), left(nullptr), right(nullptr), height(1) {}
}
