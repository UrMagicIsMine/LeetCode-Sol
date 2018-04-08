/* Given an array of integers and an integer k, find out whether there are two
* distinct indices i and j in the array such that nums[i] = nums[j] and the
* absolute difference between i and j is at most k.
*/

#include <vector>
#include <stack>
#include <cassert>
using namespace std;

class MyQueue {
public:
	/** Initialize your data structure here. */
	MyQueue() {

	}

	/** Push element x to the back of queue. */
	void push(int x) {

		stack<int> stack;
		int N = m_stack.size();
		while (N--) {
			stack.push(m_stack.top());
			m_stack.pop();
		}
		stack.push(x);
		N = stack.size();
		while (N--) {
			m_stack.push(stack.top());
			stack.pop();
		}
	}

	/** Removes the element from in front of queue and returns that element. */
	int pop() {
		int ret = m_stack.top();
		m_stack.pop();
		return ret;
	}

	/** Get the front element. */
	int peek() {
		return m_stack.top();
	}

	/** Returns whether the queue is empty. */
	bool empty() {
		return m_stack.empty();
	}

private:
	stack<int> m_stack;

};

int main()
{
	MyQueue que;
	que.push(1);
	que.push(3);
	que.push(4);
	assert(que.empty() == false);
	assert(que.peek() == 1);
	assert(que.pop() == 1);
	assert(que.peek() == 3);
	que.pop();
	assert(que.peek() == 4);
	return 0;
}
