// Implement Queue using Stacks

class Queue {
    stack<int> input, output;
public:
    // Push element x to the back of queue.
    void push(int x) {
        input.push(x);
    }

    // Removes the element from in front of queue.
    void pop(void) {
        peek();
        output.pop();
    }

    // Get the front element.
    int peek(void) {
        if(output.size()==0){
            while(!input.empty()){
                output.push(input.top());
                input.pop();
            }
        }
        return output.top();
    }

    // Return whether the queue is empty.
    bool empty(void) {
        return input.size()==0 && output.size()==0;
    }
};
