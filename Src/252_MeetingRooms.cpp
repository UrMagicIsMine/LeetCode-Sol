/*
Given an array of meeting time intervals consisting of start and end times
[[s1,e1],[s2,e2],...] (si < ei), determine if a person could attend all meetings.

Example 1:

Input: [[0,30],[5,10],[15,20]]
Output: false
Example 2:

Input: [[7,10],[2,4]]
Output: true
*/

bool canAttendMeetings(vector<Interval>& intervals) {

    if(intervals.size() < 2)
        return true;

    auto lambda = [](const Interval& i1, const Interval& i2){
        return i1.start < i2.start;
    };

    sort(intervals.begin(), intervals.end(), lambda);
    int end = intervals[0].end;

    for(int i = 1; i < intervals.size(); i++){
        if(intervals[i].start < end)
            return false;
        else
            end = intervals[i].end;
    }
    return true;
}
