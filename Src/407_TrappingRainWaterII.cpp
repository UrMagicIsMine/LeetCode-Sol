/*
Given an m x n matrix of positive integers representing the height of each unit
cell in a 2D elevation map, compute the volume of water it is able to trap after
raining.

Note:
Both m and n are less than 110. The height of each unit cell is greater than 0
and is less than 20,000.

Example:

Given the following 3x6 height map:
[
[1,4,3,1,3,2],
[3,2,1,3,2,4],
[2,3,3,2,3,1]
]

Return 4.
*/

#include <vector>
#include <string>
#include <set>
#include <queue>
#include <algorithm>
#include <functional>
#include <cassert>
using namespace std;


/*
heap with BFS
*/

int trapRainWater(vector<vector<int>>& heightMap) {
	int resl = 0;
	int M = heightMap.size();
	if (M < 2) return 0;
	int N = heightMap[0].size();
	if (N < 2) return 0;

	typedef pair<int, int> pos_t;
	typedef pair<int, pos_t> elem_t;
	priority_queue<elem_t, vector<elem_t>, greater<elem_t>> heap;
	vector<vector<bool>> visited(M, vector<bool>(N, false));
	for (int j = 0; j < N; j++) {
		heap.push(elem_t(heightMap[0][j], pos_t(0, j)));
		visited[0][j] = true;
		heap.push(elem_t(heightMap[M - 1][j], pos_t(M - 1, j)));
		visited[M - 1][j] = true;
	}

	for (int i = 1; i < M - 1; i++) {
		heap.push(elem_t(heightMap[i][0], pos_t(i, 0)));
		visited[i][0] = true;
		heap.push(elem_t(heightMap[i][N - 1], pos_t(i, N - 1)));
		visited[i][N - 1] = true;
	}
	int maxb = 0;
	int dir[4][2] = { { 1,0 },{ -1,0 },{ 0,1 },{ 0,-1 } };
	int x = 0, y = 0;
	while (!heap.empty()) {
		auto tmp = heap.top();
		heap.pop();
		if (tmp.first < maxb)
			resl += maxb - tmp.first;
		else
			maxb = tmp.first;

		for (int i = 0; i < 4; i++) {
			x = tmp.second.first + dir[i][0];
			y = tmp.second.second + dir[i][1];
			if (x >= 0 && x < M && y >= 0 && y < N && !visited[x][y]) {
				visited[x][y] = true;
				heap.push(elem_t(heightMap[x][y], pos_t(x, y)));
			}
		}
	}

	return resl;
}
int main()
{
	vector<vector<int>> heightMap = { {12, 13, 1, 12},
                                    {13, 4, 13, 12},
                                    {13, 8, 10, 12},
                                    {12, 13, 12, 12},
                                    {13, 13, 13, 13} };
	int ans = 14;
	int ret = trapRainWater(heightMap);
	assert(ret = ans);
	return 0;
}
