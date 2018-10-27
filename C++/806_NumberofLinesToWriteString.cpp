/* We are to write the letters of a given string S, from left to right into lines.
* Each line has maximum width 100 units, and if writing a letter would cause the
* width of the line to exceed 100 units, it is written on the next line. We are
* given an array widths, an array where widths[0] is the width of 'a', widths[1]
* is the width of 'b', ..., and widths[25] is the width of 'z'.
*
* Now answer two questions: how many lines have at least one character from S,
* and what is the width used by the last such line? Return your answer as an
* integer list of length 2.
*
* Example :
* Input:
* widths = [10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10]
* S = "abcdefghijklmnopqrstuvwxyz"
* Output: [3, 60]
* Explanation:
* All letters have the same length of 10. To write all 26 letters,
* we need two full lines and one line with 60 units.
*/

#include <vector>
#include <string>
#include <cassert>
using namespace std;

vector<int> numberOfLines(vector<int>& widths, string S) {
	vector<int> resl(2, 0);

	int sum = 0;
	for (auto c : S) {
		sum += widths[c - 'a'];
		if (sum > 100) {
			resl[0]++;
			sum = widths[c - 'a'];
		}
	}
	if (sum > 0)
		resl[0]++;
	resl[1] = sum;

	return resl;
}
int main()
{
	vector<int> widths = { 4,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10 };
	string S = "bbbcccdddaaa";
	vector<int> ret = numberOfLines(widths, S);
	vector<int> ans = { 2,4 };
	assert(ret == ans);
	return 0;
}
