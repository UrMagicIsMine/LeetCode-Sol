/*
Given an array nums, there is a sliding window of size k which is moving from the
very left of the array to the very right. You can only see the k numbers in the
window. Each time the sliding window moves right by one position. Return the max
sliding window.

Example:

Input: nums = [1,3,-1,-3,5,3,6,7], and k = 3
Output: [3,3,5,5,6,7]
Explanation:

Window position                Max
---------------               -----
[1  3  -1] -3  5  3  6  7       3
 1 [3  -1  -3] 5  3  6  7       3
 1  3 [-1  -3  5] 3  6  7       5
 1  3  -1 [-3  5  3] 6  7       5
 1  3  -1  -3 [5  3  6] 7       6
 1  3  -1  -3  5 [3  6  7]      7
Note:
You may assume k is always valid, 1 ≤ k ≤ input array's size for non-empty array.

Follow up:
Could you solve it in linear time?
*/

#include <vector>
#include <set>

using namespace std;

// use multiset, O(NlogN)

vector<int> maxSlidingWindow(vector<int>& nums, int k) {
    vector<int> resl;

    multiset<int> ms;
    for(int i = 0; i < nums.size(); i++){
        ms.insert(nums[i]);
        if(i < k-1){
            continue;
        }
        resl.push_back(*ms.rbegin());
        // only delete one element
        ms.erase(ms.equal_range(nums[i+1-k]).first);
    }
    return resl;
}

// monotonic queue problem, O(N)

vector<int> maxSlidingWindow(vector<int>& nums, int k) {
    vector<int> resl;
    deque<int> deq;
    for(int i = 0; i < nums.size(); i++){
        while(!deq.empty() && nums[i] > deq.back()){
            deq.pop_back();
        }
        deq.push_back(nums[i]);
        if( i-k >=0 && deq.front() == nums[i-k] )
            deq.pop_front();
        if(i-k+1 >= 0)
            resl.push_back(deq.front());
    }

    return resl;
}
