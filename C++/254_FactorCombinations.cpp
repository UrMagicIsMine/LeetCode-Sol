/*
Numbers can be regarded as product of its factors. For example,

8 = 2 x 2 x 2;
  = 2 x 4.
Write a function that takes an integer n and return all possible combinations of
its factors.

Note:

You may assume that n is always positive.
Factors should be greater than 1 and less than n.
Example 1:

Input: 1
Output: []
Example 2:

Input: 37
Output:[]
Example 3:

Input: 12
Output:
[
  [2, 6],
  [2, 2, 3],
  [3, 4]
]
Example 4:

Input: 32
Output:
[
  [2, 16],
  [2, 2, 8],
  [2, 2, 2, 4],
  [2, 2, 2, 2, 2],
  [2, 4, 4],
  [4, 8]
]
*/

#include <vector>

void _DFS(vector<vector<int>>& resl, int low, int n, vector<int> factors){

    for(int i = low; i <= sqrt(n); i++){
        if(n%i==0){
            vector<int> nxtFactors(factors);
            nxtFactors.push_back(i);
            _DFS(resl, i, n/i, nxtFactors);
            nxtFactors.push_back(n/i);
            resl.push_back(std::move(nxtFactors));
        }
    }
    return;
}

vector<vector<int>> getFactors(int n) {
    vector<vector<int>> resl;
    vector<int> factors;
    _DFS(resl, 2, n, factors);
    return resl;
}
