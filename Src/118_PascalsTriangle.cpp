/* Given numRows, generate the first numRows of Pascal's triangle.
*
* For example, given numRows = 5,
* Return
*
* [
*      [1],
*     [1,1],
*    [1,2,1],
*   [1,3,3,1],
*  [1,4,6,4,1]
* ]
*/
#include <vector>
#include <algorithm>

using namespace std;
typedef vector<int> vec1D;
typedef vector<vec1D> vec2D;

vector<vector<int>> generate(int numRows) {

	vec2D resl;
	resl.reserve(numRows);

	for (int i = 1; i <= numRows; i++)
		resl.push_back(std::move(vec1D(i, 1)));

	for (int i = 2; i <numRows; i++)
		for (int j = 1; j < i; j++)
			resl[i][j] = resl[i - 1][j - 1] + resl[i - 1][j];
	return resl;
}


int main()
{
	vec2D ret = generate(5);
	return 0;
}
