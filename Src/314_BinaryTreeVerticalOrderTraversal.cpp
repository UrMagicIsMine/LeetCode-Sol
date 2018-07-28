/*
Given a binary tree, return the vertical order traversal of its nodes' values.
(ie, from top to bottom, column by column).

If two nodes are in the same row and column, the order should be from left to right.

Examples 1:

Input: [3,9,20,null,null,15,7]

   3
  /\
 /  \
 9  20
    /\
   /  \
  15   7

Output:

[
  [9],
  [3,15],
  [20],
  [7]
]
Examples 2:

Input: [3,9,8,4,0,1,7]

     3
    /\
   /  \
   9   8
  /\  /\
 /  \/  \
 4  01   7

Output:

[
  [4],
  [9],
  [3,0,1],
  [8],
  [7]
]
Examples 3:

Input: [3,9,8,4,0,1,7,null,null,null,2,5] (0's right child is 2 and 1's left child is 5)

     3
    /\
   /  \
   9   8
  /\  /\
 /  \/  \
 4  01   7
    /\
   /  \
   5   2

Output:

[
  [4],
  [9,5],
  [3,0,1],
  [8,2],
  [7]
]

*/

#include <vector>
#include <queue>

struct TreeNode{
  int value;
  TreeNode* left;
  TreeNode* right;
  TreeNode(int val) : value(val), left(NULL), right(NULL){}
};

vector<vector<int>> verticalOrder(TreeNode* root) {
    vector<vector<int>> resl;
    if(!root)
        return resl;
    map<int, vector<int>> valueMap;
    queue<pair<TreeNode*, int>> que;
    que.push(make_pair(root, 0));
    TreeNode *pNode = nullptr;
    int tmp = 0;
    while(!que.empty()){

        pNode = que.front().first;
        tmp = que.front().second;
        que.pop();
        valueMap[tmp].push_back(pNode->val);
        if(pNode->left)
            que.push(make_pair(pNode->left, tmp-1));
        if(pNode->right)
            que.push(make_pair(pNode->right, tmp+1));
    }

    for(auto& p : valueMap)
        resl.push_back(move(p.second));
    return resl;
}
