/* Given n non-negative integers representing the histogram's bar height where the width of each bar is 1, find the area of largest rectangle in the histogram.
Above is a histogram where width of each bar is 1, given height = [2,1,5,6,2,3].
The largest rectangle is shown in the shaded area, which has area = 10 unit.

Example:

Input: [2,1,5,6,2,3]
Output: 10
*/

#include <vector>
#include <algorithm>
#include <stack>
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

/* split into left and right intervals, then handle overlapping intervals */
vector<Interval> insert(vector<Interval>& intervals, Interval newInterval) {

	vector<Interval> left, right;
	int N = intervals.size();
	for (int i = 0; i < N; i++) {
		if (intervals[i].end < newInterval.start)
			left.push_back(intervals[i]);
		if (intervals[i].start > newInterval.end)
			right.push_back(intervals[i]);
	}
	Interval mid = newInterval;
	if (left.size() + right.size() != intervals.size()) {
		mid.start = min(newInterval.start, intervals[left.size()].start);
		mid.end = max(newInterval.end, intervals[N - right.size() - 1].end);

	}
	left.push_back(mid);
	left.insert(left.end(), right.begin(), right.end());
	return left;
}

int main()
{
	vector<Interval> intervals = { {1, 2},{3, 5},{6, 7},{8, 10},{12, 16 }};
	Interval newInterval(4, 8);
	vector<Interval> ans = { {1,2 }, { 3,10 }, { 12,16 }};
	vector<Interval> ret = insert(intervals, newInterval);
	assert(ret.size() == ans.size());
	for (int i = 0; i < ret.size(); i++) {
		assert(ret[i].start == ans[i].start);
		assert(ret[i].end == ans[i].end);
	}
	return 0;
}
