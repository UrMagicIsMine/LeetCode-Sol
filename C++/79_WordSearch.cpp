/* Given a 2D board and a word, find if the word exists in the grid.

The word can be constructed from letters of sequentially adjacent cell, where
"adjacent" cells are those horizontally or vertically neighboring. The same
letter cell may not be used more than once.

Example:

board =
[
  ['A','B','C','E'],
  ['S','F','C','S'],
  ['A','D','E','E']
]

Given word = "ABCCED", return true.
Given word = "SEE", return true.
Given word = "ABCB", return false.
*/
#include <vector>
#include <cassert>
using namespace std;

bool _DFS(vector<vector<char>>& board, int M, int N, int i, int j, const string& word, int idx){

		if(idx == word.length()){
				return true;
		}

		if( i < 0 || i >= M || j < 0 || j >= N || board[i][j] != word[idx] ){
				return false;
		}

		char tmp = board[i][j];
		board[i][j] = '#';

		bool found = _DFS(board, M, N, i+1, j, word, idx+1)
							|| _DFS(board, M, N, i-1, j, word, idx+1)
							|| _DFS(board, M, N, i, j+1, word, idx+1)
							|| _DFS(board, M, N, i, j-1, word, idx+1);

		board[i][j] = tmp;
		return found;
}

bool exist(vector<vector<char>>& board, string word) {
		int M = board.size();
		if(M == 0){
				return false;
		}
		int N = board[0].size();
		if(N == 0){
				return false;
		}

		for(int i = 0; i < M; i++){
				for(int j = 0; j < N; j++){
						if(_DFS(board, M, N, i, j, word, 0)){
								return true;
						}
				}
		}
		return false;
}

int main()
{
	vector<vector<char>> board = { { 'A','B','C','E' },{'S','F','C','S'},{'A','D','E','E'} };
	string word = "ABCCED";
	bool ans = true;
	bool ret = exist(board, word);
	assert(ret == ans);
	return 0;
}
