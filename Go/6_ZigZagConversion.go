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

func convert(s string, numRows int) string {
    if numRows == 1 {
        return s
    }
    Rows := make([][]rune, numRows)
    dir := -1
    curRow := 0
    for _, c := range(s) {
        Rows[curRow] = append(Rows[curRow], c)
        if curRow == 0 || curRow == numRows - 1 {
            dir = -dir
        }
        curRow += dir
    }
    ret := ""
    for _, row := range(Rows) {
        ret += string(row)
    }
    return ret
}
