/*Find the total area covered by two rectilinear rectangles in a 2D plane.

Each rectangle is defined by its bottom left corner and top right corner as shown in the figure.


                 |-----------------------| (G,H)
							   |                       |
							   |                       |
        --------------------  (C,D)      |
				|			   |         |             |
			  |			   |         |             |
 (A,B)  --------------------             |
                 |                       |
							   |                       |
					(E,F)  |------------------------

Assume that the total area is never beyond the maximum possible value of int.

*/

#include <algorithm>
#include <cassert>
using namespace std;

int computeArea(int A, int B, int C, int D, int E, int F, int G, int H) {

	int left = max(A, E);
	int right = max(left, min(C, G));
	int low = max(B, F);
	int high = max(low, min(D, H));
	return (C - A)*(D - B) + (G - E)*(H - F) - (right - left)*(high - low);

}

int main()
{
	int ret = computeArea(-2, -2, 2, 2, -2, -2, 2, 2);
	int ans = 16;
	assert(ret == ans);
	return 0;
}
