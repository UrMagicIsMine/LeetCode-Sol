/*
There is a garden with N slots. In each slot, there is a flower. The N flowers
will bloom one by one in N days. In each day, there will be exactly one flower
blooming and it will be in the status of blooming since then.

Given an array flowers consists of number from 1 to N. Each number in the array
represents the place where the flower will open in that day.

For example, flowers[i] = x means that the unique flower that blooms at day i
will be at position x, where i and x will be in the range from 1 to N.

Also given an integer k, you need to output in which day there exists two flowers
in the status of blooming, and also the number of flowers between them is k and
these flowers are not blooming.

If there isn't such day, output -1.

Example 1:
Input:
flowers: [1,3,2]
k: 1
Output: 2
Explanation: In the second day, the first and the third flower have become blooming.
Example 2:
Input:
flowers: [1,2,3]
k: 1
Output: -1
Note:
The given array will be in the range [1, 20000].
*/

#include <vector>

int kEmptySlots(vector<int>& flowers, int k) {
    vector<int> bloomday(flowers.size(), 0);
    for(int i = 0; i < flowers.size(); i++){
        bloomday[flowers[i]-1] = i+1;
    }

    int left = 0, right = k+left+1, day = INT_MAX;
    for(int i = 1; right < flowers.size(); i++){
        // current days[i] is valid, continue scanning
        if(bloomday[i] > bloomday[left] && bloomday[i] > bloomday[right]){
            continue;
        }
        // reach boundary of sliding window, since previous number are all valid, record result
        if(i == right){
            day = min(day, max(bloomday[left], bloomday[right]));
        }
        // not valid, move the sliding window
        left = i;
        right = k + left + 1;
    }
    return day == INT_MAX? -1 : day;
}
