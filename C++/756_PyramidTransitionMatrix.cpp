/* We are stacking blocks to form a pyramid. Each block has a color which is a
* one letter string, like `'Z'`.
*
* For every block of color `C` we place not in the bottom row, we are placing it
* on top of a left block of color `A` and right block of color `B`. We are allowed
* to place the block there only if `(A, B, C)` is an allowed triple.
*
* We start with a bottom row of bottom, represented as a single string. We also
* start with a list of allowed triples allowed. Each allowed triple is represented
* as a string of length 3.
*
* Return true if we can build the pyramid all the way to the top, otherwise false.
*
* Example 1:
* Input: bottom = "XYZ", allowed = ["XYD", "YZE", "DEA", "FFF"]
* Output: true
* Explanation:
* We can stack the pyramid like this:
*     A
*    / \
*   D   E
*  / \ / \
* X   Y   Z
*
* This works because ('X', 'Y', 'D'), ('Y', 'Z', 'E'), and ('D', 'E', 'A') are allowed triples.
* Example 2:
* Input: bottom = "XXYX", allowed = ["XXX", "XXY", "XYX", "XYY", "YXZ"]
* Output: false
* Explanation:
* We can't stack the pyramid to the top.
* Note that there could be allowed triples (A, B, C) and (A, B, D) with C != D.
* Note:
* bottom will be a string with length in range [2, 8].
* allowed will have length in range [0, 200].
* Letters in all strings will be chosen from the set {'A', 'B', 'C', 'D', 'E', 'F', 'G'}.
* Notice that the allowed string can be used multiple times.
*/

#include <string>
#include <vector>
#include <cassert>
using namespace std;

bool _match(string & sz, string &target, int pos) {

	return sz[0] == target[pos] && sz[1] == target[pos + 1];
}

bool _DFS(string down, string up, int pos, vector<string>& allowed) {

	if (down.size() == 1)
		return true;

	for (int i = 0; i < allowed.size(); i++) {

		if (_match(allowed[i], down, pos)) {

			up.push_back(allowed[i][2]);
			if (up.size() + 1 == down.size()) {
				bool ret = _DFS(up, "", 0, allowed);
				if (ret)
					return true;
			}
			else {
				bool ret = _DFS(down, up, pos + 1, allowed);
				if (ret)
					return true;
			}
			up.pop_back();
		}
	}
	return false;
}

bool pyramidTransition(string bottom, vector<string>& allowed) {

	return _DFS(bottom, "", 0, allowed);
}

int main()
{
	string bottom = "BCD";
	vector<string> allowed = { "ACC","ACB","ABD","DAA","BDC","BDB","DBC",
							   "BBD","BBC","DBD","BCC","CDD","ABA","BAB",
							   "DDC","CCD","DDA","CCA","DDD" };
	bool ans = true;
	bool ret = pyramidTransition(bottom, allowed);
	assert(ret == ans);
	return 0;
}
