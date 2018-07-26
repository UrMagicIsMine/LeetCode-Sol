/*
Given a non-empty array of numbers, a0, a1, a2, … , an-1, where 0 <= ai < 231.

Find the maximum result of ai XOR aj, where 0 <= i, j < n.

Could you do this in O(n) runtime?

Example:

Input: [3, 10, 5, 25, 2, 8]

Output: 28

Explanation: The maximum result is 5 ^ 25 = 28.
*/

#include <vector>

struct TrieNode{
    TrieNode* children[2];
    TrieNode(){
        children[0] = nullptr;
        children[1] = nullptr;
    }
};

class Solution {
public:
    int findMaximumXOR(vector<int>& nums) {
        TrieNode* root = new TrieNode();
        for(auto num : nums)
            _buildTrie(root, num);

        int maxXOR = 0;
        for(auto num : nums)
            maxXOR = max(maxXOR, _findMaxXOR(num, root));

        return maxXOR;
    }

    void _buildTrie(TrieNode* root, int num){
        for(int i = 31; i >= 0; --i){
            int idx = (num >> i) & 1;
            if(root->children[idx] == nullptr)
                root->children[idx] = new TrieNode();
            root = root->children[idx];
        }
        return;
    }

    int _findMaxXOR(int num, TrieNode* root){
        int resl = 0;
        for(int i = 31; i >=0; i--){
            int idx = 1 - (num >> i) & 1;
            if(root->children[idx]){
                resl += (1 << i);
                root = root->children[idx];
            }
            else{
                root = root->children[1-idx];
            }
        }
        return resl;
    }
};
