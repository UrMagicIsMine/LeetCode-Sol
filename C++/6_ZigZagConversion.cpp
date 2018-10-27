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

#include <string>
#include <vector>
#include <numeric>
#include <algorithm>
#include <cassert>
using namespace std;

/*
* intuitive solution using direction to append, Run-time O(N) and Memory O(N)
*/

string convert(string s, int numRows) {

	int strLen = s.length();
	if (strLen <= numRows || numRows == 1) return s;

	vector<string> stranform(numRows);
	int iRow = 0, dir = -1;

	for (int i = 0; i < strLen; i++) {
		if (iRow == 0 || iRow == numRows - 1)
			dir = -dir;
		stranform[iRow] += s[i];
		iRow += dir;
	}
	return accumulate(stranform.begin(), stranform.end(), string(""));
}

int main()
{
	string s = "PAYPALISHIRING";
	int numRows = 3;
	string ans = "PAHNAPLSIIGYIR";
	string ret = convert(s, numRows);
	assert(ret == ans);
	return 0;
}
