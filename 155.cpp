// Min Stack

class MinStack {
public:
    void push(int x) {
        stack[p++] = x;
        if(min_p == 0 || min_stack[min_p-1] >= x) {
            min_stack[min_p++] = x;
        }
    }

    void pop() {
        int x = stack[p -1];
        int y = min_stack[min_p - 1];
        if(x == y) {
            --min_p;
        }
        --p;
    }

    int top() {
        return stack[p - 1];
    }

    int getMin() {
        return min_stack[min_p - 1];
    }

private:
    int SIZE = 100000;
    int* stack = new int[SIZE];
    int* min_stack = new int[SIZE];
    int p = 0;
    int min_p = 0;
};
