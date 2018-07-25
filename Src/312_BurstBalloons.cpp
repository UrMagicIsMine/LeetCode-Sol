/*
Given n balloons, indexed from 0 to n-1. Each balloon is painted with a number on
it represented by array nums. You are asked to burst all the balloons. If the you
burst balloon i you will get nums[left] * nums[i] * nums[right] coins. Here left
and right are adjacent indices of i. After the burst, the left and right then
becomes adjacent.

Find the maximum coins you can collect by bursting the balloons wisely.

Note:

You may imagine nums[-1] = nums[n] = 1. They are not real therefore you can not
burst them.
0 ≤ n ≤ 500, 0 ≤ nums[i] ≤ 100
Example:

Input: [3,1,5,8]
Output: 167
Explanation: nums = [3,1,5,8] --> [3,5,8] -->   [3,8]   -->  [8]  --> []
             coins =  3*1*5      +  3*5*8    +  1*3*8      + 1*8*1   = 167
*/

#include <vector>

int maxCoins(vector<int>& nums) {
    int N = nums.size();
    nums.insert(nums.begin(), 1);
    nums.push_back(1);

    vector<vector<int>> Coins(N+2, vector<int>(N+2, 0));

    for(int Len = 1; Len <= N; Len++){
        for(int i = 1; i <= N-Len+1; i++){
            int j = i+Len-1;
            for(int k = i; k <= j; k++){
                Coins[i][j] = max(Coins[i][j], Coins[i][k-1] + Coins[k+1][j]
                                              + nums[i-1]*nums[j+1]*nums[k]);
            }
        }
    }
    return Coins[1][N];
}
