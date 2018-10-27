/* Given a list of 24-hour clock time points in "Hour:Minutes" format, find the
* minimum minutes difference between any two time points in the list.
* Example 1:
* Input: ["23:59","00:00"]
* Output: 1
* Note:
* The number of time points in the given list is at least 2 and won't exceed 20000.
* The input time is legal and ranges from 00:00 to 23:59.
*/
#include<vector>
#include <string>
#include <algorithm>
#include <cassert>
using namespace std;

int findMinDifference1(vector<string>& timePoints) {

	sort(timePoints.begin(), timePoints.end());

	int N = timePoints.size();
	int minDiff = INT_MAX;
	for (int i = 0; i < N; i++) {
		int mt1 = stoi(timePoints[i].substr(0, 2)) * 60 + stoi(timePoints[i].substr(3, 2));
		int mt2 = stoi(timePoints[(i + 1) % N].substr(0, 2)) * 60 + stoi(timePoints[(i + 1) % N].substr(3, 2));
		int diff = min(abs(mt2 - mt1), 1440 - abs(mt2 - mt1));
		minDiff = min(diff, minDiff);
	}
	return minDiff;
}

int findMinDifference2(vector<string>& timePoints) {

	if (timePoints.size() >= 1440)
		return 0;

	int N = 0;
	vector<bool> times(1440, false);
	for (int i = 0; i < timePoints.size(); i++) {
		int mt1 = stoi(timePoints[i].substr(0, 2)) * 60 + stoi(timePoints[i].substr(3, 2));
		if (times[mt1] == false) {
			times[mt1] = true;
			N++;
		}
		else
			return 0;
	}

	int first = 0;
	while (!times[first])
		first++;

	int minDiff = INT_MAX;
	int pre = first;
	int next = first + 1;
	for (int i = 0; i < N - 1; i++) {
		while (!times[next])
			next++;

		minDiff = min(minDiff, min(abs(next - pre), 1440 - abs(next - pre)));
		pre = next;
		next++;
	}
	minDiff = min(minDiff, min(abs(pre - first), 1440 - abs(pre - first)));
	return minDiff;
}

int main()
{
	vector<string> timePoints = { "23:59","00:00" };
	int ret1 = findMinDifference1(timePoints);
	int ret2 = findMinDifference2(timePoints);
	int ans = 1;
	assert(ret1 == ans);
	assert(ret2 == ans);
	return 0;
}
