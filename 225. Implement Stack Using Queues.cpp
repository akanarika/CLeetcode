class MyStack {
private:
    size_t size;
    queue<int> q;

public:
    /** Initialize your data structure here. */
    MyStack() {
        size = 0;
    }
    
    /** Push element x onto stack. */
    void push(int x) {
        q.push(x);
        size++;
    }
    
    /** Removes the element on top of the stack and returns that element. */
    int pop() {
        int num;
        for (size_t i = 0; i < size; i++) {
            num = q.front();
            if (i < (size - 1)) {
                q.push(num);
            } 
            q.pop();
        }
        size--;
        return num;
    }
    
    /** Get the top element. */
    int top() {
        int num;
        for (size_t i = 0; i < size; i++) {
            num = q.front();
            q.push(num);
            q.pop();
        }
        return num;
    }
    
    /** Returns whether the stack is empty. */
    bool empty() {
        return size == 0;
    }
};

/**
 * Your MyStack object will be instantiated and called as such:
 * MyStack* obj = new MyStack();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->top();
 * bool param_4 = obj->empty();
 */
