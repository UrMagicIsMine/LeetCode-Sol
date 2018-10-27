/* Implement the following operations of a stack using queues.
*
* push(x) -- Push element x onto stack.
* pop() -- Removes the element on top of the stack.
* top() -- Get the top element.
* empty() -- Return whether the stack is empty.
* Notes:
* You must use only standard operations of a queue -- which means only push to
* back, peek/pop from front, size, and is empty operations are valid.
* Depending on your language, queue may not be supported natively. You may
* simulate a queue by using a list or deque (double-ended queue), as long as you
* use only standard operations of a queue.
* You may assume that all operations are valid (for example, no pop or top
* operations will be called on an empty stack).
*/

#include <stack>
#include <vector>
#include <queue>
#include <cassert>
using namespace std;

class MyStack {
public:
	/** Initialize your data structure here. */
	MyStack() {

	}

	/** Push element x onto stack. */
	void push(int x) {
		_queueTmp.push(x);
		while (!_queue.empty()) {
			_queueTmp.push(_queue.front());
			_queue.pop();
		}
		swap(_queue, _queueTmp);
	}

	/** Removes the element on top of the stack and returns that element. */
	int pop() {
		int tmp = _queue.front();
		_queue.pop();
		return tmp;
	}

	/** Get the top element. */
	int top() {
		return _queue.front();
	}

	/** Returns whether the stack is empty. */
	bool empty() {
		return _queue.empty();
	}

	queue<int> _queue;
	queue<int> _queueTmp;
};

int main()
{
	MyStack obj;
	obj.push(1);
	obj.push(2);
	obj.push(3);
	int ret1 = obj.pop();
	assert(ret1 == 3);
	obj.pop();
	int ret2 = obj.top();
	assert(ret2 == 1);
	bool isEmpty = obj.empty();
	assert(isEmpty == false);
	return 0;
}
