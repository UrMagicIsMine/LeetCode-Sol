/*
Shuffle a set of numbers without duplicates.

Example:

// Init an array with set 1, 2, and 3.
int[] nums = {1,2,3};
Solution solution = new Solution(nums);

// Shuffle the array [1,2,3] and return its result. Any permutation of [1,2,3] must equally likely to be returned.
solution.shuffle();

// Resets the array back to its original configuration [1,2,3].
solution.reset();

// Returns the random shuffling of array [1,2,3].
solution.shuffle();
*/

#include <vector>

class Solution {
public:
    Solution(vector<int> nums) : m_vec(nums){

    }

    /** Resets the array to its original configuration and return it. */
    vector<int> reset() {
        return m_vec;
    }

    /** Returns a random shuffling of the array. */
    vector<int> shuffle() {
        vector<int> nums(m_vec);
        for(int i = (int)m_vec.size()-1; i >= 1; i--){
            int j = rand()%(i+1);
            swap(nums[i], nums[j]);
        }
        return nums;
    }

private:
    vector<int> m_vec;

};
