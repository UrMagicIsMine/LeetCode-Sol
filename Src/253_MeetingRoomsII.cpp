/*
Given an array of meeting time intervals consisting of start and end times
[[s1,e1],[s2,e2],...] (si < ei), find the minimum number of conference rooms
required.

Example 1:

Input: [[0, 30],[5, 10],[15, 20]]
Output: 2
Example 2:

Input: [[7,10],[2,4]]
Output: 1
*/

#include <vector>

/**
 * Definition for an interval.
 */
struct Interval {
  int start;
  int end;
  Interval() : start(0), end(0) {}
  Interval(int s, int e) : start(s), end(e) {}
};

int minMeetingRooms(vector<Interval>& intervals) {
    vector<pair<int, int>> events;
    for(auto & p : intervals){
        events.emplace_back(p.start, 1);
        events.emplace_back(p.end, -1);
    }

    sort(events.begin(), events.end());
    int maxRooms = 0, rooms = 0;
    for(auto &p : events){
        rooms += p.second;
        maxRooms = max(maxRooms, rooms);
    }
    return maxRooms;
}


int minMeetingRooms(vector<Interval>& intervals) {

    auto lambda = [](const Interval & p1, const Interval & p2){
        return p1.start < p2.start;
    };

    sort(intervals.begin(), intervals.end(), lambda);
    priority_queue<int, vector<int>, greater<int>> minHeap;
    for(auto & p : intervals){
        if(!minHeap.empty() && minHeap.top() <= p.start)
            minHeap.pop();
        minHeap.push(p.end);
    }
    return minHeap.size();

}
