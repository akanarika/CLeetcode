class MinStack {
private:
    int m;
    stack<int> s;
public:
    /** initialize your data structure here. */
    MinStack() {
        m = INT_MAX; 
    }
    
    void push(int x) {
        s.push(x);
        m = min(m, x);
    }
    
    void pop() {
        if (s.top() == m) {
            s.pop();
            stack<int> tmp;
            int currentMin = INT_MAX;
            while (!s.empty()) {
                currentMin = min(currentMin, s.top());
                tmp.push(s.top());
                s.pop();
            }
            m = currentMin;
            while (!tmp.empty()) {
                s.push(tmp.top());
                tmp.pop();
            }
            return;
        }
        s.pop();
    }
    
    int top() {
        return s.top();    
    }
    
    int getMin() {
        return m; 
    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(x);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */
