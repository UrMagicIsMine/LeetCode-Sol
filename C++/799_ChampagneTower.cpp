/* We stack glasses in a pyramid, where the first row has 1 glass, the second row
* has 2 glasses, and so on until the 100th row.  Each glass holds one cup (250ml)
* of champagne.
*
* Then, some champagne is poured in the first glass at the top.  When the top most
* glass is full, any excess liquid poured will fall equally to the glass immediately
* to the left and right of it.  When those glasses become full, any excess champagne
* will fall equally to the left and right of those glasses, and so on.  (A glass at
* the bottom row has it's excess champagne fall on the floor.)
*
* For example, after one cup of champagne is poured, the top most glass is full.
* After two cups of champagne are poured, the two glasses on the second row are
* half full.  After three cups of champagne are poured, those two cups become full
* - there are 3 full glasses total now.  After four cups of champagne are poured,
* the third row has the middle glass half full, and the two outside glasses are a
* quarter full, as pictured below.
*/

#include <vector>
#include <cassert>
using namespace std;

double champagneTower(int poured, int query_row, int query_glass) {

	double amount = poured;
	vector<vector<double>> glass;

	int index = 0;
	glass.push_back(vector<double>(1, 0));
	glass[0][0] = amount;

	for (int row = 0; row <= query_row; ++row)
	{
		glass.push_back(vector<double>(row + 2, 0));
		for (int col = 0; col <= row; ++col)
		{
			amount = glass[row][col];
			glass[row][col] = (amount >= 1.0f) ? 1.0f : amount;
			amount = (amount >= 1.0f) ? (amount - 1) : 0.0f;
			glass[row + 1][col] += amount / 2;
			glass[row + 1][col + 1] += amount / 2;
		}
	}

	return glass[query_row][query_glass];
}


int main()
{
	int pour = 6;
	double ans = 0.75;
	double ret = champagneTower(6,2,0);
	assert(abs(ans - ret) < 1E-12);
	return 0;

}
