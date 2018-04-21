/* Given n points on a 2D plane, find the maximum number of points that lie on the same straight line.
*
* Example 1:
*
* Input: [[1,1],[2,2],[3,3]]
* Output: 3
* Explanation:
* ^
* |
* |        o
* |     o
* |  o
* +------------->
* 0  1  2  3  4
* Example 2:
*
* Input: [[1,1],[3,2],[5,3],[4,1],[2,3],[1,4]]
* Output: 4
* Explanation:
* ^
* |
* |  o
* |     o        o
* |        o
* |  o        o
* +------------------->
* 0  1  2  3  4  5  6
*/

#include <vector>
#include <algorithm>
#include <map>
#include <cassert>
using namespace std;

/**
* Definition for a point.
*/
struct Point {
	int x;
	int y;
	Point() : x(0), y(0) {}
	Point(int a, int b) : x(a), y(b) {}
};

int gcd(int a, int b) {
	if (b)
		while ((a %= b) && (b %= a));
	return a + b;
}

/*
We start from a specific point p, and compute all the slopes of the lines between
p and the remaining points. Then those with the same slopes will be the same line.
We can find out the maximum number of points fall on a line containing p. We
exhaust all possible p's and record the largest number we have seen.

to represent the slope (dy / dx), we record dx and dy in a pair<int, int>, because
dy = 4, dx = 2 and dy = 8, dx = 4 represents the same slope, we need to divide
both of them by their gcd first.

Run-time O(N^2logN), space O(N)
*/

int maxPoints(vector<Point>& points) {

	int N = points.size(), ret = 0;
	map<pair<int, int>, int> LinePts;

	for (int i = 0; i < N; i++) {

		LinePts.clear();
		int duplicates = 1;
		for (int j = i + 1; j < N; j++) {

			if (points[j].x == points[i].x && points[j].y == points[i].y) {
				duplicates++;
				continue;
			}
			int dx = points[j].x - points[i].x;
			int dy = points[j].y - points[i].y;
			int c = gcd(dx, dy);
			LinePts[make_pair(dx / c, dy / c)]++;
		}
		ret = max(ret, duplicates);
		for (auto pts : LinePts)
			ret = max(ret, pts.second + duplicates);
	}
	return ret;
}

int main()
{
	vector<Point> pts = { {1,1 }, { 2,2 }, { 3,3 } };
	int ans = 3;
	int ret = maxPoints(pts);
	assert(ret == ans);
	return 0;
}
