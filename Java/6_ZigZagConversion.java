/* The string "PAYPALISHIRING" is written in a zigzag pattern on a given number
* of rows like this: (you may want to display this pattern in a fixed font for
* better legibility)
*
* P   A   H   N
* A P L S I I G
* Y   I   R
* And then read line by line: "PAHNAPLSIIGYIR"
*
* Write the code that will take a string and make this conversion given a number
* of rows:
*
* string convert(string text, int nRows);
* convert("PAYPALISHIRING", 3) should return "PAHNAPLSIIGYIR".
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