/*
* Design a stack that supports push, pop, top, and retrieving the minimum
* element in constant time.
*
* push(x) -- Push element x onto stack.
* pop() -- Removes the element on top of the stack.
* top() -- Get the top element.
* getMin() -- Retrieve the minimum element in the stack.
*
*/

#include <vector>
#include <algorithm>
#include <cassert>
using namespace std;

/******************************************************************************/
/* Solution 1: update m_min variable when push or pop, pop is O(N) */

class MinStack_Sln1 {
public:
	/** initialize your data structure here. */
	MinStack_Sln1() {
		m_min = INT_MAX;
	}

	void push(int x) {
		if (x<m_min)
			m_min = x;
		m_vdata.push_back(x);
	}

	void pop() {
		if (m_vdata.size() == 0)
			return;

		int tmp = m_vdata.back();
		m_vdata.pop_back();
		if (m_vdata.size() == 0)
			m_min = INT_MAX;
		else if (tmp == m_min) {
			m_min = INT_MAX;
			for (auto it = m_vdata.begin(); it != m_vdata.end(); it++)
				m_min = min(*it, m_min);
		}
		return;
	}

	int top() {
		return m_vdata.back();
	}

	int getMin() {
		return m_min;
	}

private:
	vector<int> m_vdata;
	int m_min;
};

/******************************************************************************/
/* Solution 1: using a vector to maintain min value vector,
* update the vector when push or pop, pop is O(1) in run-time
*/

class MinStack_Sln2 {
public:
	/** initialize your data structure here. */
	MinStack_Sln2() {
		m_vmin.push_back(INT_MAX);
	}

	void push(int x) {
		m_vstack.push_back(x);
		if (x < m_vmin.back())
			m_vmin.push_back(x);
		else
			m_vmin.push_back(m_vmin.back());
	}

	void pop() {
		m_vstack.pop_back();
		m_vmin.pop_back();
	}

	int top() {
		return m_vstack.back();
	}

	int getMin() {
		return m_vmin.back();
	}

private:
	vector<int> m_vstack;
	vector<int> m_vmin;
};

int main()
{
	MinStack_Sln1 minStack1;
	MinStack_Sln2 minStack2;
	minStack1.push(-2);
	minStack1.push(0);
	minStack1.push(-3);
	minStack2.push(-2);
	minStack2.push(0);
	minStack2.push(-3);
	int ret1, ret2;
	ret1 = minStack1.getMin();
	ret2 = minStack2.getMin();
	assert(ret1 = -3);
	assert(ret1 == ret2);
	minStack1.pop();
	minStack2.pop();

	ret1 = minStack1.top();
	ret2 = minStack2.top();
	assert(ret1 = 0);
	assert(ret1 == ret2);

	ret1 = minStack1.getMin();
	ret2 = minStack2.getMin();
	assert(ret1 = -2);
	assert(ret1 == ret2);
	return 0;
}
