/* Given a string, find the length of the longest substring without repeating
* characters.
*
* Examples:
*
* Given "abcabcbb", the answer is "abc", which the length is 3.
*
* Given "bbbbb", the answer is "b", with the length of 1.
*
* Given "pwwkew", the answer is "wke", with the length of 3. Note that the answer
* must be a substring, "pwke" is a subsequence and not a substring.
*/

func max(x, y int) int {
    if x < y {
        return y
    }
    return x
}

func lengthOfLongestSubstring(s string) int {
    ret := 0;
    back := 0;
    char_table := make(map[rune]int);
    for front, c_val := range s {
        val, stat := char_table[c_val];
        if (stat == false || val < back) {
            ret = max(ret, front - back + 1);
        } else {
            back = val + 1;
        }
        char_table[c_val] = front;
    }
    return ret;
}
