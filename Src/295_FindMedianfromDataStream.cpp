/*
Median is the middle value in an ordered integer list. If the size of the list
is even, there is no middle value. So the median is the mean of the two middle
value.

For example,
[2,3,4], the median is 3

[2,3], the median is (2 + 3) / 2 = 2.5

Design a data structure that supports the following two operations:

void addNum(int num) - Add a integer number from the data stream to the data structure.
double findMedian() - Return the median of all elements so far.
Example:

addNum(1)
addNum(2)
findMedian() -> 1.5
addNum(3)
findMedian() -> 2
*/

#include <vector>
#include <queue>

class MedianFinder {
public:
    /** initialize your data structure here. */
    MedianFinder() {

    }

    void addNum(int num) {

        if(m_maxHeap.empty()){
            m_maxHeap.push(num);
            return;
        }
        else{
            if(num <= m_maxHeap.top()){
                m_maxHeap.push(num);
            }
            else{
                m_minHeap.push(num);
            }

            if(m_minHeap.size() == 2 + m_maxHeap.size()){
                int top = m_minHeap.top();
                m_minHeap.pop();
                m_maxHeap.push(top);
            }
            else if(m_maxHeap.size() == 2 + m_minHeap.size()){
                int top = m_maxHeap.top();
                m_maxHeap.pop();
                m_minHeap.push(top);
            }
            return;
        }

    }

    double findMedian() {
        if(m_maxHeap.size() == m_minHeap.size())
            return (m_minHeap.top() + m_maxHeap.top())/2.0;
        else if(m_maxHeap.size() < m_minHeap.size())
            return m_minHeap.top();
        else
            return m_maxHeap.top();
    }
private:

    priority_queue<int, vector<int>, less<int>> m_maxHeap;
    priority_queue<int, vector<int>, greater<int>> m_minHeap;
};
