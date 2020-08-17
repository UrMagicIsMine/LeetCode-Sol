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

public String convert(String s, int numRows) {
    if (numRows == 1) return s;
    List<StringBuilder> rows = new ArrayList<>();
    for (int i = 0; i < numRows; i++) {
        rows.add(new StringBuilder());
    }
    int dir = -1;
    int curRow = 0;
    for (char c : s.toCharArray()) {
        rows.get(curRow).append(c);
        if (curRow == 0 || curRow == numRows - 1) {
            dir = -dir;
        }
        curRow += dir;
    }
    StringBuilder ret = new StringBuilder();
    for (StringBuilder row : rows)
        ret.append(row);
    return ret.toString();
}
