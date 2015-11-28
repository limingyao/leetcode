// Implement Stack using Queues

class Stack {
private:
    queue<int> q;
public:
    // Push element x onto stack.
    void push(int x) {
        q.push(x);
        for(size_t i = 0; i < q.size() - 1; ++i) {
            q.push(q.front());
            q.pop();
        }
    }

    // Removes the element on top of the stack.
    void pop() {
        q.pop();
    }

    // Get the top element.
    int top() {
        return q.front();
    }

    // Return whether the stack is empty.
    bool empty() {
        return q.empty();
    }
};
