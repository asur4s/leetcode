class CustomStack {
public:
    vector<int> stack;
    int top, max;

    CustomStack(int maxSize) {
        stack.resize(maxSize);
        top = -1;
        max = maxSize;
    }
    
    void push(int x) {
        if (top == max - 1) {
            return;
        }else{
            top++;
            stack[top] = x;
        }
    }
    
    int pop() {
        if (top == -1) {
            return -1;
        }
        top--;
        return stack[top + 1];
    }
    
    void increment(int k, int val) {
        int lim = min(k, top + 1);
        for (int i = 0; i < lim; ++i) {
            stack[i] += val;
        }
    }
};