/*
Given a n x n matrix where each of the rows and columns are sorted in ascending order, find the kth smallest element in the matrix.

Note that it is the kth smallest element in the sorted order, not the kth distinct element.

Example:

matrix = [
[ 1,  5,  9],
[10, 11, 13],
[12, 13, 15]
],
k = 8,

return 13.
Note:
You may assume k is always valid, 1 <= k <= n^2.
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
Build a minHeap of elements from the first row.
Do the following operations k-1 times :
Every time when you poll out the root(Top Element in Heap),
you need to know the row number and column number of that element
(so we can create a tuple class here),
replace that root with the next element from the same column.
*/

int kthSmallest_HP(vector<vector<int>>& matrix, int k) {

	typedef pair<int, int> pos_t;
	typedef pair<int, pos_t> elem_t;
	priority_queue<elem_t, vector<elem_t>, std::greater<elem_t>> heap;
	int N = matrix.size();

	for (int j = 0; j < N; j++) {
		heap.push(elem_t(matrix[0][j], pos_t(0, j)));
	}
	int ret = 0, i = 0, j = 0;
	while (k--) {
		ret = heap.top().first;
		i = heap.top().second.first;
		j = heap.top().second.second;
		heap.pop();
		if (i == N - 1)
			continue;
		heap.push(elem_t(matrix[i + 1][j], pos_t(i + 1, j)));
	}

	return ret;
}

/*
The key point for any binary search is to figure out the "Search Space".
For me, I think there are two kind of "Search Space" -- index and range
(the range from the smallest number to the biggest number).
  -- when the array is sorted in one direction, we can use index as "search space",
  -- when the array is unsorted and we are going to find a specific number, we can use "range".
*/

int kthSmallest_BS(vector<vector<int>>& matrix, int k) {

	int N = matrix.size();
	int lo = matrix[0][0], hi = matrix[N - 1][N - 1], mid;

	while (lo < hi) {
		int cnt = 0;
		mid = (lo + hi) / 2;
		for (int i = 0; i < N; i++) {
			int j = N - 1;
			while (j >= 0 && matrix[i][j] > mid) j--;
			cnt += j + 1;
		}
		if (cnt < k) lo = mid + 1;
		else hi = mid;
	}

	return lo;
}


int main()
{
	vector<vector<int>> matrix = { {1,  5,  9}, {10, 11, 13}, {12, 13, 15} };
	int k = 8, ans = 13;
	int ret = kthSmallest_BS(matrix, k);
	assert(ret = ans);
	return 0;
}
