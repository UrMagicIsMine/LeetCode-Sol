/* A sequence of number is called arithmetic if it consists of at least three
* elements and if the difference between any two consecutive elements is the same.
*
* For example, these are arithmetic sequence:
*
* 1, 3, 5, 7, 9
* 7, 7, 7, 7
* 3, -1, -5, -9
* The following sequence is not arithmetic.
*
* 1, 1, 2, 5, 7
*
* A zero-indexed array A consisting of N numbers is given. A slice of that array
* is any pair of integers (P, Q) such that 0 <= P < Q < N.
*
* A slice (P, Q) of array A is called arithmetic if the sequence:
* A[P], A[p + 1], ..., A[Q - 1], A[Q] is arithmetic. In particular, this means
* that P + 1 < Q.
*
* The function should return the number of arithmetic slices in the array A.
*
*
* Example:
*
* A = [1, 2, 3, 4]
*
* return: 3, for 3 arithmetic slices in A: [1, 2, 3], [2, 3, 4] and [1, 2, 3, 4]
* itself.
*/

#include <vector>
#include <cassert>
using namespace std;

/* DP solution, O(n^2) */
int numberOfArithmeticSlices_Sln1(vector<int>& A) {
	int N = A.size();
	vector<int> dpVec(N + 1, 0);

	for (int i = 2; i < N; i++) {

		int cnt = 0;
		if (A[i] - A[i - 1] == A[i - 1] - A[i - 2]) {
			cnt = 1;
			int diff = A[i] - A[i - 1];
			for (int j = i - 3; j >= 0 && A[j + 1] - A[j] == diff; j--)
				cnt++;
		}
		dpVec[i + 1] = dpVec[i] + cnt;
	}

	return dpVec[N];
}

/* Optimized solution, O(n) */

int numberOfArithmeticSlices_Sln2(vector<int>& A) {
	int N = A.size();
	if (N <= 2)
		return 0;

	int arithCnt = (A[2] - A[1] == A[1] - A[0]) ? 1 : 0;
	int resl = arithCnt;
	for (int i = 3; i < N; i++) {
		// See if A[i] can be merged with the previous Arithmetic slices
		arithCnt = (A[i] - A[i - 1] == A[i - 1] - A[i - 2]) ? arithCnt + 1 : 0;
		resl += arithCnt;
	}

	return resl;
}

int main()
{
	vector<int> array = {1, 2, 3, 4};
	int ans = 3;
	auto ret1 = numberOfArithmeticSlices_Sln1(array);
	assert(ret1 == ans);

	auto ret2 = numberOfArithmeticSlices_Sln2(array);
	assert(ret2 == ans);
	return 0;
}
