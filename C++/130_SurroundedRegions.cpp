/* Given a 2D board containing 'X' and 'O' (the letter O), capture all regions surrounded by 'X'.
*
* A region is captured by flipping all 'O's into 'X's in that surrounded region.
*
* For example, After running your function, the board should be:
* X X X X         X X X X
* X O O X   --->  X X X X
* X X O X         X X X X
* X O X X         X O X X
*
*/
#include <vector>

using namespace std;

/*
* Step 1: check the four border of the matrix.If there is a element is
*         'O', change all its neighbor 'O' elements to '#'.
*
* Step 2: change all the 'O' to 'X' (those have to be surronded)
*
* Step 3: change back all the '#' to ‘O’
*
* For example :
*
* X X X X           X X X X             X X X X
* X X O X    ->	    X X O X	  ->	      X X X X
* X O X X           X # X X             X O X X
* X O X X           X # X X             X O X X
*
*/
void check(int i, int j, vector<vector<char>> &board, int M, int N) {

	if (board[i][j] == 'O') {
		board[i][j] = '#';
		if (i > 0)
			check(i - 1, j, board, M, N);
		if (j > 0)
			check(i, j - 1, board, M, N);
		if (i < M - 1)
			check(i + 1, j, board, M, N);
		if (j < N - 1)
			check(i, j + 1, board, M, N);
	}
	return;
}

void solve(vector<vector<char>>& board) {

	int M = board.size();
	if (M == 0)
		return;
	int N = board[0].size();
	if (N == 0)
		return;

	for (int i = 0; i < M; i++)
	{
		check(i, 0, board, M, N);
		check(i, N - 1, board, M, N);
	}
	for (int j = 0; j < N; j++)
	{
		check(0, j, board, M, N);
		check(M - 1, j, board, M, N);
	}

	for (int i = 0; i < M; i++) {
		for (int j = 0; j < N; j++) {
			if (board[i][j] == 'O')
				board[i][j] = 'X';
			if (board[i][j] == '#')
				board[i][j] = 'O';
		}
	}

	return;

}

int main()
{
	vector<vector<char>> board =  { { 'X','X','X','X' },
									{ 'X','O','O','X' },
									{ 'X','X','O','X' },
									{ 'X','O','X','X' }};
	solve(board);
	return 0;
}
