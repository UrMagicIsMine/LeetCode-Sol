/* Given an index k, return the kth row of the Pascal's triangle.
*
* For example, given k = 3,
* Return [1,3,3,1].
*
* Note:
* Could you optimize your algorithm to use only O(k) extra space?
*/
#include <vector>
#include <algorithm>

using namespace std;

vector<int> getRow1(int rowIndex) {

	vector<int> CurRow(rowIndex+1, 1);
	vector<int> NextRow(rowIndex+1, 1);
	int i = 2;
	while (i <= rowIndex) {

		for (int j = 1; j < i; j++)
			NextRow[j] = CurRow[j - 1] + CurRow[j];
		i++;
		std::swap(CurRow, NextRow);

	}
	return CurRow;
}

vector<int> getRow2(int rowIndex) {

		vector<int> row(rowIndex+1, 1);
		for(int iRow = 2; iRow <= rowIndex; iRow++){
				for(int j = iRow - 1; j >=1; j--)
						row[j] += row[j-1];
		}
		return row;
}

int main()
{
	vector<int> ret = getRow2(5);
	return 0;
}
