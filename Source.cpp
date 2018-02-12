
using namespace std;

#include <iostream>
#include <limits>
#include <math.h>
#include <vector>
#include <set>
#include <algorithm>
#include <string>
#include <stack>
#include <map>

#define MPII(x,y) (make_pair(x,y))

bool validRange(const string & str, int ibeg, int ilen) {
	
	if (ilen > 3)
		return false;
	int i = stoi(str.substr(ibeg, ilen));
	return i >= 0 && i <= 255;
}

void saveResl(vector<string> & resl, const string & str, const vector<int> & dotloc) {

	string s(str.length() + 3, '0');
	int idot = 1, cnt = 0;
	for (int i = 0; i < str.length(); )
	{
		if (idot >=3 || i != dotloc[idot])
			s[cnt++] = str[i++];
		else {
			s[cnt++] = '.';
			idot++;
		}
	}
	resl.push_back(s);
}

void DFS(vector<string> &resl, const string & str, vector<int> & dotloc, int idot) {

	if (idot > 3 && validRange(str, dotloc[3], str.length()- dotloc[3]))
		saveResl(resl, str, dotloc);
	else if (idot <= 3) {
		for (int i = 1; i <= 3; i++) {
			if (dotloc[idot - 1] + i < str.length() && validRange(str, dotloc[idot - 1], i)) {
				dotloc[idot] = dotloc[idot - 1] + i;
				DFS(resl, str, dotloc, idot + 1);
			}
		}
	}
}

vector<string> restoreIpAddresses(string s) {

	vector<string> resl;
	vector<int> dotloc(4, 0);
	DFS(resl, s, dotloc, 1);
	return resl;

}

int main()
{

	//vector<vector<char>> board = { {'A', 'B', 'C', 'E'},{'S', 'F', 'C', 'S'},{'A', 'D', 'E', 'E'} };
	vector<string> ret = restoreIpAddresses("0000");
	return 0;
}