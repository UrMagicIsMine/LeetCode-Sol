# Given a string s, find the longest palindromic substring in s. You may assume
# that the maximum length of s is 1000.
#
# Example 1:
#
# Input: "babad"
# Output: "bab"
# Note: "aba" is also a valid answer.
# Example 2:
#
# Input: "cbbd"
# Output: "bb"
#

class Solution(object):
    def longestPalindrome(self, s):
        """
        :type s: str
        :rtype: str
        """
        if len(s) is 0:
            return ""
        start = 0
        end = 0
        for idx in range(len(s)):
            len1 = self.lenOfPalidrome(s, idx, idx)
            len2 = self.lenOfPalidrome(s, idx, idx+1)
            max_len_tmp = max(len1, len2)
            if max_len_tmp > end - start + 1:
                start = idx - (max_len_tmp-1)/2
                end = idx + max_len_tmp/2
        return s[start:end+1]

    def lenOfPalidrome(self, s, i, j):
        while (i >= 0 and j < len(s) and s[i] == s[j]):
            i -= 1
            j += 1
        return j - i - 1
