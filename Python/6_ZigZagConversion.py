# The string "PAYPALISHIRING" is written in a zigzag pattern on a given number
# of rows like this: (you may want to display this pattern in a fixed font for
# better legibility)
#
# P   A   H   N
# A P L S I I G
# Y   I   R
# And then read line by line: "PAHNAPLSIIGYIR"
#
# Write the code that will take a string and make this conversion given a number
# of rows:
#
# string convert(string text, int nRows);
# convert("PAYPALISHIRING", 3) should return "PAHNAPLSIIGYIR".
#

class Solution(object):
    def convert(self, s, numRows):
        """
        :type s: str
        :type numRows: int
        :rtype: str
        """
        if numRows == 1:
            return s
        rows = []
        for i in range(numRows):
            rows.append([])
        dir = -1
        curRow = 0
        for i in range(len(s)):
            rows[curRow].append(s[i])
            if curRow == 0 or curRow == numRows - 1:
                dir = -dir
            curRow += dir
        ret = ""
        for row in rows:
            ret += ''.join(row)
        return ret
