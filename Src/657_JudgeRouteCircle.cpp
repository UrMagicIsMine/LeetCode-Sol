/* Initially, there is a Robot at position (0, 0). Given a sequence of its moves,
* judge if this robot makes a circle, which means it moves back to the original place.
*
* The move sequence is represented by a string. And each move is represent by a
* character. The valid robot moves are R (Right), L (Left), U (Up) and D (down).
* The output should be true or false representing whether the robot makes a circle.
*
* Example 1:
* Input: "UD"
* Output: true
* Example 2:
* Input: "LL"
* Output: false
*/

#include <unordered_set>
#include <vector>
#include <cassert>
using namespace std;

bool judgeCircle(string moves) {

	int LR = 0, UD = 0;

	for (int i = 0; i < moves.size(); i++) {
		switch (moves[i]) {
		case 'L':
			LR++;
			break;
		case 'R':
			LR--;
			break;
		case 'U':
			UD++;
			break;
		case 'D':
			UD--;
			break;
		}
	}
	return LR == 0 && UD == 0;
}

int main()
{
	bool ret = judgeCircle("LUDLLDDUU");
	bool ans = false;
	assert(ret == ans);
	return 0;
}
