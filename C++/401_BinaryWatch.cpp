/*A binary watch has 4 LEDs on the top which represent the hours (0-11), and the
* 6 LEDs on the bottom represent the minutes (0-59).
*
* Each LED represents a zero or one, with the least significant bit on the right.
*
*
* For example, the above binary watch reads "3:25".
*
* Given a non-negative integer n which represents the number of LEDs that are
* currently on, return all possible times the watch could represent.
*
* Example:
*
* Input: n = 1
* Return: ["1:00", "2:00", "4:00", "8:00", "0:01", "0:02", "0:04", "0:08", "0:16",
*          "0:32"]
* Note:
* The order of output does not matter.
* The hour must not contain a leading zero, for example "01:00" is not valid, it
* should be "1:00".
* The minute must be consist of two digits and may contain a leading zero, for
* example "10:2" is not valid, it should be "10:02".
*/

#include <string>
#include <bitset>
#include <vector>
#include <map>
#include <algorithm>
#include <cassert>
using namespace std;

vector<string> readBinaryWatch_Sln1(int num) {
	vector<string> resl;
	map<int, vector<string>> nLEDtoHour;
	map<int, vector<string>> nLEDtoMinu;

	for (int i = 0; i < 60; i++) {
		bitset<6> bits(i);
		int cnt = 0;
		for (int b = 0; b < 6; b++) {
			if (bits.test(b))
				cnt++;
		}
		if (i < 12) {
			nLEDtoHour[cnt].push_back(to_string(i));
		}
		nLEDtoMinu[cnt].push_back((i < 10 ? "0" : "") + to_string(i));
	}

	for (int i = 0; i <= num; i++) {
		auto h = nLEDtoHour.find(i);
		auto m = nLEDtoMinu.find(num - i);
		if (h != nLEDtoHour.end() && m != nLEDtoMinu.end()) {

			for (int hi = 0; hi < h->second.size(); hi++)
				for (int mi = 0; mi < m->second.size(); mi++)
					resl.push_back(h->second[hi] + ":" + m->second[mi]);
		}
	}
	return resl;

}

vector<string> readBinaryWatch_Sln2(int num) {
	vector<string> resl;
	for (int h = 0; h < 12; h++)
		for (int m = 0; m < 60; m++)
			if (bitset<10>(h << 6 | m).count() == num)
				resl.emplace_back(to_string(h) + ":" + (m < 10 ? "0" : "") + to_string(m));
	return resl;
}

int main()
{
	int num = 1;
	vector<string> ret1 = readBinaryWatch_Sln1(5);
	vector<string> ret2 = readBinaryWatch_Sln2(5);
	sort(ret1.begin(), ret1.end());
	sort(ret2.begin(), ret2.end());
	assert(ret1 == ret2);
	return 0;
}
