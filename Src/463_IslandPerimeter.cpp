/*
You are given a map in form of a two-dimensional integer grid where 1 represents
land and 0 represents water. Grid cells are connected horizontally/vertically
(not diagonally). The grid is completely surrounded by water, and there is exactly
one island (i.e., one or more connected land cells). The island doesn't have "lakes"
(water inside that isn't connected to the water around the island). One cell is
a square with side length 1. The grid is rectangular, width and height don't
exceed 100. Determine the perimeter of the island.

Example:

[[0,1,0,0],
 [1,1,1,0],
 [0,1,0,0],
 [1,1,0,0]]

Answer: 16
Explanation: The perimeter is the 16 yellow stripes in the image below:
*/

#include <vector>

int _cntPer(vector<vector<int>> &grid, int M, int N, int i, int j){
    if(i < 0 || i == M || j < 0 || j == N)
        return 1;
    return grid[i][j] == 0;
}

int islandPerimeter(vector<vector<int>>& grid) {
    int M = grid.size();
    int N = grid[0].size();
    int ret = 0;
    for(int i = 0; i < M; i++){
        for(int j = 0; j < N; j++){
            if(grid[i][j] == 1){
                ret += _cntPer(grid,M, N, i-1,j)
                     + _cntPer(grid,M, N, i+1,j)
                     + _cntPer(grid,M, N, i,j-1)
                     + _cntPer(grid,M, N, i,j+1);
            }
        }
    }
    return ret;
}
