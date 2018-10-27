/* Given an array of citations (each citation is a non-negative integer) of a
researcher, write a function to compute the researcher's h-index.

According to the definition of h-index on Wikipedia: "A scientist has index h
if h of his/her N papers have at least h citations each, and the other N − h
papers have no more than h citations each."

Example:

Input: citations = [3,0,6,1,5]
Output: 3
Explanation: [3,0,6,1,5] means the researcher has 5 papers in total and each of
them had received 3, 0, 6, 1, 5 citations respectively. Since the researcher has
3 papers with at least 3 citations each and the remaining two with no more than
3 citations each, her h-index is 3.
Note: If there are several possible values for h, the maximum one is taken as the h-index.
*/

#include <vector>
#include <algorithm>

int hIndex_ST(vector<int>& citations) {

    sort(citations.begin(), citations.end(), greater<int>());
    int i = 0;
    for(; i < citations.size(); i++){
        if(citations[i] >= i+1)
            continue;
        else
            return i;
    }
    return citations.size();
}

// Hash table solution.

int hIndex_HT(vector<int>& citations) {

    int N = citations.size();
    vector<int> nums(N+1, 0);
    for(auto c : citations){
        if( c > N) nums[N]++;
        else nums[c]++;
    }
    int tot = 0;
    for(int i = N; i>=0; i--){
        tot += nums[i];
        if(tot >= i)
            return i;
    }
    return 0;
}
