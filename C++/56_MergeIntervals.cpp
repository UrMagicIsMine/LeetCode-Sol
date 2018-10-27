/* Given a collection of intervals, merge all overlapping intervals.

Example 1:

Input: [[1,3],[2,6],[8,10],[15,18]]
Output: [[1,6],[8,10],[15,18]]
Explanation: Since intervals [1,3] and [2,6] overlaps, merge them into [1,6].
Example 2:

Input: [[1,4],[4,5]]
Output: [[1,5]]
Explanation: Intervals [1,4] and [4,5] are considerred overlapping.
*/

#include <string>
#include <vector>
#include <algorithm>
#include <functional>
#include <cassert>
using namespace std;

/**
* Definition for an interval.
*/
struct Interval {
	int start;
	int end;
	Interval() : start(0), end(0) {}
	Interval(int s, int e) : start(s), end(e) {}
};

vector<Interval> merge(vector<Interval>& intervals) {

	auto lambda = [](Interval& l, Interval& r) {
		return l.start < r.start || ((l.start == r.start) && l.end < r.end);
	};

	sort(intervals.begin(), intervals.end(), lambda);
	vector<Interval> resl;
	for (int i = 0; i < intervals.size(); i++) {
		if (resl.empty()) {
			resl.push_back(intervals[i]);
			continue;
		}
		Interval& iback = resl.back();
		if (iback.end < intervals[i].start) {
			resl.push_back(intervals[i]);
			continue;
		}
		else if (iback.end < intervals[i].end) {
			iback.end = intervals[i].end;
		}
	}
	return resl;
}

int main()
{
	int n = 3;
	vector<Interval> intervals = { {1, 3},{2, 6},{8, 10},{15, 18} };
	vector<Interval> ans = { {1,6},{8,10},{15,18} };
	vector<Interval> ret = merge(intervals);
	assert(ret == ans);
	return 0;
}
