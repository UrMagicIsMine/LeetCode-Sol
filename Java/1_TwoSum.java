/* Given an array of integers, return indices of the two numbers such that they
* add up to a specific target.
*
* You may assume that each input would have exactly one solution, and you may
* not use the same element twice.
*
* Example:
*
* Given nums = [2, 7, 11, 15], target = 9,
*
* Because nums[0] + nums[1] = 2 + 7 = 9,
* return [0, 1].
*/

public int[] twoSum(int[] nums, int target) {
    int[] sorted_nums = nums.clone();
    Arrays.sort(sorted_nums);
    int idx1 = 0, idx2 = sorted_nums.length - 1;
    int[] ret = {idx1, idx2};
    int num1 = 0, num2 = 0;
    while ( idx1 < idx2 ) {
        int sum = sorted_nums[idx1] + sorted_nums[idx2];
        if(sum > target) {
            idx2--;
        } else if (sum < target) {
            idx1++;
        } else {
            num1 = sorted_nums[idx1];
            num2 = sorted_nums[idx2];
            break;
        }
    }
    // Find the index;
    for (int idx = 0; idx < nums.length; idx++) {
        if (nums[idx] == num1) {
            ret[0] = idx;
            break;
        }
    }
    for (int idx = nums.length - 1; idx >= 0; idx--) {
        if (nums[idx] == num2) {
            ret[1] = idx;
            break;
        }
    }
    return ret;
}
