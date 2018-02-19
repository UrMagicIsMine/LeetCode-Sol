/* Given a triangle, find the minimum path sum from top to bottom.
* Each step you may move to adjacent numbers on the row below.
*
* For example, given the following triangle
* [
*      [2],
*     [3,4],
*    [6,5,7],
*   [4,1,8,3]
* ]
* The minimum path sum from top to bottom is 11 (i.e., 2 + 3 + 5 + 1 = 11).
*
* Note:
* Bonus point if you are able to do this using only O(n) extra space,
* where n is the total number of rows in the triangle.
*/
#include <vector>
#include <algorithm>

using namespace std;

	/* DP solution 1, O(1) storage if original triangle can be modified */

int minimumTotal_Sol1(vector<vector<int>>& triangle) {

	int N = triangle.size();
	if (N == 0)
		return 0;
	for (int i = N - 2; i >= 0; i--)
		for (int j = 0; j <= i; j++)
			triangle[i][j] += min(triangle[i + 1][j], triangle[i + 1][j + 1]);

	return triangle[0][0];
}

	/* DP solution 2, O(n) storage if original triangle cannot be modified */

int minimumTotal_Sol2(vector<vector<int>>& triangle) {

	int N = triangle.size();

	if (N == 0)
		return 0;

	vector<int> dpTmp(triangle[N - 1]);
	for (int i = N - 2; i >= 0; i--)
		for (int j = 0; j <= i; j++)
			dpTmp[j] = min(dpTmp[j], dpTmp[j+1]) + triangle[i][j];

	return dpTmp[0];
}


int main()
{
	vector<vector<int>> triangle = { {2},{3,4},{6,5,7},{ 4,1,8,3 } };
	int ret1 = minimumTotal_Sol1(triangle);
	int ret2 = minimumTotal_Sol2(triangle);
	return 0;
}
