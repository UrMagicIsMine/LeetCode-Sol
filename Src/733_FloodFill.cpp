/* An image is represented by a 2-D array of integers, each integer representing
* the pixel value of the image (from 0 to 65535).
*
* Given a coordinate (sr, sc) representing the starting pixel (row and column)
* of the flood fill, and a pixel value newColor, "flood fill" the image.
*
* To perform a "flood fill", consider the starting pixel, plus any pixels
* connected 4-directionally to the starting pixel of the same color as the
* starting pixel, plus any pixels connected 4-directionally to those pixels
* (also with the same color as the starting pixel), and so on. Replace the color
* of all of the aforementioned pixels with the newColor.
*
* At the end, return the modified image.
*
* Example 1:
* Input:
* image = [[1,1,1],[1,1,0],[1,0,1]]
* sr = 1, sc = 1, newColor = 2
* Output: [[2,2,2],[2,2,0],[2,0,1]]
* Explanation:
* From the center of the image (with position (sr, sc) = (1, 1)), all pixels connected
* by a path of the same color as the starting pixel are colored with the new color.
* Note the bottom corner is not colored 2, because it is not 4-directionally connected
* to the starting pixel.
* Note:
*
* The length of image and image[0] will be in the range [1, 50].
* The given starting pixel will satisfy 0 <= sr < image.length and 0 <= sc < image[0].length.
* The value of each color in image[i][j] and newColor will be an integer in [0, 65535].
*/

#include <vector>
#include <cassert>
using namespace std;

void _DFSfill(vector<vector<int>> & image, int sr, int sc, const pair<int, int>& dim, int origColor, int newColor) {

	if (sr >= 0 && sr < dim.first && sc >= 0 && sc < dim.second && image[sr][sc] == origColor) {

		image[sr][sc] = newColor;
		_DFSfill(image, sr - 1, sc, dim, origColor, newColor);
		_DFSfill(image, sr, sc - 1, dim, origColor, newColor);
		_DFSfill(image, sr + 1, sc, dim, origColor, newColor);
		_DFSfill(image, sr, sc + 1, dim, origColor, newColor);
	}
	return;
}

vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int newColor) {

	pair<int, int> dim = make_pair(image.size(), image[0].size());

	if (sr >= 0 && sr < dim.first && sc >= 0 && sc < dim.second) {
		int origColor = image[sr][sc];
		if (origColor != newColor)
			_DFSfill(image, sr, sc, dim, origColor, newColor);
	}
	return image;
}

int main()
{
	vector<vector<int>> images = { {1,1,1 }, { 1,1,0 }, { 1,0,1 } };
	int sr = 1, sc = 1;
	vector<vector<int>> ans = { { 2,2,2 },{ 2,2,0 },{ 2,0,1 } };
	vector<vector<int>> ret = floodFill(images, sr, sc, 2);
	assert(ret == ans);
	return 0;
}
