class MinStack {
private:
    stack<int> my_stack, min_stack;

public:
    MinStack() {
        min_stack.push(INT_MAX);
    }
    
    void push(int val) {
        my_stack.push(val);
        min_stack.push(min(val, min_stack.top()));
    }
    
    void pop() {
        my_stack.pop();
        min_stack.pop();
    }
    
    int top() {
        return my_stack.top();
    }
    
    int getMin() {
        return min_stack.top();
    }
};