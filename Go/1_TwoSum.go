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

func twoSum(nums []int, target int) []int {
    num_table := make(map[int]int);
    for idx1, val := range nums {
        if idx2, ok := num_table[target - val]; ok {
            return []int{idx2, idx1};
        }
        num_table[val] = idx1;
    }
    return []int{-1, -1};
}
