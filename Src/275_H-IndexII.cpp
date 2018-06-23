/* Given an array of citations sorted in ascending order (each citation is a
non-negative integer) of a researcher, write a function to compute the researcher's
h-index.

According to the definition of h-index on Wikipedia: "A scientist has index h if
h of his/her N papers have at least h citations each, and the other N − h papers
have no more than h citations each."

Example:

Input: citations = [0,1,3,5,6]
Output: 3
Explanation: [0,1,3,5,6] means the researcher has 5 papers in total and each of
them had received 0, 1, 3, 5, 6 citations respectively. Since the researcher has
3 papers with at least 3 citations each and the remaining two with no more than
3 citations each, her h-index is 3.
Note:

If there are several possible values for h, the maximum one is taken as the h-index.

Follow up:

This is a follow up problem to H-Index, where citations is now guaranteed to be
sorted in ascending order. Could you solve it in logarithmic time complexity?
*/

#include <vector>

// binary search to find min(i) that citations[i] >= N -i
// equivalent to find citations[i] + i >= N, increasing function, at most 1 equals N
// find that i, if not the minimum i;
// consider corner cases

int hIndex(vector<int>& citations) {
    int N = citations.size();
    if( N == 0 )
        return 0;
    int lo = 0, hi = N - 1;
    int mid;
    while(lo <= hi){
        mid = lo + (hi - lo)/2;
        if(mid + citations[mid] == N)
            return N - mid;
        else if (mid + citations[mid] > N)
            hi = mid - 1;
        else
            lo = mid + 1;
    }
    return N - lo;
}
