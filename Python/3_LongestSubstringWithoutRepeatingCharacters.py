# Given a string, find the length of the longest substring without repeating
# characters.
#
# Examples:
#
# Given "abcabcbb", the answer is "abc", which the length is 3.
#
# Given "bbbbb", the answer is "b", with the length of 1.
#
# Given "pwwkew", the answer is "wke", with the length of 3. Note that the answer
# must be a substring, "pwke" is a subsequence and not a substring.
#

class Solution(object):
    def lengthOfLongestSubstring(self, s):
        """
        :type s: str
        :rtype: int
        """
        char_table = {}
        back = 0
        ret = 0
        for front in range(len(s)):
            if (s[front] not in char_table) or (char_table[s[front]] < back):
                ret = max(ret, front - back + 1)
            else:
                back = char_table[s[front]] + 1
            char_table[s[front]] = front
        return ret
