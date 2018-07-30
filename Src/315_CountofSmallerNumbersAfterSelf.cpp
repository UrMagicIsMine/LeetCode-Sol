/*
You are given an integer array nums and you have to return a new counts array.
The counts array has the property where counts[i] is the number of smaller elements
to the right of nums[i].

Example:

Input: [5,2,6,1]
Output: [2,1,1,0]
Explanation:
To the right of 5 there are 2 smaller elements (2 and 1).
To the right of 2 there is only 1 smaller element (1).
To the right of 6 there is 1 smaller element (1).
To the right of 1 there is 0 smaller element.
*/

#include <vector>

class FenwickTree{

public:
    FenwickTree(int n) : _tree(n+1, 0){}

    void update(int i, int delta){
        while(i < _tree.size()){
            _tree[i] += delta;
            i += lowbit(i);
        }
        return;
    }

    int query(int i){
        int sum = 0;
        while(i > 0){
            sum += _tree[i];
            i -= lowbit(i);
        }
        return sum;
    }

private:

    static int lowbit(int x){
        return x & (-x);
    }

    vector<int> _tree;
};


class Solution {
public:
    vector<int> countSmaller(vector<int>& nums) {

        set<int> sorted(nums.begin(), nums.end());
        unordered_map<int, int> rank;
        int iRank = 0;
        for(auto num : sorted)
            rank[num] = ++iRank;

        FenwickTree fwTree(nums.size());
        vector<int> resl;
        resl.reserve(nums.size());
        for(int i = (int)nums.size() - 1; i >= 0; i--){
            resl.push_back(fwTree.query(rank[nums[i]]-1));
            fwTree.update(rank[nums[i]], 1);
        }

        reverse(resl.begin(), resl.end());
        return resl;

    }
};
