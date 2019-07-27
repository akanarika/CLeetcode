class MyQueue {
private:
    stack<int> main;
    stack<int> other;

    void swap(stack<int> &a, stack<int> &b) {
       while (!a.empty()) {
           b.push(a.top());
           a.pop();
       }
    }

public:
    /** Initialize your data structure here. */
    MyQueue() {

    }
    
    /** Push element x to the back of queue. */
    void push(int x) {
        if (!other.empty() && main.empty()) {
            swap(other, main);
        }
        main.push(x); 
    }
    
    /** Removes the element from in front of queue and returns that element. */
    int pop() {
        if (!main.empty() && other.empty()) {
            swap(main, other);
        }
       int num = other.top();
       other.pop();
       return num;
    }
    
    /** Get the front element. */
    int peek() {
        if (!main.empty() && other.empty()) {
            swap(main, other);
        }
        return other.top();
    }
    
    /** Returns whether the queue is empty. */
    bool empty() {
        return main.empty() && other.empty();
    }
};

/**
 * Your MyQueue object will be instantiated and called as such:
 * MyQueue* obj = new MyQueue();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->peek();
 * bool param_4 = obj->empty();
 */
