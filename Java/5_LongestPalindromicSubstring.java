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
    if ("".equals(s))
        return "";
    int max_len = 0, idx_mid = 0;
    int len = s.length();
    for (int idx = 0; idx < len; idx++) {
        int pal_len1 = lengthOfPalindrome(s, idx, idx);
        int pal_Len2 = lengthOfPalindrome(s, idx, idx+1);
        if (pal_len1 > max_len || pal_Len2 > max_len) {
            max_len = Math.max(pal_len1, pal_Len2);
            idx_mid = idx;
        }
    }
    int left = 0, right =0;
    if ((max_len & 1) != 0) {
        // Odd
        left = idx_mid - (max_len >> 1);
        right = idx_mid + (max_len >> 1) + 1;
    } else {
        // Even
        left = idx_mid - (max_len >> 1) + 1;
        right = idx_mid + (max_len >> 1) + 1;
    }
    return s.substring(left, right);
}

private int lengthOfPalindrome(String s, int i, int j) {
    int len = s.length();
    int ret = 0;
    while ( i >= 0 && j < len ) {
        if (s.charAt(i) == s.charAt(j)) {
            ret += (i==j)? 1 : 2;
            i--;
            j++;
        } else {
            break;
        }
    }
    return ret;
}
