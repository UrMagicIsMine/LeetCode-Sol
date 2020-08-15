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

public String longestPalindrome(String s) {
    if (s == null || s.length() < 1) return "";
    int left = 0, right =0;
    for (int idx = 0; idx < s.length(); idx++) {
        int pal_len1 = lengthOfPalindrome(s, idx, idx);
        int pal_Len2 = lengthOfPalindrome(s, idx, idx+1);
        int len = Math.max(pal_len1, pal_Len2);
        if (len > right - left + 1) {
            left = idx - (len - 1) / 2;
            right = idx + len / 2;
        }
    }
    return s.substring(left, right+1);
}

private int lengthOfPalindrome(String s, int i, int j) {
    int len = s.length();
    while ( i >= 0 && j < len && s.charAt(i) == s.charAt(j)) {
        i--;
        j++;
    }
    return j - i - 1;
}
