/* Given a string s, find the longest palindromic substring in s. You may assume
* that the maximum length of s is 1000.
*
* Example 1:
*
* Input: "babad"
* Output: "bab"
* Note: "aba" is also a valid answer.
* Example 2:
*
* Input: "cbbd"
* Output: "bb"
*/

func longestPalindrome(s string) string {
    if len(s) == 0 {
        return ""
    }
    start, end := 0, 0
    for i := 0; i < len(s); i++ {
        len1 := lengthOfPalindrome(s, i, i)
        len2 := lengthOfPalindrome(s, i, i+1)
        max_len_tmp := max(len1, len2)
        if (max_len_tmp > end - start + 1) {
            start = i - (max_len_tmp-1)/2
            end = i + max_len_tmp/2
        }
    }
    return s[start:end+1]
}

func max(i, j int) int {
    if (i > j) {
        return i
    }
    return j
}

func lengthOfPalindrome(s string, i int, j int) int {
    for (i >=0 && j < len(s) && s[i] == s[j]) {
        i--
        j++
    }
    return j - i - 1
}
